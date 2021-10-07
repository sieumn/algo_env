/**************************************************************
    Problem: 3110 (주문형 농산물 재배)
    User: sieunss.park
    Language: C++
    Result: Success
    Time:273 ms
    Memory:81404 kb
    Date: 2021.10.07
****************************************************************/

#include<vector>
using namespace std;

#define MAX_LOT_SIZE 100000
#define MAX_MEMBER_ID 10000

extern int add_lot();
extern void assign(int lot_num, int s, int size, int member_id);
extern void back(int lot_num, int s, int size);
extern void grow(int lot_num, int s, int size, int crop);

struct Data{
    int lot, st, size;
};

vector<Data> mem[MAX_MEMBER_ID + 10];
int memsize[MAX_MEMBER_ID + 10];

void init_member()
{
    for(int i = 0; i <= MAX_MEMBER_ID; i++){
        mem[i].clear();
        memsize[i] = 0;
    }
}
 
void move(int s, int e){
    mem[e].push_back(mem[s].back());
    mem[s].pop_back();
}

void assign_member(int member_id, int size)
{
    if(memsize[0] < size){
        int lot = add_lot();
        Data tmp = {lot, 0, MAX_LOT_SIZE};
        mem[0].push_back(tmp);
        memsize[0] += MAX_LOT_SIZE;
    }

    memsize[0] -= size;
    memsize[member_id] = size;

    while(size > 0){
        auto it = mem[0].back();
        if(mem[0].back().size > size){
            mem[0].back().size -= size;
            Data tmp = {it.lot, it.st + it.size - size, size};
            mem[0].push_back(tmp);
            it = mem[0].back();
        }
        size -= it.size;
        assign(it.lot, it.st, it.size, member_id);
        move(0, member_id);
    }
}
 
void back_member(int member_id)
{
    memsize[0] += memsize[member_id];
    memsize[member_id] = 0;

    while(!mem[member_id].empty()){
        auto it = mem[member_id].back();
        back(it.lot, it.st, it.size);
        move(member_id, 0);
    }
}
 
void grow_member(int member_id, int crop)
{
    for(Data p : mem[member_id]){
        grow(p.lot, p.st, p.size, crop);
    }
}