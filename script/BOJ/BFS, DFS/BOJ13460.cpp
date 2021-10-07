//Problem: [Complete] [구슬 탈출 2] https://www.acmicpc.net/problem/13460

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0,1}}; //LRBT
int map[10][10];

struct balls{
    int distance;
    int rx, ry, bx, by;
};

void move(int &x, int &y, int d){
    while(1){
        x += dir[d][0], y += dir[d][1];
        if(map[x][y]==1){
            x -= dir[d][0], y -= dir[d][1];
            break;
        } else if(map[x][y]==2) break;
    }
}

int main(){

    int visit[10][10][10][10];
    int irx, iry, ibx, iby, hx, hy;
    int ans = -1;
    int m, n;
    char s[11];

    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        scanf("%s", &s);
        for(int j = 0; j < n; j++){
            switch(s[j]){
                case '.': map[i][j] = 0; break;
                case '#': map[i][j] = 1; break;
                case 'O': map[i][j] = 2; hx = i, hy = j; break;
                case 'R': irx = i, iry = j; break;
                case 'B': ibx = i, iby = j; break;
            }
        }
    }

    queue<struct balls> q;
    q.push({0, irx, iry, ibx, iby});
    visit[irx][iry][ibx][iby] = 1;
    
    while(!q.empty()){
        struct balls cur = q.front(); q.pop();

        if(cur.distance > 10) break;
        if(cur.rx == hx & cur.ry == hy){
            ans = cur.distance;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int rx = cur.rx, ry = cur.ry, bx = cur.bx, by = cur.by;
            move(rx, ry, i);
            move(bx, by, i);

            if(bx == hx & by == hy) continue;
            if(bx == rx & by == ry){
                switch(i){
                    case 0:
                        cur.rx < cur.bx ? bx++ : rx++; break;
                    case 1:
                        cur.rx < cur.bx ? rx-- : bx--; break;
                    case 2:
                        cur.ry < cur.by ? by++ : ry++; break;
                    case 3:
                        cur.ry < cur.by ? ry-- : by--; break;
                }
            }

            if(visit[rx][ry][bx][by] == 0){
                q.push({cur.distance+1, rx, ry, bx, by});
                visit[rx][ry][bx][by] = 1;
            }
        }
    }

    printf("%d", ans);

    return 0;
}