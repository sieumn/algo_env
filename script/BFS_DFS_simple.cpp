//Problem: [DFS와 BFS] https://www.acmicpc.net/problem/1260

// Solver: Sieun Park
// Solved Date: 2021.04.22

#include <iostream>
#include <algorithm>
#include <queue> 
#include <vector>
using namespace std;

vector<int> vertices[1001];
int visit[1001];

void makeGraph(int v, int e){    

    int vs, vf;
    for(int i = 0; i < e; i++){
        scanf("%d %d", &vs, &vf);
        vertices[vs].push_back(vf);
        vertices[vf].push_back(vs);
    }
    for(int i = 1; i < v + 1; i++) sort(vertices[i].begin(), vertices[i].end());
}

void searchBFS(int s){

    queue<int> queue;

    queue.push(s);
    while(!queue.empty()){
        int tmp = queue.front();
        printf("%d ", tmp);
        queue.pop();
        
        for(int i = 0; i < vertices[tmp].size(); i++){
            if(visit[vertices[tmp][i]]) continue;
            visit[vertices[tmp][i]] = 1;
            queue.push(vertices[tmp][i]);
        }
    }
}

void searchDFS(int s){

    printf("%d ", s);
    for(int i = 0; i < vertices[s].size(); i++){
        if(visit[vertices[s][i]]) continue;
        visit[vertices[s][i]] = 1;
        searchDFS(vertices[s][i]);
    }
}

int main(){

    int v, e, s;
    scanf("%d %d %d", &v, &e, &s);
    makeGraph(v, e);

    fill(visit, visit + v + 1, 0);
    visit[s] = 1;
    searchDFS(s);
    printf("\n");

    fill(visit, visit + v + 1, 0);
    visit[s] = 1;
    searchBFS(s);
    printf("\n");

    return 0;
}