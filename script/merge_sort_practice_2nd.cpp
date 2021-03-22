// Ploblem: [수 정렬하기 2] https://www.acmicpc.net/problem/2751

// Solver: Sieun Park
// Solved Date: 2021.03.22
// BigO: O(nlogn)

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &seq, int first, int mid, int last){
    vector<int> combine;
    int l_idx = first, r_idx = mid+1;
    int idx = first;

    for(int i = 0; i < last - first + 1; i++){
        if(l_idx == mid+1) combine.push_back(seq[r_idx++]);
        else if(r_idx == last+1) combine.push_back(seq[l_idx++]);
        else if(seq[l_idx]<seq[r_idx]) combine.push_back(seq[l_idx++]);
        else combine.push_back(seq[r_idx++]);
    }
    for(int i = 0; i < last - first + 1; i++){
        seq[first+i] = combine[i];
    }
}

void merge_sort(vector<int> &seq, int first, int last){
    if(first < last){
        int mid = (first+last)/2;
        merge_sort(seq, first, mid);
        merge_sort(seq, mid+1, last);
        merge(seq, first, mid, last);
    } 
} 

int main(){

    int n;
    cin >> n;

    vector<int> seq;
    for(int i=0; i<n; i++){
        int e;
        scanf("%d", &e);
        seq.push_back(e);
    }

    vector<int> ans;
    merge_sort(seq, 0, n-1);

    for(int i=0; i<n; i++) printf("%d\n", seq[i]);

    return 0;
}