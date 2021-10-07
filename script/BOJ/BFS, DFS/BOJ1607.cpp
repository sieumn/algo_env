// Problem: [숨바꼭질] https://www.acmicpc.net/problem/1607
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int cntmin = 987987987;
int visit[100000+10];
queue<int> q;

void BFS(){

    fill(&visit[0], &visit[0]+100010, 987987987);
    visit[n] = 0;
    q.push(n);    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur==m){
            cntmin = visit[cur];
            return ;
        }

        if(cur+1 <= 100000 && visit[cur+1] > visit[cur]+1){
            visit[cur+1] = visit[cur]+1;
            q.push(cur+1);
        }

        if(cur*2 <= 100000 && visit[cur*2] > visit[cur]+1){
            visit[cur*2] = visit[cur]+1;
            q.push(cur*2);
        }

        if(cur-1 >= 0 && visit[cur-1] > visit[cur]+1){
            visit[cur-1] = visit[cur]+1;
            q.push(cur-1);
        }

    }

}

int main(){

    scanf("%d %d", &n, &m);

    BFS();
    printf("%d", visit[m]);
}