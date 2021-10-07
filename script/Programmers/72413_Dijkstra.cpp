//Problem: [합승택시요금] https://programmers.co.kr/learn/courses/30/lessons/72413

// Solver: Sieun Park
// Solved Date: 2021.04.30

#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 9999999

struct edge_t{
    int dest;
    int weight;
};

bool operator<(const edge_t &left, const edge_t &right){
    return left.weight > right.weight;
}

void Dijkstra(int n, vector<edge_t>* graph, vector<int> &distance, int s){
    
    priority_queue<edge_t> pq;

    edge_t tmp = {s, 0};
    distance[s]=0;
    pq.push(tmp);
    
    while(!pq.empty()){
        int cur = pq.top().dest;
        int d = pq.top().weight;
        pq.pop();
        
        if(d > distance[cur]) continue;
        
        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i].dest;
            int nextDistance = graph[cur][i].weight + d;
            
            if(distance[next] > nextDistance){
                distance[next] = nextDistance;
                edge_t nexte = {next, nextDistance};
                pq.push(nexte);                
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    vector<edge_t> graph[n+1];
    
    for(int i=0; i<fares.size(); i++){
        edge_t newEdge1 = {fares[i][1], fares[i][2]};
        graph[fares[i][0]].push_back(newEdge1);
        
        edge_t newEdge2 = {fares[i][0], fares[i][2]};
        graph[fares[i][1]].push_back(newEdge2);
    }
    
    vector<int> distance_s;
    distance_s.resize(n+1, INF);
    Dijkstra(n, graph, distance_s, s);
    
    int min = distance_s[a] + distance_s[b];
    for(int i=1; i<n+1; i++){
        if(i==s || distance_s[i] > min) continue;
        
        vector<int> distance_tmp;
        distance_tmp.resize(n+1, INF);
        Dijkstra(n, graph, distance_tmp, i);

        int temp = distance_s[i] + distance_tmp[a] + distance_tmp[b];
        if(temp < min) min = temp;
    }

    return min;
}