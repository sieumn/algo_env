// Problem: [DFS와 BFS] https://www.acmicpc.net/problem/1260
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, E;
vector<int> arr[1000+10];

vector<int> stack; // for DFS
int visit_DFS[1000+10]; //for DFS

vector<int> queue; // for BFS
int visit_BFS[1000+10]; //for BFS

void DFS(int depth){

    if(depth == N+1) return;

    int cur = stack.back();
    stack.pop_back();
    printf("%d ",cur);

    for(int i=0; i<arr[cur].size(); i++){
        int next = arr[cur][i];
        if(visit_DFS[next]==0){
            visit_DFS[next] = 1;
            stack.push_back(next);
            DFS(depth+1);
        }
    }
}

void BFS(){

    while(!queue.empty()){
        int cur = queue.front();
        queue.erase(queue.begin());
        printf("%d ",cur);

        for(int i=0; i<arr[cur].size(); i++){
            int next = arr[cur][i];
            if(visit_BFS[next]==0){
                visit_BFS[next] = 1;
                queue.push_back(next);
            }
        }
    }
}

int main(){

    int s, a, b;
    scanf("%d %d %d", &N, &E, &s);
    for(int i=0; i<E; i++){
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1; i<=N; i++) sort(arr[i].begin(), arr[i].end());

    stack.push_back(s);
    visit_DFS[s] = 1;
    DFS(0);

    printf("\n");

    queue.push_back(s);
    visit_BFS[s] = 1;
    BFS();

}