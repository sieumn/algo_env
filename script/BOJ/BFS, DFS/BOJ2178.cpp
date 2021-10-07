// Problem: [미로 탐색] https://www.acmicpc.net/problem/2178
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int r, c;
    int distance;
};

int N, M;
int mindis = 1000000;
int map[100+10][100+10];
int visit[100+10][100+10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<struct node> queue;

int main(){

    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    struct node cur = {1, 1, 1};
    visit[1][1] = 1;
    queue.push_back(cur);

    while(!queue.empty()){
        cur = queue.front();
        queue.erase(queue.begin());

        if(cur.r == N && cur.c == M){
            printf("%d", cur.distance);
            break;
        }

        struct node next;
        for(int i=0; i<4; i++){

            next.r = cur.r + dir[i][0];
            next.c = cur.c + dir[i][1];
            next.distance = cur.distance + 1;

            if(next.r <= 0 || next.r > N || next.c <= 0 || next.c > M) continue;
            if(visit[next.r][next.c]==1 || map[next.r][next.c]==0) continue;

            queue.push_back(next);
            visit[next.r][next.c] = 1;
        }
    }
    return 0;
}