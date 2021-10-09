/**************************************************************
    Problem: 3123 (키로거(Keylogger))
    User: sieunss.park
    Language: C++
    Result: Success
    Time:183 ms
    Memory:26500 kb
****************************************************************/

#include<iostream>
using namespace std;

const int MAX = 1000005;
char str[MAX];
int bufcnt;

struct node {
    char ch;
    node* prev, * next;
    void alloc(char _ch, node* _prev, node* _next) {
        ch = _ch, prev = _prev, next = _next;
        prev->next = next->prev = this;
    }
    void pop() {
        prev->next = next;
        next->prev = prev;
    }
} * head, *tail, *cur, buf[MAX];

int main(){
    int T;
    head = buf, tail = buf + 1;
    scanf("%d", &T);

    while (T--) {
        bufcnt = 2;
        head->next = tail, tail->prev = head;
        cur = tail;

        scanf("%s", str);
        for (int i = 0; str[i]; i++) {
            if (str[i] == '<'){
                if (cur->prev != head) cur = cur->prev;
            }
            else if (str[i] == '>') {
                if (cur != tail) cur = cur->next;
            }
            else if (str[i] == '-') {
                if (cur->prev != head) cur->prev->pop();
            }
            else {
                buf[bufcnt++].alloc(str[i], cur->prev, cur);
            }
        }
        for (node* p = head->next; p != tail; p = p->next) {
            printf("%c", p->ch);
        }
        printf("\n");
    }
    return 0;
}