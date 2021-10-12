/**************************************************************
    Problem: 2918 (구간성분)
    User: sieunss.park
    Language: C++
    Result: Success
    Time:376 ms
    Memory:2156 kb
    Date: 2021.10.12
****************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

const int SIZE = (1 << 12);
const int MOD = SIZE - 1;

char A[1510], B[1510];
int alen, blen, a_sum[1510], b_sum[1510];

struct node {
    int pos;
    node* next;
    node* alloc(int _pos, node* _next) {
        pos = _pos, next = _next;
        return this;
    }
} *Hash[MOD], buffer[1500];

int checkval(int pos_a, int pos_b, int n) {
    int check[26] = {0, };
    for(int i = pos_a - n + 1; i <= pos_a; i++)
        check[A[i] - 'a']++;
    for(int i = pos_b - n + 1; i <= pos_b; i++) {
        check[B[i] - 'a']--;
        if(check[B[i] - 'a'] < 0) return 0;
    }
    return 1;
}

int check(int n) {
    int i, key, bcnt;
    for(i = 0; i < MOD; i++) Hash[i] = 0;
    for(i = n; i <= alen; i++) {
        key = (a_sum[i] - a_sum[i - n] + MOD) % MOD;
        Hash[key] = buffer[bcnt++].alloc(i, Hash[key]);
    }
    for(i = n; i <= blen; i++) {
        key = (b_sum[i] - b_sum[i - n] + MOD) % MOD;
        for(node* p = Hash[key]; p; p = p->next) {
            if(checkval(p->pos, i, n)) return 1;
        }
    }
    return 0;
}

int main() {

    scanf("%s %s", A + 1, B + 1);
    alen = strlen(A + 1), blen = strlen(B + 1);

    int i;
    for(i = 1; i <= alen; i++)
        a_sum[i] = a_sum[i - 1] + (A[i] - 'a' + 1) * (A[i] - 'a' + 1);
    for(i = 1; i <= blen; i++)
        b_sum[i] = b_sum[i - 1] + (B[i] - 'a' + 1) * (B[i] - 'a' + 1);
    
    for(i = min(alen, blen); i > 0; i--)
        if(check(i)) break;

    printf("%d", i);
    return 0;
}