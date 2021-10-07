//Problem: [로봇청소기] https://www.acmicpc.net/problem/14503

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

struct node{
    int i, j;
    int dir;
};

int main(){

    int n, m, e;
    int mi, mj, md;
    int map[50][50];
    int ans = 0;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &mi, &mj, &md);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &e);
            map[i][j] = e;
        }
    }

    queue<struct node> q;
    if(md == 3) md = 1;
    else if(md == 1) md = 3;
    struct node next = {mi, mj, md};
    q.push(next);

    while(!q.empty()){

        struct node cur = q.front(); q.pop();
        if(map[cur.i][cur.j]==0){
            map[cur.i][cur.j] = 2;
            //printf("(%d %d) %d \n", cur.i, cur.j, cur.dir);
            ans++;
        }

        int d = cur.dir;
        
        for(int i=0; i<4; i++){
            int k = i + d;
            if(k > 3) k -= 4;

            next = cur;
            next.i += dir[k][0]; next.j += dir[k][1];

            if(map[next.i][next.j] || next.i < 0 || next.i > n-1 || next.j < 0 || next.j > m-1){
                next.i -= dir[k][0]; next.j -= dir[k][1];
            }
            else if(map[next.i][next.j]==0){
                next.dir = k + 1;
                if(next.dir>3) next.dir-=4;
                q.push(next);
                break;
            }
            if(i == 3){
                d++;
                if(d>3) d-=4;
                next.i += dir[d][0]; next.j += dir[d][1];
                if(map[next.i][next.j] == 1 || next.i < 0 || next.i > n-1 || next.j < 0 || next.j > m-1){
                    next.i -= dir[d][0]; next.j -= dir[d][1];
                    break;
                }
                next.dir = cur.dir;
                q.push(next); break;
            }
        }
    }

    printf("%d", ans);
    return 0;
}