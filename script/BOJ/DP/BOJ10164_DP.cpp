//Problem: [격자상의 경로] https://www.acmicpc.net/problem/10164
//Solver: Sieun Park
//Solved Date: 2021.05.08

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    
    int max_size;
    int x, y;
    if(k == 0) max_size = (m-1)+(n-1);
    else{
        x = k % n;
        y = k / n + 1;
        if(x == 0){ x = n; y--; }
        max_size = max((x-1)+(y-1), (m+n)-(x+y));
    }

    double factorial[max_size+1];
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i < max_size+1; i++){
        factorial[i] = factorial[i-1] * i;
    }

    double ans;
    if(k==0){
        ans = factorial[(m-1)+(n-1)] / (factorial[m-1]*factorial[n-1]);
    } else{
        ans = factorial[(x-1)+(y-1)] * factorial[(n-x)+(m-y)] / (factorial[x-1] * factorial[y-1] * factorial[n-x] * factorial[m-y]);
    }

    printf("%.0f", ans);

    return 0;
}