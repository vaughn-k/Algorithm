/*
26m

방문 체크해가면서 순회(중복 방문 방지, state 추가)

문제 개요 : 백준2636번 <치즈>

빈칸은 0, 치즈가 있는곳은 1로 주어지며 치즈 내부가 아닌 외부에 0으로 맞닿아 있는 부분은 한시간이 지나면 녹는다.

이때 몇시간이 흘렀을때 모두 녹는지, 그리고 마지막으로 다 녹을때 그 개수를 출력

치즈의 존재여부 0,1을 떠나 현재 방문했던 공기(10) 현재 녹은 치즈(-1) 의 상태를 추가해 중복 방문을 방지하였다.

*/

#include <iostream>

using namespace std;


int n,m;
int c[101][101];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int cheeze = 0;

/*
0 = 공기
10 = 지나간 공기
1 = 치즈
-1 = 현재 녹은곳
*/
int dc[2];
// 0 이 최신정보

void day(int i, int j){
    int gi,gj;
    for(int x=0;x<4;x++){
        gi = i+di[x];
        gj = j+dj[x];
        if((gi >= 0) && (gi <= n-1) && (gj >= 0) && (gj <= m-1)){
            if(c[gi][gj] == 0){
                c[gi][gj] = 10;
                day(gi,gj);
            }
            else if(c[gi][gj] == 1){
                c[gi][gj] = -1;
                dc[0]++;

            }
        }
    }
}

void go(){
    int de = 1;
    int count = -1;
    dc[0] = 1;
    dc[1] = 0;
    while(dc[0] != 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j] == 10){
                    c[i][j] = 0;
                }
                else if(c[i][j] == -1){
                    c[i][j] = 0;
                }
            }
        }
        c[0][0] = 10;
        dc[1] = dc[0];
        dc[0] = 0;
        day(0,0);
        count++;
    }
    cout << count << endl;
    cout << dc[1] << endl;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c[i][j];
            if(c[i][j] == 1){
                cheeze++;
            }
        }
    }
    if(cheeze == 0){
        cout << 0 << endl;
        cout << 0 << endl;
    }
    else{
        go();
    }
}
