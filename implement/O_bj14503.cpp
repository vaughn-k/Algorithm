/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.26

소요시간 : 30m

문제명 - 백준 14503 - 로봇 청소기
   
알고리즘
    - 구현

문제개요
    로봇청소기가 정해진 규칙에 따라 이동할때 청소하는 구역의 개수 출력

    문제이해하기 힘들었음

*//////////////////////////////////////////////////////////////////////////


#include <iostream>

using namespace std; 

int n,m;
int map[51][51];
int tot = 0;
// 0 : 빈칸(청소전) | 1 : 벽 | 2 : 청소한칸

int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};
// 상 우 하 좌

int nextDirection(int start){
    start = start - 1;
    if(start < 0){
        return 3;
    }
    else{
        return start;
    }
}

int backingDirection(int start){
    if(start == 1){
        return 3;
    }
    else if(start == 2){
        return 0;
    }
    else if(start == 3){
        return 1;
    }
    else{
        return 2;
    }
}

int move(int ni, int nj, int direction){
    int nowDirection = direction;
    int tmpDirection;
    int nexti,nextj;
    int cot = 0;
    while(true){
        if(cot == 4){ // 갈곳이 없는 상황 
            tmpDirection = backingDirection(nowDirection);
            nexti = ni + di[tmpDirection];
            nextj = nj + dj[tmpDirection];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < m){
                if(map[nexti][nextj] == 1){ // 벽이면 종료
                    return 0;
                }
                else{
                    return move(nexti,nextj,nowDirection);
                }
            }
            else{
                return 0;
            }
        }
        nowDirection = nextDirection(nowDirection);
        nexti = ni + di[nowDirection];
        nextj = nj + dj[nowDirection];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < m){
            if(map[nexti][nextj] == 0){ // 다음장소가 아직 청소안한곳
                map[nexti][nextj] = 2;
                tot++;
                return move(nexti,nextj,nowDirection);
            }
        }
        cot++;
    }

}

int main(){
    int si,sj,d;
    cin >> n >> m;
    cin >> si >> sj >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    map[si][sj] = 2;
    tot++;
    move(si,sj,d);
    cout << tot;
}