/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.24

소요시간 : 40m

문제명 - 백준 12100 - 2048(Easy)
   
알고리즘
    - 구현

문제개요
    2048 게임 규칙에 따라 최대 5번 움직일때 주어진 상황에서 만들수 있는 가장 큰 블록을 출력
    (단, 기존게임과 다르게 움직일때마다 새로운 블럭이 생성되지 않는다.)

    움직이는 부분은 최대 depth = 5까지 dfs로 설계하였고
    각 state마다 움직이고자 하는 방향기준으로 먼저 합칠수 있는 수들을 합쳐서 큐에 넣고
    큐에 있는 숫자들을 한번에 새로운 배열에 넣어서 다음 인자로 전달하였다. 

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>

using namespace std;

int n;

queue<int> q;

void print(int bd[][21]){
    cout << "-0------------" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << bd[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-0------------" << endl;
}

int move(int bd[][21], int direction, int ct){
    int sub[21][21];
    // direction 0,1,2,3 상하 좌우
    int maxi = 0;
    if(ct == 5){ // 종료
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maxi < bd[i][j]){
                    maxi = bd[i][j];
                }
            }
        }
    }
    else{
        int start, end, sign;
        int before;
        int now;
        if(direction == 0 || direction == 1){ // 상하로 move
            for(int c=0;c<n;c++){
                if(direction == 0){ // 위로 올릴때
                    start = 0;
                    end = n-1;
                    sign = 1;
                }
                else{ // 아래로 내릴때
                    start = n-1;
                    end = 0;
                    sign = -1;
                }
                // 합칠수 있는부분 모두 합치기
                before = -1;
                now = start;
                while(now >= 0 && now < n){                   
                    if(before == -1){
                        if(bd[now][c] != 0){
                            before = bd[now][c];
                        }
                    }
                    else{
                        if(bd[now][c] != 0){
                            if(before == bd[now][c]){ // 합쳐야 하는 상황
                                q.push(before*2);
                                before = -1;
                            }
                            else{ // 다른수가 나온상황
                                q.push(before);
                                before = bd[now][c];
                            }
                        }
                    }
                    if(now == end){
                        if(before != -1){
                            q.push(before);
                        }
                    }
                    now += sign;
                }
                while(q.size() != n){
                    q.push(0);
                }
                now = start;
                // 전부 위로 올려서 정렬하기
                while(q.size() > 0){
                    sub[now][c] = q.front();
                    q.pop();
                    now += sign;
                }
            }
        }
        else{ // 좌우로 move
            for(int c=0;c<n;c++){
                if(direction == 2){ // 좌로 밀때
                    start = 0;
                    end = n-1;
                    sign = 1;
                }
                else{ // 우로 밀때
                    start = n-1;
                    end = 0;
                    sign = -1;
                }
                // 합칠수 있는부분 모두 합치기
                before = -1;
                now = start;
                while(now >= 0 && now < n){                   
                    if(before == -1){
                        if(bd[c][now] != 0){
                            before = bd[c][now];
                        }
                    }
                    else{
                        if(bd[c][now] != 0){
                            if(before == bd[c][now]){ // 합쳐야 하는 상황
                                q.push(before*2);
                                before = -1;
                            }
                            else{ // 다른수가 나온상황
                                q.push(before);
                                before = bd[c][now];
                            }
                        }
                    }
                    if(now == end){
                        if(before != -1){
                            q.push(before);
                        }
                    }
                    now += sign;
                }
                while(q.size() != n){
                    q.push(0);
                }
                now = start;
                // 전부 위로 올려서 정렬하기
                while(q.size() > 0){
                    sub[c][now] = q.front();
                    q.pop();
                    now += sign;
                }
            }
        }
        for(int i=0;i<4;i++){
            maxi = max(move(sub,i,ct+1),maxi);
        }
    }
    return maxi;
}

int main(){
    int board[21][21];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    int maxi = 0;
    for(int i=0;i<4;i++){
        maxi = max(maxi, move(board,i,0));
    }
    cout << maxi;
}

/*

5
2 0 2 2 2
2 0 2 2 2
2 2 2 4 4
2 2 2 4 4
2 0 0 2 2
*/