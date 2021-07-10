/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.28

소요시간 : 1h

문제명 - 백준 15683 - 감시
   
알고리즘
    - dfs로 모든 경우의수 탐색
    - stack을 이용한 map history 복구

문제개요
    n by m 배열에 cctv종류(1~5)와 벽(6)이 주어질때 각 cctv별로 방향을 설정해서 사각지대를
    최소로 할때 그 값 출력

    각 cctv에 번호를 부여하고 해당 번호에서 방향을 설정한후 해당 방향에서 비출수있는곳을 변경해주고
    stack에 넣은후 나중에 이후 cctv들을모두 탐색한후 다시 돌아와서 stack에 있는 비췄던 곳을 다시
    0으로 초기화.


*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

struct CCTV{
    int i;
    int j;
    int type;
};

struct POSI{
    int i;
    int j;
    int index;
};

int n,m,cctvCount = 0;
int map[9][9];
int left_ = 0;

queue<int> q;
stack<POSI> cctvStack;
CCTV list[9];

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

int go(int index, int direction, int noMonitor){
    CCTV cctv = list[index];
    POSI posi;
    int goi,goj;
    int tmp;

    if(index == cctvCount){
        return noMonitor;
    }

    if(cctv.type == 1){
        q.push(direction);
    }
    else if(cctv.type == 2){
        if(direction == 0){
            q.push(0);
            q.push(2);
        }
        else if(direction == 1){
            q.push(1);
            q.push(3);
        }
        else{
            return 1000000;
        }
    }
    else if(cctv.type == 3){
        q.push(direction);
        if(direction == 3){
            q.push(0);
        }
        else{
            q.push(direction+1);
        }
    }
    else if(cctv.type == 4){
        q.push(direction);
        if(direction+1 > 3){
            q.push(direction - 3);
        }
        else{
            q.push(direction+1);
        }
        if(direction + 2 > 3){
            q.push(direction - 2);
        }
        else{
            q.push(direction + 2);
        }
    }
    else{
        if(direction == 0){
            for(int i=0;i<4;i++){
                q.push(i);
            }
        }
        else{
            return 1000000;
        }
    }
    
    while(q.size() > 0){
        goi = cctv.i;
        goj = cctv.j;
        while(true){
            goi = goi + di[q.front()];
            goj = goj + dj[q.front()];
            if(goi >= 0 && goj >= 0 && goi < n && goj < m){
                if(map[goi][goj] == 6){ // 벽 만났을때
                    break;
                }
                else if(map[goi][goj] == 0){ // 사각지대 없앨수 있을때
                    map[goi][goj] = 10;
                    posi.i = goi;
                    posi.j = goj;
                    posi.index = index;
                    cctvStack.push(posi);
                    noMonitor--;
                }
            }
            else{
                break;
            }
        }
        q.pop();
    }
    
    int minimum = 1000000;
    for(int i=0;i<4;i++){
        minimum = min(minimum, go(index+1,i,noMonitor));
    }
    while(cctvStack.size() > 0){
        if(cctvStack.top().index == index){
            map[cctvStack.top().i][cctvStack.top().j] = 0;
            cctvStack.pop();
        }
        else{
            break;
        }
    }
    return minimum;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5){
                list[cctvCount].i = i;
                list[cctvCount].j = j;
                list[cctvCount].type = map[i][j];
                cctvCount++;
            }
            else if(map[i][j] == 0){
                left_++;
            }
        }
    }
    int minimum = 100000;
    for(int i=0;i<4;i++){
        minimum = min(minimum, go(0,i,left_));
    }
    cout << minimum;
}