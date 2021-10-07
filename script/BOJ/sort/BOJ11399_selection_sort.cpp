// Ploblem: [ATM] https://www.acmicpc.net/problem/11399
// [Required] Use the Selection Sort to solve it.

// Solver: Sieun Park
// Solved Date: 2021.03.16
// BigO: O(n^2)

#include <iostream>
#include <vector>

using namespace std;

void selection_sort(int n, vector<int> &seq){
    int min_idx;
    for(int i=0; i<n-1; i++){
        min_idx=i;
        for(int j=i+1; j<n; j++){
            if(seq[j] < seq[min_idx]) min_idx=j;
        }
        if(i!=min_idx) swap(seq[i], seq[min_idx]);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cal_total(vector<int> &seq){
    int sum=0;
    for(int i=0; i<seq.size(); i++)
        sum += seq[i]*(seq.size()-i);
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);

    vector<int> seq;

    for (int i = 0; i < n; i++){
        int e;
        scanf("%d", &e);
        seq.push_back(e);
    }

    selection_sort(n, seq);
    printf("%d", cal_total(seq));

    return 0;
}
