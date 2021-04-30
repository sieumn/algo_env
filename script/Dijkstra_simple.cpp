//Problem: [최단 경로] https://www.acmicpc.net/problem/1753

// Solver: Sieun Park
// Solved Date: 2021.04.30

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 99999999

struct edge{
    int destIdx;
    int weight;
};

bool operator<(const edge left, const edge right){
    return left.weight > right.weight;
}

void makegraph(vector<edge>* graph, int e){
    int vs, vf, w;
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &vs, &vf, &w);
        edge newe = {vf, w};
        graph[vs].push_back(newe);
    }
}

void DIKJSTRA(vector<edge>* graph, vector<int> &distance, int s){

    priority_queue<edge> pq;
    edge tmpe = {s, 0};
    pq.push(tmpe);
    distance[s]=0;

    while(!pq.empty()){
        int tmpv = pq.top().destIdx;
        int tmpw = pq.top().weight;
        pq.pop();

        if(tmpw > distance[tmpv]) continue;

        for(int i=0; i<graph[tmpv].size(); i++){
            int next  = graph[tmpv][i].destIdx;
            int nextDistance = graph[tmpv][i].weight + tmpw;
            if(nextDistance < distance[next]){
                distance[next] = nextDistance;
                edge tmpe2 = {next, nextDistance};
                pq.push(tmpe2);
            }
        }
    }
}

int main(){

//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int v, e, s;
    scanf("%d %d %d", &v, &e, &s);

    vector<edge> graph[v+1];
    vector<int> distance;
    distance.resize(v+1, INF);

    makegraph(graph, e);
    DIKJSTRA(graph, distance, s);

    for(int i=1; i<distance.size(); i++){
        if(distance[i] == INF) printf("INF \n");
        else printf("%d \n", distance[i]);
    }

    return 0;
}