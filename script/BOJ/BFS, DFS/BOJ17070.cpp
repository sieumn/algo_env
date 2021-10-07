//Problem: [Complete] [파이프 옮기기 1] https://www.acmicpc.net/problem/17070

#include<iostream>
using namespace std;

int num;
int ans;
int map[17][17];

void DFS(int ci, int cj, int dir){
    if(dir == 0){
        if(ci == num && cj+1 == num){ ans++; return; }
        if(cj+2 <= num && !map[ci][cj+2]) DFS(ci, cj+1, 0);
        if(ci+1 <= num && cj+2 <=num && !map[ci][cj+2] && !map[ci+1][cj+1] && !map[ci+1][cj+2]) DFS(ci, cj+1, 2);
    }
    else if(dir == 1){
        if(ci+1 == num && cj == num){ ans++; return; }
        if(ci+2 <= num && !map[ci+2][cj]) DFS(ci+1, cj, 1);
        if(ci+2 <= num && cj+1 <= num && !map[ci+2][cj] && !map[ci+1][cj+1] && !map[ci+2][cj+1]) DFS(ci+1, cj, 2);
    }
    else{
        if(ci+1 == num && cj+1 == num){ ans++; return; }
        if(cj+2 <= num && !map[ci+1][cj+2]) DFS(ci+1, cj+1, 0);
        if(ci+2 <= num && !map[ci+2][cj+1]) DFS(ci+1, cj+1, 1);
        if(cj+2 <= num && cj+2 <= num && !map[ci+1][cj+2] && !map[ci+2][cj+1] && !map[ci+2][cj+2]) DFS(ci+1, cj+1, 2);
    }
}

int main(){

    ans = 0;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            int e;
            scanf("%d", &e);
            map[i+1][j+1] = e;
        }
    }

    DFS(1, 1, 0);

    printf("%d", ans);
    return 0;
}