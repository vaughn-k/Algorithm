/*
13m

백준 17404 - RGB거리 2

dp - 함수형 재귀 + 메모이제이션 

문제 개요 : N개의 집이 있고 각 집마다 3개의 색중 하나를 칠해야하는데 각 집은 앞뒤집과 색이 달라야하며, 첫집과 마지막 집의 색도 달라야할때

각 집들의 색별 칠하는 비용이 주어졌을때 최소의 비용으로 모든 집을 칠하는 방법 구하기

*/

#include <iostream>

using namespace std;

int n;
int h[1002][3];
int d[1002][3][3];

int dp(int now, int color, int start){
    // now 번째 집을 color 색으로 칠했을때 최솟값
    int ans;
    int c[3];
    c[0] = 99999999;
    c[1] = 99999999;
    c[2] = 99999999;
    if(now == n-1){
        if(color == start){
            return 99999999;
        }
        else{
            return h[now][color];
        }
    }
    if(d[now][color][start] != -1){
        return d[now][color][start];
    }

    for(int i=0;i<3;i++){
        if(i != color){
            c[i] = dp(now+1,i,start);
        }
    }
    ans = min(c[0],min(c[1],c[2])) + h[now][color];
    d[now][color][start] = ans;
    return ans;
}    

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> h[i][0] >> h[i][1] >> h[i][2];
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                d[i][j][k] = -1;
            }
        }
    }
    int a1,a2,a3;
    a1 = dp(0,0,0);
    a2 = dp(0,1,1);
    a3 = dp(0,2,2);
    cout << min(a1,min(a2,a3));
}