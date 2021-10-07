//Problem: [민식우선탐색] https://www.acmicpc.net/problem/1376

// Solver: Sieun Park
// Solved Date: 2021.04.23

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100001
vector<int> vertices[MAX_SIZE];
int visit[MAX_SIZE];

void makeGraph(int v, int e){    

    int vs, vf;
    for(int i = 0; i < e; i++){
        scanf("%d %d", &vs, &vf);
        if(vs == vf) continue;
        vertices[vs].push_back(vf);
        vertices[vf].push_back(vs);
    }
    for(int i = 1; i < v + 1; i++){
        sort(vertices[i].begin(), vertices[i].end());
        vertices[i].erase(unique(vertices[i].begin(), vertices[i].end()), vertices[i].end());
    }
}

void mfs(int s){

    if(!visit[s]) printf("%d ", s);
    visit[s] = 1;

    vector<int> tmp;

    for(int i = 0; i < vertices[s].size(); i++){
        if(!visit[vertices[s][i]])
            tmp.push_back(vertices[s][i]);
    }

    if(tmp.size() == 0) return;
    else if(tmp.size() % 2 == 0){
        for(int i = 0; i < tmp.size(); i++){
            if(!visit[tmp[i]]){
                mfs(tmp[i]);
                mfs(s);
                return ;
            }
        }
    }
    else{
        int m;
        for(int i = 0; i < tmp.size(); i++){
            m = tmp.size() / 2 + i;
            if(m >= tmp.size()) m = m - tmp.size();
            if(!visit[tmp[m]]){
                mfs(tmp[m]);
                mfs(s);
                return;
            }
        }
    }
}

int main(){

    int v, e;
    scanf("%d %d", &v, &e);
    makeGraph(v, e);
    mfs(1);

    return 0;
}