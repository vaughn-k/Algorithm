/*/////////////////////////////////////////////////////////////////////////
소요시간 : 45m

문제명 - 백준 17144 - 미세먼지 안녕!

알고리즘
    - 2차원배열 좌표이동

문제개요
    n by m 배열에 공기청정기(-1) 와 미세먼지들의 양이 주어지고 시간(t)가 주어진다.
    각 초마다 미세먼지는 상하좌우로 확산하고(현재값/5 만큼) 확산한 만큼 자신은 줄어든다.
    이후 공기청정기의 위에서는 시계반시계방향으로, 아래에서는 시계방향으로 바람이 불어 미세먼지들이
    해당 방향에 맞추어 한칸씩 이동한다.

    이때 t초(t번) 반복하였을때 남아있는 미세먼지들의 총량 출력
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>

using namespace std;

int n,m,t;

int map[51][51];

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

int clocki[][4] = {{0,-1,0,1},{0,1,0,-1}};
int clockj[][4] = {{1,0,-1,0},{1,0,-1,0}};

int robot;

queue<int> q;

void spread(){ // 미세먼지 1초동안 확산
    int tmp[51][51];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j] = 0;
        }
    }
    tmp[robot][0] = -1;
    tmp[robot+1][0] = -1;

    int unit;
    int cot;
    int goi,goj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] > 0){
                unit = map[i][j] / 5;
                cot = 0;
                for(int k=0;k<4;k++){
                    goi = i + di[k];
                    goj = j + dj[k];
                    if(goi >= 0 && goj >= 0 && goi < n && goj < m){
                        if(map[goi][goj] != -1){
                            tmp[goi][goj] += unit;
                            cot++;
                        }
                    }
                }
                tmp[i][j] += map[i][j] - unit * cot;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j] = tmp[i][j];
        }
    }
}

void cleaner(){ // 공기청정기 1초동안 정화
    // up
    int nowi,nowj;
    int k;
    int before,tmp;
    int bei,bej;
    bool first;
    for(int index = 0; index < 2; index++){
        k = 0;
        first = true;
        nowi = robot + index;
        nowj = 0;
        before = 0;
        while(true){
            nowi = nowi + clocki[index][k];
            nowj = nowj+ clockj[index][k];
            // cout << nowi << " " << nowj << endl;
            if(first){
                before = map[nowi][nowj];
                map[nowi][nowj] = 0;
                first = false;
            }
            else{
                if(map[nowi][nowj] == -1){
                    break;
                }
                tmp = map[nowi][nowj];
                map[nowi][nowj] = before;
                before = tmp;
                // up condition
                if(nowi == robot && nowj == m-1){
                    k++;
                }
                else if(nowi == 0 && nowj == m-1){
                    k++;
                }
                else if(nowi == 0 && nowj == 0){
                    k++;
                }

                // down condition
                if(nowi == robot+1 && nowj == m-1){
                    k++;
                }
                else if(nowi == n-1 && nowj == m-1){
                    k++;
                }
                else if(nowi == n-1 && nowj == 0){
                    k++;
                }
            }
        }

    }
}

int main(){
    bool first = true;
    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == -1 && first){
                robot = i;
                first = false;
            }
        }
    }
    for(int i=0;i<t;i++){
        spread();
        cleaner();
    }

    int tot = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] > 0){
                tot += map[i][j];
            }
        }
    }
    cout << tot;
}
