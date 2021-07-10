/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.25

소요시간 : 1h

문제명 - 백준 17825 - 주사위 윳놀이
   
알고리즘
    - 구현

문제개요
    윷놀이 말판과 각 지점별 점수가 주어지고 주사위 10개의 순서가 주어질때 최대로 얻을 수 있는 
    점수 출력.

*//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;

int dice[11];

int nxt[41];
int nxt2[16];
int score[41];

void setting(){
    for(int i=0;i<=19;i++){
        nxt[i] = i+1;
        score[i] = i*2;
    }

    nxt[20] = -1;
    score[20] = 40;

    for(int i=21;i<=22;i++){
        nxt[i] = i+1;
    }
    nxt[23] = 27;
    score[21] = 13;
    score[22] = 16;
    score[23] = 19;

    for(int i=24;i<=28;i++){
        nxt[i] = i+1;
    }
    score[24] = 28;
    score[25] = 27;
    score[26] = 26;
    score[27] = 25;
    score[28] = 30;
    nxt[29] = 20;
    score[29] = 35;

    nxt[30] = 31;
    nxt[31] = 27;
    score[30] = 22;
    score[31] = 24;


    nxt2[5] = 21;
    nxt2[10] = 30;
    nxt2[15] = 24;
}

int move(int index, int posi[4], int select, int total){
    // index번째의 주사위를 select 번째말을 움직이는데 사용할것이다. 
    // 그리고 현재까지 합계점수가 total

    // 종료조건
    if(index == 10){
        return total;
    }
    
    // 이동
    int tmp[4];
    for(int i=0;i<4;i++){ // 배열 복사
        tmp[i] = posi[i];
    }
    
    int jump = dice[index];
    int now = posi[select]; // 현위치
    while(jump > 0){
        if(now == -1){
            break;
        }
        if(jump == dice[index] && (now == 5 || now == 10 || now == 15)){ // 처음 시작위치   
            now = nxt2[now];
        }
        else{
            now = nxt[now];
        }
        jump--;
    }

    for(int i=0;i<4;i++){
        if(tmp[i] == now && now != -1){ // 도착지에 다른 말이 있을경우
            return -1;
        }
    }
    // 정상적인 경우 합계정산
    if(now != -1){ // 도착지에 도착했을 경우 점수추가 없으므로 아닐때만 플러스
        total = total + score[now];
    }
    tmp[select] = now;

    // 다음 주사위 던지기
    int maxi = 0;
    for(int i=0;i<4;i++){
        if(tmp[i] != -1){
            maxi = max(maxi, move(index+1,tmp,i,total));
        }
    }
    return maxi;
}

int main(){
    for(int i=0;i<10;i++){
        cin >> dice[i];
    }
    setting();
    int maxi = -1;
    int d[4] = {0,0,0,0};
    for(int i=0;i<4;i++){
        maxi = max(move(0,d,i,0),maxi);
    }
    cout << maxi;
}