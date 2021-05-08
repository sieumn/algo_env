#include <string>
#include <vector>
#include <map>

using namespace std;

#define INF 999999

struct word{
    int visit;
    int distance;
    vector<int> wl;
};

bool wordcheck(string cur, string next){
    int count = 0;
    for(int i=0; i<cur.size(); i++){
        if(cur[i] == next[i]) count++;
    }
    if(count == cur.size()-1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);

    vector<struct word> list;
    map<string, int> map;        
    list.resize(words.size());

    //make graph, initialization
    for(int i=0; i<words.size(); i++){
        map.insert(make_pair(words[i], i));
        list[i].visit = 0;
        list[i].distance = INF;
        
        if(i==words.size()-1) break;
        for(int j=i+1; j<words.size(); j++){
            if(wordcheck(words[i], words[j])){
                list[i].wl.push_back(j);
                list[j].wl.push_back(i);
            }
        }
    }
    if(map.count(target)==0) return 0;
    
    vector<int> q;
    int cur = map.find(begin)->second;
    q.push_back(cur);
    list[cur].distance = 0;
    list[cur].visit = 1;

    while(!q.empty()){
        cur = q.front();
        
        for(int i=0; i<list[cur].wl.size(); i++){
            int next = list[cur].wl[i];
            int nextDistance = list[cur].distance + 1;

            if(list[next].visit==0){
                q.push_back(next);
                list[next].distance = nextDistance;
                list[next].visit = 1;
            }
            else if(list[next].distance > nextDistance){
                list[next].distance = nextDistance;
            }            
        }        
        q.erase(q.begin());
    }
    
    int des = list[map.find(target)->second].distance;
    if(des == 999999) return 0;
    else return des;
}