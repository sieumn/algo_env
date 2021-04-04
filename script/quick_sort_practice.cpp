// Ploblem: [수 정렬하기 2] https://www.acmicpc.net/problem/2751
// [Required] Use the Quick Sort to solve it.

// Solver: Sieun Park
// Solved Date: 2021.04.03
// BigO: O(nlogn)

#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int> &arr, int, int);
int random_partition(vector<int> &arr, int, int);
int random_pivot(int, int);
void swap(int*, int*);

void quick_sort(vector<int> &arr, int front, int rear){
    if(front < rear){
        int q = random_partition(arr, front, rear);
        if(front < q-1) quick_sort(arr, front, q-1);
        if(q+1 < rear) quick_sort(arr, q+1, rear);
    }
}

int random_partition(vector<int> &arr, int front, int rear){
    int q = random_pivot(front, rear);
    swap(&arr[q], &arr[rear]);

    int left = front-1;
    for(int i = front; i < rear; i++){
        if(arr[i]<arr[rear]){
            swap(&arr[i], &arr[left+1]);
            left++;
        }
    }
    swap(&arr[rear], &arr[left+1]);
    return left+1;
}

int random_pivot(int front, int rear){
    int range = rear - front + 1;
    return rand() % range + front;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char** argv){

    int num;
    scanf("%d", &num);

    // get input
    vector<int> arr;
    for(int i=0; i<num; i++){
        int e;
        scanf("%d", &e);
        arr.push_back(e);
    }

    quick_sort(arr, 0, num-1);

    //print output
    for(int i=0; i<num; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}