// Problem: [안전 영역] https://www.acmicpc.net/problem/2468
// Date: 2021.08.22
// Solver: Sieun Park

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int map[100+10][100+10];
int visit[100+10][100+10];
int exist[100+10];
int ans = 1, cnt = 0;
int maxheight;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void BFS(int r, int c, int s){
    queue<pair<int, int> > q;
    q.push(make_pair(r,c));
    visit[r][c] = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int next_r = cur.first + dir[i][0];
            int next_c = cur.second + dir[i][1];

            if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
            if(visit[next_r][next_c] == 0 && map[next_r][next_c] > s){
                visit[next_r][next_c] = 1;
                q.push(make_pair(next_r, next_c));
            }
        }
    }
}

void findvillage(int s){
    
    fill(&visit[0][0], &visit[0][0]+110*110, 0);
    cnt = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] > s && visit[i][j]==0){
                BFS(i, j, s);
                cnt++;
            }
        }
    }

    if(cnt > ans) ans = cnt;
}

int main(){

    int e;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &e);
            exist[e] = 1;
            map[i][j] = e;
            if(e > maxheight) maxheight = e;
        }
    }

    for(int i=1; i<maxheight; i++){
        if(exist[i]==1) findvillage(i);
    }
    printf("%d", ans);
}