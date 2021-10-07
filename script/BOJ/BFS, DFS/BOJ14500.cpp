//Problem: [테트로미노] https://www.acmicpc.net/problem/14500

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int map[500][500];
int visit[500][500];
int maxsum = 0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(pair<int, int> cur, int sum, int depth){

    if(depth == 4){
        if(sum > maxsum) maxsum = sum;
        return ;
    }
    
    pair<int, int> next;
    for(int d = 0; d < 4; d++){
        next.first = cur.first + dir[d][0];
        next.second = cur.second + dir[d][1];

        if(visit[next.first][next.first] || next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) continue;
        else{
            visit[next.first][next.second] = 1;
            DFS(next, sum + map[next.first][next.second], depth+1);
            visit[next.first][next.second] = 0;
        }
    }
}

void caseT(pair<int, int> cur){
    int tmp;
    int curx = cur.first, cury = cur.second;

    if(curx + 1 < n && cury + 2 < m){
        tmp = map[curx][cury] + map[curx][cury+1] + map[curx][cury+2] + map[curx+1][cury+1];
        if(tmp > maxsum) maxsum = tmp;
    }
    if(curx - 1 >= 0 && cury + 2 < m){
        tmp = map[curx][cury] + map[curx][cury+1] + map[curx][cury+2] + map[curx-1][cury+1];       
        if(tmp > maxsum) maxsum = tmp;
    }
    if(curx + 2 < n && cury + 1 < m){
        tmp = map[curx][cury] + map[curx+1][cury] + map[curx+2][cury] + map[curx+1][cury+1];
        if(tmp > maxsum) maxsum = tmp;
    }
    if(curx + 2 < n && cury - 1 >= 0){
        tmp = map[curx][cury] + map[curx+1][cury] + map[curx+2][cury] + map[curx+1][cury-1];
        if(tmp > maxsum) maxsum = tmp;
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int e;
            scanf("%d", &e);
            map[i][j] = e;
        }
    }

    fill(&visit[0][0], &visit[0][0]+500*500, 0);    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            pair<int, int> cur = make_pair(i, j);
//            printf("test1\n");
            visit[i][j] = 1;
            DFS(cur, map[i][j], 0);
            visit[i][j] = 0;
//            printf("test2\n");

            caseT(cur);
//            printf("test3\n");
        }
    }

    printf("%d", maxsum);
}