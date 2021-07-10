/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.04.01

소요시간 : 40m

문제명 - 백준 14499 주사위 굴리기
   
알고리즘
    - 구현

문제개요
    n by m 맵이 주어지고 각 칸에는 숫자가 쓰여있다.
    그리고 주사위의 위치가 주어지고(초기 모든 주사위면은 0)
    주사위를 움직일 명령이 주어진다(1,2,3,4 : 우좌상하)

    그리고 정해진 규칙에따라 주사위의눈 또는 맵의 숫자가 변경되며
    움직일때마다 주사위의 윗면 숫자를 출력
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int n,m,x,y,k;
int map[21][21];
int order[1001];
int dice[6];

// 상 하 좌 우 앞 뒤

int diceMove[][6] = 
{{0,0,0,0,0,0},
{2,3,1,0,4,5},
{3,2,0,1,4,5},
{4,5,2,3,1,0},
{5,4,2,3,0,1},
};



int di[] = {0,0,0,-1,1};
int dj[] = {0,1,-1,0,0};
// 1 2 3 4 

void go(int index){
    int tmp[6];
    x = x + di[index];
    y = y + dj[index];
    if(x >= 0 && y >= 0 && x < n && y < m){
        for(int i=0;i<6;i++){
            tmp[i] = dice[diceMove[index][i]];
        }
        for(int i=0;i<6;i++){
            dice[i] = tmp[i];
        }

        if(map[x][y] == 0){
            map[x][y] = dice[1];
        }
        else{
            dice[1] = map[x][y];
            map[x][y] = 0;
        }
        cout << dice[0] << '\n';
    }
    else{
        x = x - di[index];
        y = y - dj[index];
    }
}

int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i=0;i<6;i++){
        dice[i] = 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin >> order[i];
    }

    for(int i=0;i<k;i++){
        go(order[i]);
    }
}