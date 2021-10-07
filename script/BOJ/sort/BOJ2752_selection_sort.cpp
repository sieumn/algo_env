// Ploblem: [세수정렬] https://www.acmicpc.net/problem/2752
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

int main(){
    vector<int> seq;

    for (int i = 0; i < 3; i++){
        int e;
        scanf("%d", &e);
        seq.push_back(e);
    }

    selection_sort(3, seq);

    for (int i = 0; i < 3; i++){
        printf("%d ", seq[i]);
    }
    return 0;
}
