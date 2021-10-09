/**************************************************************
    Problem: 3247 (한줄 메모장2)
    User: sieunss.park
    Language: C++
    Result: Success
    Time:1401 ms
    Memory:1416 kb
    Date: 2021.10.07
****************************************************************/

#ifndef NULL
#define NULL 0
#endif

#include<deque>
#include<string.h>
#include<string>
using namespace std;

deque<char> memo1, memo2, del;
int mode, cnt;

void initUser(){
    memo1.clear(), memo2.clear();
    mode = 0;
}
 
void Insert(int len, char str[]){
    if(mode != 1){
        mode = 1;
        cnt = 0;
    }
    cnt += len;
    for(int i=0; i<len; i++) memo1.push_back(str[i]);
}
 
void Backspace(int count){
    if(mode != -1){
        mode = -1;
        del.clear();
    }
    for(int i=0; i<count; i++){
        if(memo1.empty()) break;
        del.push_front(memo1.back());
        memo1.pop_back();
    }
}
 
void Delete(int count){
    if(mode != -1){
        mode = -1;
        del.clear();
    }
    for(int i=0; i<count; i++){
        if(memo2.empty()) break;
        del.push_back(memo2.front());
        memo2.pop_front();
    }       
}
 
void moveForward(int moveCnt){
    mode = 0;
    for(int i=0; i<moveCnt; i++){
        if(memo1.empty()) return;
        memo2.push_front(memo1.back());
        memo1.pop_back();
    }
}
 
void moveBackward(int moveCnt){
    mode = 0;
    for(int i=0; i<moveCnt; i++){
        if(memo2.empty()) return;
        memo1.push_back(memo2.front());
        memo2.pop_front();
    }
}
 
void Undo(){
    if(mode == 1){
        Backspace(cnt);
    }
    else if(mode == -1){
        mode = 1, cnt = del.size();
        while(del.size()){
            memo1.push_back(del.front());
            del.pop_front();
        }
    }
}
 
void getString(int stPos, int len, char str[]){
    mode = 0;
    int k = 0;
    while(stPos < memo1.size() && k < len) str[k++] = memo1[stPos++];
    while(stPos - memo1.size() < memo2.size() && k < len) str[k++] = memo2[stPos++ - memo1.size()];
}