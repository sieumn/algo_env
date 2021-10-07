//Problem: [뱀] https://www.acmicpc.net/problem/3190

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int, int> add(const pair<int, int> &a, const pair<int, int> &b){
    return make_pair(a.first + b.first, a.second + b.second);
}

int main(){

    int n, anum, turn;
    int map[101][101];
    vector<pair<int, int> > snake;
    vector<pair<int, int> > dir;

    fill(&map[0][0], &map[0][0]+101*101, 0);

    scanf("%d", &n);
    scanf("%d", &anum);
    for(int i=0; i<anum; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1; //1: apple
    }
    map[1][1] = 2; //2: snake
    snake.push_back(make_pair(1,1));

    scanf("%d", &turn);
    for(int i=0; i<turn; i++){
        int a; char c;
        scanf("%d %c", &a, &c);
        if(c == 'D') dir.push_back(make_pair(a, 0)); //dir.second = 0: 오른쪽
        else if(c =='L') dir.push_back(make_pair(a, 1)); //dir.second = 1: 왼쪽
    }

    int time = 0;
    pair<int, int> curdir = make_pair(0, 1); //현재 뱀머리좌표
    while(true){
        time++;

        pair<int, int> next = add(snake.back(), curdir); //한 칸 앞으로
        if(next.first == 0 || next.first == n+1 || next.second == 0 || next.second == n+1){ break; } //벽이면 종료
        if(map[next.first][next.second] == 2){ break; } //자기 자신 만나면 종료
        
        //사과 만나면 먹기. 사과 못만나면 꼬리자르기
        if(map[next.first][next.second] != 1){
            map[snake.front().first][snake.front().second] = 0;
            snake.erase(snake.begin());
        }
        map[next.first][next.second] = 2;
        snake.push_back(next);

        if(time == (dir.front()).first){ 
            int k = 1;
            if(curdir.first == 0){ //좌우방향
                if(dir.front().second == 1) k = -1; 
                curdir = make_pair(k * curdir.second, 0);
            } else{ //왼쪽
                if(dir.front().second == 0) k = -1;
                curdir = make_pair(0, k * curdir.first);
            }
            dir.erase(dir.begin());
        }
    }
    
    printf("%d", time);
    return 0;
}