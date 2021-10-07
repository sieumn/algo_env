//Problem: [DFS와 BFS] https://www.acmicpc.net/problem/1260

// Solver: Sieun Park
// Solved Date: 2021.04.20

#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

enum { WHITE, GRAY, BLACK };

struct vertex{
    int nodeID;
    int nodeColor;
    struct edgeList *el;

    //BFS  
    int distance;
    int prenode;

    //DFS
    int time_d;
    int time_f;
};

struct edge{
    int dest_node;
    struct edge *nextEdge;
};

struct edgeList{
    struct edge *head;
    struct edge *tail;
};

void makeGraph(vertex vertices[], int v, int e);
void initializeGraph(vertex vertices[], int v);
void initializeColor(vertex vertices[], int v);
void addEdge(vertex *vertex, edge *newEdge);
void printGraph(vertex vertices[], int v);
void searchDFS(vertex vertices[], int v, int e, int s);
void searchBFS(vertex vertices[], int v, int e, int s);

void initializeGraph(vertex vertices[], int v){
    for(int i = 0; i < v; i++){
        
        vertices[i].nodeID = i + 1;
        vertices[i].nodeColor = WHITE;

        vertices[i].distance = 9999;
        vertices[i].prenode = 0;

        vertices[i].time_d = 0;
        vertices[i].time_f = 0;

        vertices[i].el = new edgeList();
        vertices[i].el->head = NULL;
        vertices[i].el->tail = NULL;
    }
}

void initializeColor(vertex vertices[], int v){
    for(int i = 0; i < v; i++){
        vertices[i].nodeColor = WHITE;
    }
}

void makeGraph(vertex vertices[], int v, int e){    

    initializeGraph(vertices, v);
    for(int i = 0; i < e; i++){

        int vs, vf;
        scanf("%d %d", &vs, &vf);

        //one way
        struct edge *newEdge = new edge();
        newEdge->dest_node = vf;
        newEdge->nextEdge = NULL;
        addEdge(&vertices[vs-1], newEdge);
        //the other way
        struct edge *newEdge2 = new edge();
        newEdge2->dest_node = vs;
        newEdge2->nextEdge = NULL;
        addEdge(&vertices[vf-1], newEdge2);
    }
}

void addEdge(vertex *vertex, edge *newEdge){

    if(vertex->el->head == NULL){
        vertex->el->head = newEdge;
        vertex->el->tail = newEdge;      
    }
    else{
        struct edge *tmpEdge = vertex->el->head;
        if(tmpEdge->dest_node > newEdge->dest_node){
            newEdge->nextEdge = tmpEdge;
            vertex->el->head = newEdge;
            return;
        }
        while(tmpEdge->nextEdge){
            if(tmpEdge->nextEdge->dest_node > newEdge->dest_node){
                newEdge->nextEdge = tmpEdge->nextEdge;
                tmpEdge->nextEdge = newEdge;
                return;
            }
            tmpEdge = tmpEdge->nextEdge;
        }
        tmpEdge->nextEdge = newEdge;
        vertex->el->tail = newEdge;
    }
}

void searchBFS(vertex vertices[], int v, int e, int s){

    initializeColor(vertices, v);

    queue<int> queue;
    vector<int> search_result;

    queue.push(s);
    vertices[s-1].nodeColor = GRAY;
    vertices[s-1].distance = 0;
    
    while(!queue.empty()){

        int v = queue.front();
        queue.pop();
        search_result.push_back(v);
        
        struct edge *tmpNode = vertices[v-1].el->head;
        int u;
        while(tmpNode){
            u = tmpNode->dest_node;
            if(vertices[u-1].nodeColor == WHITE){
                vertices[u-1].nodeColor = GRAY;
                vertices[u-1].distance = vertices[v-1].distance + 1;
                vertices[u-1].prenode = v;
                queue.push(u);
            }
            tmpNode = tmpNode->nextEdge;
        }
        vertices[v-1].nodeColor = BLACK;
    }

//    printf("BFS result: ");
    for(int i = 0; i < search_result.size(); i++){
        printf("%d ", search_result[i]);
    }
    printf("\n");
}

void searchDFS(vertex vertices[], int v, int e, int s){

    initializeColor(vertices, v);

    vector<int> search_result;
    vector<int> stack;
    vector<int> tmpstack;
    int timestamp = 0;

    vertices[s-1].nodeColor = GRAY;
    vertices[s-1].time_d = ++timestamp;
    stack.push_back(s);

    while(!stack.empty()){
        int v = stack.back();
        stack.pop_back();
        if(vertices[v-1].nodeColor == BLACK) continue;
        search_result.push_back(v);

        struct edge *tmpEdge = vertices[v-1].el->head;
        int u;
        while(tmpEdge){
            u = tmpEdge->dest_node;
            if(vertices[u-1].nodeColor != BLACK) tmpstack.push_back(u);
            if(vertices[u-1].nodeColor == WHITE){
                vertices[u-1].nodeColor = GRAY;
                vertices[u-1].time_d = ++timestamp;
            }
            tmpEdge = tmpEdge->nextEdge;
        }
        sort(tmpstack.begin(), tmpstack.end(), greater<int>());
        stack.insert(stack.end(), tmpstack.begin(), tmpstack.end());
        while(!tmpstack.empty()) tmpstack.pop_back();

        vertices[v-1].nodeColor = BLACK;
        vertices[v-1].time_f = ++timestamp;
    }

//    printf("DFS result: ");
    for(int i = 0; i < search_result.size(); i++){
        printf("%d ", search_result[i]);
    }
    printf("\n");
}

void printGraph(vertex vertices[], int v){
    for(int i = 0; i < v; i++){
        printf("vertex %d:", vertices[i].nodeID);

        struct edge *tmpNode = vertices[i].el->head;
        while(tmpNode){
            printf("%d ", tmpNode->dest_node);
            tmpNode = tmpNode->nextEdge;
        }
        printf("\n");
    }
}

int main(){

    int v, e, s;
    scanf("%d %d %d", &v, &e, &s);
    struct vertex vertices[v];

    makeGraph(vertices, v, e);

//    printGraph(vertices, v);

    searchDFS(vertices, v, e, s);
    searchBFS(vertices, v, e, s);

    return 0;
}