// Problem: [스타트링크] https://www.acmicpc.net/problem/5014
// Date: 2021.08.22
// Solver: Sieun Park

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int F, S, G, U, D;
queue<int> q;

int BFS(){

    int visit[1000000+10];
    fill(&visit[0], &visit[0]+1000010, 987987987);
    q.push(S);
    visit[S] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == G) break;

        if(cur+U <= F && visit[cur+U] > visit[cur]+1){
            visit[cur+U] = visit[cur]+1;
            q.push(cur+U);
        }
        if(cur-D >= 1 && visit[cur-D] > visit[cur]+1){
            visit[cur-D] = visit[cur]+1;
            q.push(cur-D);
        }
    }

    return visit[G];
}

int main(){

    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    int ans = BFS();

    if(ans==987987987) printf("use the stairs");
    else printf("%d", ans);

    return 0;
}