//Problem: [01타일] https://www.acmicpc.net/problem/1904
//Solver: Sieun Park
//Solved Date: 2021.05.08

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    scanf("%d", &n);
    for(int i=3; i < n+1; i++){
        int next = arr[i-1] + arr[i-2];
        arr.push_back(next % 15746);
    }
    printf("%d", arr[n]);

    return 0;
}