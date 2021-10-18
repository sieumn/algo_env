#ifndef NULL
#define NULL 0
#endif

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_SIZE 1005

const int SIZE = (1 << 16);
const int MOD = SIZE - 1;

int N, M;
int AP[MAX_SIZE][MAX_SIZE];
int BP[20][20];

struct node {
    int pos_r, pos_c;
    node* next;
    node* alloc(int _pos_r, int _pos_c, node* _next){
        pos_r = _pos_r, pos_c = _pos_c, next = _next;
        return this;
    }
} *Hash[MOD], buf[MAX_SIZE*MAX_SIZE];

int hashkey(int r, int c){
    int key = 0;
    for(int i = 0; i < 4; i++){
        key = (key << 4) + (AP[r + i][c + 3] & 15);
    }
    return key;
}

void init(int n, int ap[][1000], int m){
    N = n, M = m;
    int cnt = 0, key;
    for(int i = 0; i < MOD; i ++){
        Hash[i] = 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0, k = 0; j < N; j++){
            AP[i][j] = (k << 1) + ap[i][j];
            k = AP[i][j];
        }
    }
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            key = hashkey(i, j);
            Hash[key] = buf[cnt++].alloc(i, j, Hash[key]);
        }
    }
}

int comp(int r, int c) {
    for(int i = 0; i < M; i++){
        if((AP[r + i][c + M - 1] & ((1 << M) - 1)) != BP[i][M - 1]){
            return 0;
        }
    }
    return 1;
}

int query(int bp[][20]){
    int row = 0, col = 0;
    int key = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0, k = 0; j < M; j++){
            BP[i][j] = (k << 1) + bp[i][j];
            k = BP[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        key = (key << 4) + BP[i][3];
    }

    for(node* p = Hash[key]; p; p = p->next){
        if(comp(p->pos_r, p->pos_c)) {
            row = p->pos_r;
            col = p->pos_c;
            return row * N + col;
        }
    }

    return 0;
}