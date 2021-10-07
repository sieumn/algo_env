//Problem: [주사위 굴리기] https://www.acmicpc.net/problem/14499

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){

    int map[20][20];
    int xy_dir[5][2] = {{0, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int dice_dir[7][7] = {{0,0,0,0,0,0,0}, {3,2,4,5,3,2,4}, {3,6,4,1,3,6,4}, {2,1,5,6,2,1,5}, {5,1,2,6,5,1,2}, {3,1,4,6,3,1,4}, {3,5,4,2,3,5,4}};
    int dice_num[7] = {0,0,0,0,0,0,0};
    int n, m, x, y, k;
    int dir, top, right, bot;
    queue<int> command;

    scanf("%d %d  %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int e;
            scanf("%d", &e);
            map[i][j] = e;
        }
    }
    for(int i=0; i<k; i++){
        int e;
        scanf("%d", &e);
        command.push(e);
    }

    top = 1; right = 3; //top+bot=7
    for(int i=0; i<k; i++){
        int tmptop = top, tmpright = right;
        dir = command.front(); command.pop();
        if(dir == 2) dir = 3;
        else if(dir == 3) dir = 2;

        int right_idx = 0;
        while(true){
            if(dice_dir[top][right_idx] == right) break;
            right_idx++;
        }
        bot = dice_dir[top][right_idx + dir - 1];
        if(dir == 1) right = top;
        if(dir == 3) right = 7 - top;
        top = 7 - bot;

        x += xy_dir[dir][0]; y += xy_dir[dir][1];
        //printf("test: %d, %d, %d, (%d, %d) ", dir, right, bot, x, y);
        if(x < 0 || y < 0 || x > n-1 || y > m-1){
            x -= xy_dir[dir][0]; y-= xy_dir[dir][1];
            top = tmptop, right = tmpright;
            continue;
        }
        if(map[x][y]==0) map[x][y] = dice_num[bot];
        else{
            dice_num[bot] = map[x][y];
            map[x][y] = 0;
        }

        printf("%d\n", dice_num[top]);

    }
    return 0;
}