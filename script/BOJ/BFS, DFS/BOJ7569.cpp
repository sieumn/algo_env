// Problem: [토마토] https://www.acmicpc.net/problem/7569
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
    int r, c, h;
    int days;
};

int N, M, H;
int empty_count, ripe_count, ans;
int box[100+10][100+10][100+10];
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<struct node> q;

void BFS(){

    while(!q.empty()){
        struct node cur = q.front();
        q.pop();
        if(cur.days > ans) ans = cur.days;

        for(int i=0; i<6; i++){
            struct node next = {cur.r + dir[i][0], cur.c + dir[i][1], cur.h + dir[i][2], cur.days + 1};
            if(next.r < 0 || next.c < 0 || next.h < 0 || next.r >= M || next.c >= N || next.h >= H) continue;
            if(box[next.r][next.c][next.h]==0){
                box[next.r][next.c][next.h] = 1;
                q.push(next);
                ripe_count++;
            }
        }
    }
}

int main(){

    scanf("%d %d %d", &N, &M, &H);
    for(int i=0; i<H; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<N; k++){
                scanf("%d", &box[j][k][i]);
                if(box[j][k][i]==1){
                    struct node tmp = {j, k, i, 0};
                    q.push(tmp);
                }
                if(box[j][k][i]==-1) empty_count++;
                else if(box[j][k][i]==1) ripe_count++;
            }
        }
    }

    if(ripe_count + empty_count == N*M*H) printf("0");
    else{
        BFS();
        if(ripe_count + empty_count == N*M*H) printf("%d", ans);
        else printf("-1");
    }
    return 0;

}