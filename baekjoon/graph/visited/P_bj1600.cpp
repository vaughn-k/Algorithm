/*
1h 20m

그래프 - bfs - visited 체크 심화

문제 개요 : w by h 말판에서 (0,0)에서 (h,w)까지 가는데 체스의 말(나이트)처럼 이동하거나 상하좌우로 한칸 이동할 수 있다.

처음에 k가 주어지며 다만 나이트처럼 이동할경우 k값을 1 소모한다.

이런 조건하에 가장 적은 횟수로 가는 횟수 출력

*/

// #pragma once
#include <biostream>
#include <queue>
#include <utility>

using namespace std;

int k,w,h;
int g[201][201];
int s[201][201][32];
/*
g[i][j] = -2 = 벽
g[i][j] = -1 = 방문안함
g[i][j] = 0 방문했을때 k값

g[i][j][k] = (i,j)지점에 k횟수를 가지고 진입했는지 여부
*/


struct posi{
    int i;
    int j;
    int left;
};


queue<posi> q1;
queue<posi> q2;

int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};
int hi[] = {-1,-2,-2,-1,1,2,2,1};
int hj[] = {-2,-1,1,2,2,1,-1,-2};

// void print(){
//     cout << "-----------------" << endl;
//     for(int i=0;i<h;i++){
//         for(int j=0;j<w;j++){
//             cout << g[i][j] << " ";
//         }
//         cout << endl;
//     }

// }

int go(){
    int count = 0;
    int go_i,go_j,go_k;
    posi now;
    posi next;
    while(q2.size() > 0){
        // print();
        q1 = q2;
        while(q2.size() > 0){q2.pop();}
        while(q1.size() > 0){
            now = q1.front();
            if(now.i == h-1 && now.j == w-1){
                return count;
            }
            q1.pop();
            // 말로이동ㅈ
            for(int t=0;t<8;t++){
                go_i = now.i + hi[t];
                go_j = now.j + hj[t];
                go_k = now.left;
                // 유효한 좌표인지 확인 && 점프할 k가 남아있는지
                if(go_i >= 0 && go_j >= 0 && go_i <= h-1 && go_j <= w-1 && now.left > 0){ 
                    if(s[go_i][go_j][go_k-1] == -1){ // 그곳을 k에 대해 방문 했었는지
                        s[go_i][go_j][go_k-1] = 1;
                        next.i = go_i;
                        next.j = go_j;
                        next.left = now.left - 1;
                        q2.push(next);
                    }
                }
            }

            // 일반 상하좌우 이동
            for(int t=0;t<4;t++){
                go_i = now.i + di[t];
                go_j = now.j + dj[t];
                go_k = now.left;
                if(go_i >= 0 && go_j >= 0 && go_i <= h-1 && go_j <= w-1){
                    if(s[go_i][go_j][go_k] == -1){
                        s[go_i][go_j][go_k] = 1;
                        next.i = go_i;
                        next.j = go_j;
                        next.left = now.left;
                        q2.push(next);
                    }
                }
            }
        }
        count++;
    }
    return -1;
}

int main(){
    int tmp;
    cin >> k;
    cin >> w;
    cin >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> tmp;
            for(int a=0;a<=k;a++){
                if(tmp == 0){
                    s[i][j][a] = -1;
                }
                else{
                    s[i][j][a] = -2;
                }
            }
        }
    }
    posi p;
    p.i = 0;
    p.j = 0;
    p.left = k;
    q2.push(p);
    cout << go();
}

/*
5



*/