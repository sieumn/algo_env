//Problem: [Complete] [괄호 추가하기] https://www.acmicpc.net/problem/16637

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int ansmax = -999999;

void calculate(vector<int>& num, vector<int>& op, vector<int>& visited, int s){

    vector<int> nnum;
    nnum.resize(num.size()); copy(num.begin(), num.end(), nnum.begin());
    vector<int> nop;
    nop.resize(op.size()); copy(op.begin(), op.end(), nop.begin());
    vector<int> nvisited;
    nvisited.resize(visited.size()); copy(visited.begin(), visited.end(), nvisited.begin());
    
    if(nnum.size()==1){
        if(nnum.front() > ansmax) ansmax = nnum.front();
        //printf("case3: %d\n", nnum.front());
        return ;
    }

    int tmp = nnum[0];
    for(int i=0; i<nnum.size()-1; i++){
        switch(nop[i]){
            case 0: tmp += nnum[i+1]; break;
            case 1: tmp -= nnum[i+1]; break;
            case 2: tmp *= nnum[i+1]; break;
        }
    }
    if(tmp > ansmax) ansmax = tmp;
    //printf("case1: %d\n", tmp);

    int chk = 0;
    for(int i=0; i<num.size()-1; i++){
        if(nvisited[i]==0 && nvisited[i+1]==0) chk++;
    }
    if(chk == 0 || nvisited[s]==1 || nvisited[s+1]==1) return;

    switch(nop[s]){
        case 0: nnum[s] += nnum[s+1]; break;
        case 1: nnum[s] -= nnum[s+1]; break;
        case 2: nnum[s] *= nnum[s+1]; break;
    }
    nvisited[s] = 1;
    nnum.erase(nnum.begin()+s+1);
    nop.erase(nop.begin()+s);
    nvisited.erase(nvisited.begin()+s+1);

    for(int i=0; i<nnum.size()-1; i++){
        calculate(nnum, nop, nvisited, i);
    }
}

int main(){
    int len;
    char str[20];

    vector<int> num;
    vector<int> op;

    scanf("%d", &len);
    scanf("%s", str);

    for(int i=0; i<len; i++){
        if(i%2){
            if(str[i]=='+') op.push_back(0);
            else if(str[i]=='-') op.push_back(1);
            else op.push_back(2);
        }
        else num.push_back(str[i] - '0');
    }

    vector<int> visited;
    visited.resize(num.size());

    if(num.size()==1){
        printf("%d", num[0]); return 0;
    }
    for(int i=0; i<num.size()-1; i++){
        visited.resize(num.size());
        calculate(num, op, visited, i);
    }

    printf("%d", ansmax);
    return 0;
}