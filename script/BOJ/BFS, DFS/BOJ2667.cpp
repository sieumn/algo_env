// Problem: [단지번호붙이기] https://www.acmicpc.net/problem/2667
// Date: 2021.08.18
// Solver: Sieun Park

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int r, c;
};

int N;
int map[25+5][25+5];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<int> pop;

void BFS(int r, int c){
    vector<pair<int, int> > queue;
    queue.push_back(make_pair(r,c));
    map[r][c] = 0;

    int house = 0;
    while(!queue.empty()){
        pair<int, int> cur = queue.front();
        queue.erase(queue.begin());
        house++;

        for(int i=0; i<4; i++){
            int next_r = cur.first + dir[i][0];
            int next_c = cur.second + dir[i][1];

            if(next_r < 0 || next_c < 0 || next_r >= N || next_c >= N) continue;
            if(map[next_r][next_c]==0) continue;

            queue.push_back(make_pair(next_r, next_c));
            map[next_r][next_c] = 0;
        }
    }
    pop.push_back(house);
}

int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==1){
                BFS(i, j);
            }
        }
    }

    sort(pop.begin(), pop.end());

    printf("%d\n", pop.size());
    for(int i=0; i<pop.size(); i++){
        printf("%d\n", pop[i]);
    }

    return 0;
}