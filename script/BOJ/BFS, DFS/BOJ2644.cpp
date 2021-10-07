// Problem: [촌수계산] https://www.acmicpc.net/problem/2644
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V, E;
int s, f;
vector<int> arr[100+10];
vector<pair<int, int> > queue;
int visit[100+10];
int ans = 987987987;

int main(){

    int a, b;
    scanf("%d %d %d %d", &V, &s, &f, &E);
    for(int i=1; i<=E; i++){
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    queue.push_back(make_pair(s, 0));
    visit[s] = 1;
    while(!queue.empty()){
        pair<int, int> cur = queue.front();
        queue.erase(queue.begin());

        if(cur.first == f){
            ans = cur.second; break;
        }

        for(int i=0; i<arr[cur.first].size(); i++){
            int next = arr[cur.first][i];

            if(visit[next]==1) continue;
            visit[next] = 1;
            queue.push_back(make_pair(next, cur.second+1));
        }
    }

    if(ans==987987987) printf("-1");
    else printf("%d", ans);

}