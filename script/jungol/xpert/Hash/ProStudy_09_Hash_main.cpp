/**************************************************************
    Problem: 3123
    User: sieunss.park
    Language: C++
    Result: Success
    Time:183 ms
    Memory:26500 kb
    Date: 2021.10.09
****************************************************************/

#include<iostream>
using namespace std;

#define MAX_SIZE 1000

const int SIZE = (1 << 12);
const int MOD = SIZE - 1;

int N, K, M, bn;
int A[MAX_SIZE+10], B[MAX_SIZE+10], sum[MAX_SIZE+10];

struct node{
    int pos, same_cnt;
    node* next;
    node* alloc(int _pos, node* _next){
        pos = _pos, next = _next, same_cnt = 1;
        return this;
    }
} *Hash[SIZE], buf[1000];

int checkval(int oidx, int didx){

    // 순방향
    int i, j;
    for (i = oidx, j = didx; i > oidx - K; i--, j--) {
        if(A[i] != B[j]) break;
    }
    if(i <= oidx - K) return 1;

    // 역방향
    for (i = oidx, j = didx - K + 1; i > oidx - K; i--, j++) {
        if(A[i] != B[j]) return 0;
    }
    return 1;    
}

int match_chk(int t){
    int match = 0;
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &B[i]);
        sum[i] = (sum[i - 1] + B[i] * B[i]) & MOD;

        if (i >= K) {
            int key = (sum[i] - sum[i - K] + MOD) & MOD; // MOD 더해준 거는 음수 방지
            for (node *p = Hash[key]; p != NULL; p = p->next) {
                if(p->same_cnt == t && checkval(p->pos, i)) {
                    p->same_cnt = t + 1;
                    match = 1;
                }
            }
        }
    }
    return match;
}

int main(){
    scanf("%d %d", &N, &K);
    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &A[i]);
        sum[i] = (sum[i - 1] + A[i] * A[i]) & MOD;

        if (i >= K) {
            int key = (sum[i] - sum[i - K] + MOD) & MOD; // MOD 더해준 거는 음수 방지
            Hash[key] = buf[bn++].alloc(i, Hash[key]);
        }
    }
    for (int tc = 1; tc < N; tc++) {
        if(match_chk(tc) == 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}