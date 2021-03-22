// Ploblem: [수 정렬하기 2] https://www.acmicpc.net/problem/2751

// Solver: Sieun Park
// Solved Date: 2021.03.22
// BigO: O(nlogn)

#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int> &left, vector<int> &right){
    vector<int> combine;
    int l_idx=0, r_idx=0;
    int iter = left.size() + right.size();

    for(int i=0; i<iter; i++){
        if(l_idx == left.size()) combine.push_back(right[r_idx++]);
        else if(r_idx == right.size()) combine.push_back(left[l_idx++]);
        else if(left[l_idx]<right[r_idx]) combine.push_back(left[l_idx++]);
        else combine.push_back(right[r_idx++]);
    }
    return combine;
}

vector<int> merge_sort(vector<int> &seq, int first, int last){
    vector<int> left, right;
    vector<int> temp;

    if(first < last){
        int mid = (first+last)/2;
        left = merge_sort(seq, first, mid);
        right = merge_sort(seq, mid+1, last);
        return merge(left, right);
    } else{
        temp.push_back(seq[first]);
        return temp;
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
    ans = merge_sort(seq, 0, n-1);

    for(int i=0; i<n; i++) printf("%d\n", ans[i]);

    return 0;
}