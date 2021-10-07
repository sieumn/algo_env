// Problem: [바이러스] https://www.acmicpc.net/problem/2606
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V, E;
vector<int> link[100+10];
vector<int> queue;
int visit[100+10];
int ans;

int main(){

    int a, b;
    scanf("%d %d", &V, &E);
    for(int i=1; i<=E; i++){
        scanf("%d %d", &a, &b);
        link[a].push_back(b);
        link[b].push_back(a);
    }

    queue.push_back(1);
    visit[1] = 1;

    while(!queue.empty()){
        int cur = queue.front();
        queue.erase(queue.begin());
        ans++;

        for(int i=0; i<link[cur].size(); i++){
            int next = link[cur][i];
            if(visit[next]==0){
                visit[next]=1;
                queue.push_back(next);
            }
        }
    }

    printf("%d", ans-1);
    return 0;

}