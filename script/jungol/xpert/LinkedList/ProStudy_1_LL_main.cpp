/**************************************************************
    Problem: 1102 (스택 (stack))
    User: sieunss.park
    Language: C++
    Result: Success
    Time:1 ms
    Memory:2084 kb
    Date: 2021.10.05
****************************************************************/
 
#include<iostream>
using namespace std;
 
#define MAX_SIZE 100
 
class stack{
private:
    int arr[MAX_SIZE+10];
    int top;
 
public:
    stack() : top(-1) {};
 
    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }
 
    void push(int val){
        arr[++top] = val;
    }
 
    void pop(){
        if(isEmpty())
            cout << "empty\n";
        else
            cout << arr[top--] << "\n";
    }
 
    void size(){
        cout << (top + 1) << "\n";
    }
};
 
int main(){
 
    int T, val;
    char mode;
    stack st;
 
    cin >> T;
 
    for(int i = 0; i < T; i++){
        cin >> mode;
        if(mode == 'i'){
            cin >> val;
            st.push(val);
        }
        else if(mode == 'c')
            st.size();
        else if(mode == 'o')
            st.pop();
    }
 
    return 0;
}