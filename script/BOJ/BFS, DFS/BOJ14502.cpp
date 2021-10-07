//Problem: [Complete] [연구소] https://www.acmicpc.net/problem/14502

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, e;
int map[8][8];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

struct node{
    int i,j;
};

int main(){
    int n, m, e;
    int walls = 0;
    int map[8][8];
    vector<struct node> zeros;
    vector<struct node> virus;

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &e);
            map[i][j] = e;

            struct node newnode = {i, j};
            if(e == 0) zeros.push_back(newnode);
            else if(e == 1) walls++;
            else if(e == 2) virus.push_back(newnode);
        }
    }

    walls+=3;
    int max = 0;
    for(int i=0; i<zeros.size()-2; i++){
        for(int j=i+1; j<zeros.size()-1; j++){
            for(int k=j+1; k<zeros.size(); k++){
                int cmap[8][8];
                copy(&map[0][0], &map[0][0]+64, &cmap[0][0]);

                vector<node> cvirus;
                cvirus.resize(virus.size());
                copy(virus.begin(), virus.end(), cvirus.begin());

                cmap[zeros[i].i][zeros[i].j] = 1;
                cmap[zeros[j].i][zeros[j].j] = 1;
                cmap[zeros[k].i][zeros[k].j] = 1;

                for(int l=0; l < virus.size(); l++){

                    queue<struct node> q;
                    q.push(virus[l]);

                    while(!q.empty()){
                        struct node cur = q.front(); q.pop();
                        for(int d=0; d<4; d++){
                            struct node next = cur;
                            next.i += dir[d][0]; next.j += dir[d][1];
                        
                            if(next.i > n-1 || next.i < 0 || next.j > m-1 || next.j < 0){
                                next.i -= dir[d][0]; next.j -= dir[d][1];
                                continue;
                            }
                            if(cmap[next.i][next.j]){
                                next.i -= dir[d][0]; next.j -= dir[d][1];
                                continue;
                            }
                            else{
                                cmap[next.i][next.j] = 2;
                                cvirus.push_back(next);
                                q.push(next);
                            }
                        }
                    }
                }
                int tmp = n * m - walls - cvirus.size();
                if(tmp > max) max = tmp;
            }
        }
    }

    printf("%d", max);
    return 0;

}