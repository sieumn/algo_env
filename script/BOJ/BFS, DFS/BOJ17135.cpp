//Problem: [캐슬 디펜스] https://www.acmicpc.net/problem/17135

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, d;
int ans;

struct node{
    int ci, cj;
};

bool cmp(struct node &lhs, struct node &rhs){
    if(lhs.cj < rhs.cj) return true;
    else if(lhs.cj == rhs.cj){
        if(lhs.ci > rhs.ci) return true;
    }
    return false;
}

int distance(struct node &a, struct node &b){
    return abs(a.ci - b.ci) + abs(a.cj - b.cj);
}

void playgame(vector<struct node>& enemy, vector<struct node>& my){

    if(enemy.empty()) return ;

    vector<struct node> cur;
    cur.resize(enemy.size());
    copy(enemy.begin(), enemy.end(), cur.begin());

    vector<int> kill;
    for(int i=0; i<my.size(); i++){
        int min_idx = 0;
        for(int j=1; j<cur.size(); j++){
            if(distance(my[i], cur[j]) < distance(my[i], cur[min_idx])) min_idx = j; 
        }
        if(distance(my[i], cur[min_idx]) <= d){
            kill.push_back(min_idx);
        }
    }
    sort(kill.begin(), kill.end());

    for(int i=0; i<kill.size(); i++){
        if(i>0 && kill[i]==kill[i-1]) continue;
        cur[kill[i]].ci = n-1;
        ans++;
    }

    vector<struct node> next;
    for(int i=0; i<cur.size(); i++){
        cur[i].ci++;
        if(cur[i].ci == n) continue;
        else next.push_back(cur[i]);
    }
    playgame(next, my);
}

int main(){

    int map[15][15];
    vector<struct node> enemy;
    vector<struct node> my;
    
    scanf("%d %d %d", &n, &m, &d);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int e;
            scanf("%d", &e);
            if(e==1){
                struct node tmp = {i, j};
                enemy.push_back(tmp);
            }
        }
    }
    sort(enemy.begin(), enemy.end(), cmp);

    int max = 0;
    for(int i=0; i<m-2; i++){
        struct node A = {n, i};
        for(int j=i+1; j<m-1; j++){
            struct node B = {n, j};
            for(int k=j+1; k<m; k++){
                struct node C = {n, k};
                my.clear();
                my.push_back(A);
                my.push_back(B);
                my.push_back(C);

                ans = 0;
                playgame(enemy, my);
                if(ans > max) max = ans;
            }
        }
    }

    printf("%d", max);
    return 0;

}