//Problem: [계단오르기] https://www.acmicpc.net/problem/2579
//Solver: Sieun Park
//Solved Date: 2021.05.08

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int num;
    scanf("%d", &num);
    vector<int> stairs;
    vector< pair<int, int> > count;

    stairs.push_back(0);
    for(int i = 0; i < num; i++){
        int e;
        scanf("%d", &e);
        stairs.push_back(e);
    }

    count.push_back(make_pair(0,0));
    count.push_back(make_pair(stairs[1], stairs[1]));
    if(num >= 2) count.push_back(make_pair(stairs[1]+stairs[2], stairs[2]));
    
    int cur1, cur2;
    for(int i = 3; i < num + 1; i++){
        cur1 = count[i-1].second + stairs[i];
        if(count[i-2].first > count[i-2].second) cur2 = count[i-2].first + stairs[i];
        else cur2 = count[i-2].second + stairs[i];

        count.push_back(make_pair(cur1, cur2));
    }
    cur1 = count.back().first;
    cur2 = count.back().second;

    if(cur1 > cur2) printf("%d", cur1);
    else printf("%d", cur2);
}