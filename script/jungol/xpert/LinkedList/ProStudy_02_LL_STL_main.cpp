/**************************************************************
    Problem: 3123 (키로거(Keylogger))
    User: sieunss.park
    Language: C++
    Result: Success
    Time:153 ms
    Memory:4556 kb
    Date: 2021.10.05
****************************************************************/
 
#include<iostream>
#include<vector>
using namespace std;
 
class keyboard{
private:
    vector<char> A, B;
     
public:
    void init(){
        A.clear(); B.clear();
    }
 
    void moveleft(){
        if(A.empty()) return;
        B.push_back(A.back());
        A.pop_back();
    }
 
    void moveright(){
        if(B.empty()) return;
        A.push_back(B.back());
        B.pop_back();
    }
 
    void erase(){
        if(A.empty()) return;
        A.pop_back();
    }
 
    void insert(char val){
        A.push_back(val);
    }
 
    void show(){
        for(char ch : A) printf("%c", ch);
        for(auto p = B.rbegin(); p != B.rend(); p++)
            printf("%c", *p);
        printf("\n");
    }
 
};
 
int main(){
 
    int T;
    scanf("%d", &T);
 
    char str[1000000 + 10];
    keyboard key;
 
    for(int i = 0; i < T; i++){
        key.init();
        scanf("%s", str);
        for(int j=0; str[j]; j++){
            if(str[j] == '<') key.moveleft();
            else if(str[j] == '>') key.moveright();
            else if(str[j] == '-') key.erase();
            else key.insert(str[j]);
        }
        key.show();
    }
 
    return 0;
 
}