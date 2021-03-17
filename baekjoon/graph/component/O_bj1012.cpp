/*
15m

그래프 관계를 주었을때 서로 연결되어있는 그래프의 개수가 몇개인지 찾는 문제

재귀로 풀어도되고, dfs, bfs 전부 상관없다.

매우 쉽다.

*/

#include <iostream>

using namespace std;

int t,m,n,k;
int ground[51][51];
int leftCount;
int Count = 0;


int go(int x, int y){
    if(x >= 0 && x < m && y >= 0 && y < n){
        if(ground[x][y] == 1){
            ground[x][y] = 0;
            leftCount--;
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

void sub_loop(int x, int y){
    if(go(x+1,y) == 1){
        sub_loop(x+1,y);
    }
    if(go(x,y+1) == 1){
        sub_loop(x,y+1);
    }
    if(go(x-1,y) == 1){
        sub_loop(x-1,y);
    }
    if(go(x,y-1) == 1){
        sub_loop(x,y-1);
    }
}

void main_loop(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(ground[i][j] == 1){
                sub_loop(i,j);
                Count++;
            }
        }
    }
    cout << Count << endl;
}

int main(){
    int tmp1, tmp2;
    cin >> t;
    for(int test=0;test<t;test++){
        for(int x=0;x<51;x++){
            for(int y=0;y<51;y++){
                ground[x][y] = 0;
            }
        }
        cin >> m;
        cin >> n;
        cin >> k;
        leftCount = 0;
        Count = 0;
        for(int i=0;i<k;i++){
            cin >> tmp1;
            cin >> tmp2;
            ground[tmp1][tmp2] = 1;
            leftCount++;
        }

        main_loop();
    }

}