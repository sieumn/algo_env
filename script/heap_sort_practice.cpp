// Ploblem: [수 정렬하기 2] https://www.acmicpc.net/problem/2751

// Solver: Sieun Park
// Solved Date: 2021.03.31
// BigO: O(nlogn)

#include<iostream>
#include<vector>
using namespace std;

vector<int> heap_sort(vector<int> &seq);
void max_heapify(vector<int> &seq, int root);
void build_max_heap(vector<int> &seq);
void swap(int*, int*);

vector<int> heap_sort(vector<int> &seq){
    int heap_size = seq.size()-1;
    int len = heap_size;
    build_max_heap(seq);

    vector<int> ans;
    for(int i=len; i>1; i--){
        ans.push_back(seq[1]);
        swap(&seq[1], &seq[i]);
        seq.pop_back();
        heap_size--;
        max_heapify(seq, 1);
    }
    ans.push_back(seq[1]);
    return ans;
}

void build_max_heap(vector<int> &seq){
    int heap_size = seq.size()-1;
    for(int i=heap_size/2; i>0; i--){
        max_heapify(seq, i);
    }
}

void max_heapify(vector<int> &seq, int root){
    int heap_size = seq.size()-1;
    int max_idx = root;
    for(int i=0; i<2; i++){
        if(2*root+i > heap_size) break;
        if(seq[2*root+i]>seq[max_idx]) max_idx = 2*root+i;
    }
    if(max_idx == root) return ;
    else{
        swap(&seq[max_idx], &seq[root]);
        if(2*max_idx <= heap_size){
            max_heapify(seq, max_idx);
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char** argv){

    int len;
    vector<int> arr;
    vector<int> ans;
    arr.push_back(0); //ignore arr[0]

    scanf("%d", &len);
    for(int i=0; i<len; i++){
        int e;
        scanf("%d", &e);
        arr.push_back(e);
    }

    ans = heap_sort(arr);

    for(int i=len-1; i>=0; i--){
        printf("%d\n", ans[i]);
    }

    return 0;
}