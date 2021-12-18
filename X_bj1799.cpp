#include <iostream>

using namespace std;

int n;
int borad[11][11];
int cross[11][11];
int save[11][11];
int left_;
/*
0 : 비숍이 갈수 없는곳
1 : 비숍이 갈수 있는곳
2 : 비숍이 현재 서있는곳
3 : 현재 비숍과 대각선에 위치한 곳들 = 현재는 놓을수 없음
*/

int di[] = {-1,-1,1,1};
int dj[] = {-1,1,-1,1};

void printCross(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << cross[i][j];
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}
void printBoard(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << borad[i][j];
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

void removeCross(int seq){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cross[i][j] == seq){
                cross[i][j] = 0;
                left_++;
            }
        }
    }
}

void fillCross(int x, int y, int seq){
    // count 번째 체스말을 [x][y]에 놓을것이다.
    int go_i, go_j;
    if(cross[x][y] == 0){
        left_--;
        cross[x][y] = seq;
    }
    for(int k=0;k<4;k++){
        go_i = x + di[k];
        go_j = y + dj[k];
        while(go_i >= 0 && go_i < n && go_j >= 0 && go_j < n){
            if(cross[go_i][go_j] == 0){
                left_--;
                cross[go_i][go_j] = seq;
            }
            go_i = go_i + di[k];
            go_j = go_j + dj[k];
        }
    }
}

int go(int x,int y, int seq, int maxi){
    int now_max = 0;
    if(left_ + seq - 1 < maxi){
        return 0;
    }
    fillCross(x,y,seq);
    // cout << "seq : " << seq << endl;
    // cout << "x : " << x << " |  y : " << y << endl;
    // printCross();
    bool NotCheck = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(NotCheck){
                if(i == x && j == y){
                    NotCheck = false;
                }
            }
            else{
                if(borad[i][j] == 1 && cross[i][j] == 0){
                    now_max = max(maxi,go(i,j,seq+1,maxi));
                }
            }
        }
    }
    removeCross(seq);
    return now_max+1;
}

int main_run(){
    int maxi = 0;
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(borad[i][j] == 1){
                borad[i][j] = 2; //
                tmp = go(i,j,1,maxi);
                maxi = max(maxi,tmp);
                borad[i][j] = 1; //
            }
        }
    }
    return maxi;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> borad[i][j];
            if(borad[i][j] == 1){
                left_++;
            }
            cross[i][j] = 0;
        }
    }
    // printBoard();
    cout << main_run();

}

/*
10
0 1 0 0 0 0 1 1 1 1 
1 0 1 0 1 1 0 1 0 1 
0 1 0 1 0 1 1 0 1 0 
1 0 1 0 1 0 1 0 1 0
0 1 0 0 0 0 1 1 1 1 
1 0 1 0 1 1 0 1 0 1 
0 1 0 1 0 1 1 0 1 0 
1 0 1 0 1 0 1 0 1 0
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 1 1 1 1

10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1




7
0 1 0 0 0 0 1 
1 0 1 0 1 1 0 
0 1 0 1 0 1 1 
1 0 1 0 1 0 1
0 1 0 0 0 0 1 
1 0 1 0 1 1 0 
0 1 0 1 0 1 1 


*/