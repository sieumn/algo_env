// Problem: [빙산] https://www.acmicpc.net/problem/2573
// Date: 2021.08.25
// Solver: Sieun Park

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int icecount;
int map[300+10][300+10];
vector<pair<int, int> > ice;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void meltIce(){

    int tmp[300+10][300+10];
    copy(&map[0][0], &map[0][0]+310*310, &tmp[0][0]);

    for(int i=0; i<ice.size(); i++){
        pair<int, int> cur = ice[i];

        for(int j=0; j<4; j++){
            pair<int, int> next;
            next.first = cur.first + dir[j][0];
            next.second = cur.second + dir[j][1];

            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
            if(map[next.first][next.second]==0 && tmp[cur.first][cur.second] > 0){
                tmp[cur.first][cur.second]--;
                if(tmp[cur.first][cur.second]==0){
                    icecount--;
                    ice.erase(ice.begin()+i);
                    i--;
                }
            }
        }
    }

    copy(&tmp[0][0], &tmp[0][0]+310*310, &map[0][0]);
}

bool checkConnected(){
    
    int visit[300+10][300+10] = {0, };
    int curicecount = 1;

    queue<pair<int, int> > q;
    q.push(ice[0]);
    visit[ice[0].first][ice[0].second] = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            pair<int, int> next;
            next.first = cur.first + dir[i][0];
            next.second = cur.second + dir[i][1];

            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
            if(visit[next.first][next.second]==0 && map[next.first][next.second]>0){
                visit[next.first][next.second] = 1;
                curicecount++;
                q.push(next);
            }
        }       
    }

    if(curicecount == icecount) return true;
    else return false;
}

int main(){

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]>0){
                icecount++;
                ice.push_back(make_pair(i, j));
            }
        }
    }

    int ans = 1;
    while(1){

        meltIce();
        if(icecount == 0){
            printf("0"); return 0;
        }

        bool chk = checkConnected();
        if(chk==false){
            printf("%d", ans); return 0;
        }
        ans++;

    }

    return 0;
}