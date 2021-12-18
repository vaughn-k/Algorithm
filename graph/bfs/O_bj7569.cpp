/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.04.06

소요시간 : 30m

문제명 - 백준 7569 - 토마토

난이도 - 실버1
   
알고리즘
    - 3차원 배열 bfs

문제개요
    3차원 박스상에서 익은 토마토가 근처의 안익은 토마토를 익게할 때
    몇일이 지나야 모든 토마토가 익는지 출력
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>

using namespace std;

int m,n,h;
int box[101][101][101];

int remain = 0;

struct Location{
    int h;
    int n;
    int m;
};

queue<Location> q1;
queue<Location> q2;

int dh[] = {-1,1,0,0,0,0};
int dn[] = {0,0,-1,1,0,0};
int dm[] = {0,0,0,0,-1,1};

// void print(){
//     cout << "--------------" << endl;
//     for(int i=0; i<h; i++){
//         for(int j=0; j<n; j++){
//             for(int k=0; k<m; k++){
//                 cout << box[i][j][k] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     cout << "--------------" << endl;
// }

int tomato_bfs(){
    int day = 0;
    Location now;
    Location next;

    while(q2.size() > 0){
        // print();
        day++;
        q1 = q2;
        while(q2.size() > 0){
            q2.pop();
        }
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            for(int k=0;k<6;k++){
                next.h = now.h + dh[k];
                next.n = now.n + dn[k];
                next.m = now.m + dm[k];
                if(next.h >= 0 && next.n >= 0 && next.m >= 0 && next.h < h && next.n < n && next.m < m){
                    if(box[next.h][next.n][next.m] == 0){
                        box[next.h][next.n][next.m] = 1;
                        remain--;
                        q2.push(next);
                    }
                }
            }
            if(remain == 0){
                return day;
            }
        }
    }
    return -1;
}

int main(){
    cin >> m;
    cin >> n;
    cin >> h;

    Location tmp;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> box[i][j][k];
                // cout << "i j k : " << i  << " " << j << " " << k << " " << box[i][j][k] << endl;
                if(box[i][j][k] == 1){
                    // cout << " check";
                    tmp.h = i; 
                    tmp.n = j;
                    tmp.m = k;
                    q2.push(tmp);
                }
                else if(box[i][j][k] == 0){
                    remain++;
                }
            }
        }
    }
    int ans; 
    if(remain == 0){
        cout << 0;
    }
    else{
        ans = tomato_bfs();
        
        if(ans > 0){
            cout << ans;
        }
        else{
            cout << -1;
        }
    }
}