//Problem: [색종이 붙이기] https://www.acmicpc.net/problem/17136
//Solver: Sieun Park
//Solved Date: 2021.05.19

#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 10

using namespace std;

int map[SIZE][SIZE];
int visit[SIZE][SIZE];
int puzzle_count[5];
int one_count = 0;
int ans_min = 26;
vector<pair<int, int> > q;

bool checkpuzzle(pair<int, int> cur, int n){

    if(cur.first + n > SIZE || cur.second + n > SIZE ) return false;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[cur.first + i][cur.second + j] == 0 || visit[cur.first + i][cur.second + j] == 1) return false;
        }
    }
    return true;
}

void addpuzzle(pair<int, int> cur, int n, int k){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visit[cur.first + i][cur.second + j] = k;
        }
    }
    if(k==1) one_count -= n*n;
    else one_count += n*n;
}

void playpuzzle(int idx, int ans){

    bool chk = false;
    if(ans > ans_min) return;
    if(one_count == 0){
        if(ans < ans_min) ans_min = ans;
        printf("ans: %d\n", ans_min);
        return ;
    }

    for(int j=idx; j<q.size(); j++){
        if(ans > ans_min) return;

        pair<int, int> cur = q[j];
        if(visit[cur.first][cur.second] == 1) continue;

        for(int n = 5; n > 0; n--){
            if(puzzle_count[n] == 5) continue;
            else if(!checkpuzzle(cur, n)) continue;
            else{

                addpuzzle(cur, n, 1);
                puzzle_count[n]++;
                ans++;

                playpuzzle(j+1, ans);

                addpuzzle(cur, n, 0);
                puzzle_count[n]--;
                ans--;
            }
        }
    }
}

int main(){

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            int e;
            scanf("%d", &e);
            map[i][j] = e;
            if(e==1) q.push_back(make_pair(i, j));
        }
    }
    
    one_count = q.size();
    if(q.size()){

        fill(&visit[0][0], &visit[0][0]+SIZE*SIZE, 0);
        fill(&puzzle_count[0], &puzzle_count[0]+5, 0);

        playpuzzle(0, 0);
        if(ans_min == 26) ans_min = -1;

    } else ans_min = 0;

    printf("%d", ans_min);
    return 0;
}