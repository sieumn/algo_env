//Problem: [Baseball] https://www.acmicpc.net/problem/17281
//Solved Date: 2021.05.24
//Solver: Sieun Park 

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int table[50][10];
int sselect[10];
int order[10];
int num;
int maxScore = 0;

void calscore(){
    int countout = 0;
    int score = 0;
    int alpha = 1;
    int cur = 0;
    int curscore = 0;
    queue<int> ground;

    for(int i=0; i<num; i++){
        //if(alpha) printf("\nalpha: %d\n",alpha);
        while(!ground.empty()) ground.pop();
        for(int j=0; j<3; j++) ground.push(0);
        countout = 0;

        while(countout < 3){
            for(int j=0; j<9; j++){
                
                if(j+alpha > 9) alpha -= 9;
                else if(j+alpha <= 0) alpha += 9;
                if(countout==3){
                    alpha = j+alpha;
                    break;
                }
                
                cur = order[j+alpha];
                curscore = table[i][cur];

                if(curscore == 0){
                    countout++;
                    continue;
                }
                else{
                    if(ground.front()) score++;
                    ground.pop();
                    ground.push(cur);
                }
                if(curscore == 1) continue;
                //if(curscore == 4) curscore++;
                for(int k = 0; k < curscore - 1; k++){
                    if(ground.front()) score++;
                    ground.pop();
                    ground.push(0);
                }
            }
        }
    }
    if(score > maxScore) maxScore = score;

}

void DFS(int idx){

    if(idx==10) calscore();
    else if(order[idx] > 0) DFS(idx+1);
    else{
        for(int i=1; i<10; i++){
            if(sselect[i] == 1) continue;
            sselect[i] = 1;
            order[idx] = i;
            DFS(idx+1);
            order[idx] = 0;
            sselect[i] = 0;
        }
    }
}

int main(){

    scanf("%d", &num);
    for(int i=0; i<num; i++){
        for(int j=1; j<10; j++){
            int e;
            scanf("%d", &e);
            table[i][j] = e;
        }
    }

    fill(&sselect[0], &sselect[0]+10, 0);
    fill(&order[0], &order[0]+10, 0);

    sselect[1] = 1;
    order[4] = 1;
    
    DFS(1);
    
    printf("%d", maxScore);

    return 0;
}