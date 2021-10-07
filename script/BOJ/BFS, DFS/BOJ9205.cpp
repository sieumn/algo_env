// Problem: [맥주 마시면서 걸어가기] https://www.acmicpc.net/problem/9205
// Date: 2021.08.25
// Solver: Sieun Park

#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int x, y;
};

int T, N;
int beercount = 20;
int ans;
int visit[100+10];
struct node home, fest;
vector<struct node> shop;

void init(){

    shop.clear();
    fill(&visit[0], &visit[0]+110, 0);
    ans = 0;
}

void get_input(){

    struct node tmp;
    scanf("%d", &N);
    scanf("%d %d", &home.x, &home.y);
    for(int j=0; j<N; j++){
        scanf("%d %d", &tmp.x, &tmp.y);
        shop.push_back(tmp);
    }
    scanf("%d %d", &fest.x, &fest.y);
    shop.push_back(fest);

}

int main(){

    scanf("%d", &T);
    for(int i=0; i<T; i++){
        
        init();
        get_input();

        queue<struct node> q;
        q.push(home);
        while(!q.empty()){

            struct node cur = q.front(); q.pop();
            if(cur.x == fest.x && cur.y == fest.y){
                ans = 1; break ;
            }
            for(int j=0; j<=N; j++){
                double distance = abs(cur.x - shop[j].x) + abs(cur.y - shop[j].y);
                if(distance <= beercount * 50 && visit[j]==0){
                    q.push(shop[j]);
                    visit[j] = 1;
                } 
            }
        }

        if(ans == 1) printf("happy\n");
        else printf("sad\n");

    }

    return 0;
}