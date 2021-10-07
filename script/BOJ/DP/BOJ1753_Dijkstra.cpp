//Problem: [최단 경로] https://www.acmicpc.net/problem/1753

// Solver: Sieun Park
// Solved Date: 2021.04.29

#include<iostream>
#include<vector>
using namespace std;

#define INF 99999999

struct vertex{
    int nodeIdx;
    int cost;
    vector<struct edge> el;
};

struct edge{
    int destIdx;
    int weight;
};

vector<struct vertex> graph;

void makegraph(int v, int e){
    
    for(int i=0; i<v+1; i++){
        struct vertex tmpv;
        tmpv.nodeIdx = i;
        tmpv.cost = INF;
        graph.push_back(tmpv);
    }

    int vs, vf, w;
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &vs, &vf, &w);
        struct edge tmpe;
        tmpe.destIdx = vf;
        tmpe.weight = w;
        graph[vs].el.push_back(tmpe);
    }
}

void DIKJSTRA(int s){
    
    vector<int> queue;

    graph[s].cost = 0;
    for(int i=1; i<graph.size(); i++){
        queue.push_back(graph[i].nodeIdx);
    }

    while(queue.size()){
        int qmin = 0;
        for(int i=0; i<queue.size(); i++){
            if(graph[queue[i]].cost < graph[queue[qmin]].cost) qmin = i;
        }
        int minIdx = queue[qmin];
        queue.erase(queue.begin()+qmin);

        for(int i=0; i<graph[minIdx].el.size(); i++){
            if(graph[graph[minIdx].el[i].destIdx].cost > graph[minIdx].cost + graph[minIdx].el[i].weight ){
                graph[graph[minIdx].el[i].destIdx].cost = graph[minIdx].cost + graph[minIdx].el[i].weight;
            }
        }
    }
}

int main(){

    int v, e, s;
    scanf("%d %d %d", &v, &e, &s);

    makegraph(v, e);
    DIKJSTRA(s);

    for(int i=1; i<v+1; i++){
        if(graph[i].cost == INF) printf("INF \n");
        else printf("%d \n", graph[i].cost);
    }

    return 0;
}