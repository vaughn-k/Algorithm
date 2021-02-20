/*
2h

판화그리기

dp나 그래프적인 알고리즘이 들어간것은 아니지만 

이전에 실패했던 문제였다.

i,j 값이 변화할때마다 이전 상황에 영향을 받아 현재 판화모양을 만들어야하고
이전뿐만 아니라 현재까지의 판화 상황도 고려해야 했기에 다소 까다로웠다.


*/

#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int map[101][101];
int shape[4][4];
// 0 : . 46
// 1 : | 124
// 2 : - 45 
// 3 : + 43

// 0 < 1,2 < 3

void print(){
    char a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 0){
                a = 46;
            }
            else if(map[i][j] == 1){
                a = 124;
            }
            else if(map[i][j] == 2){
                a = 45;
            }
            else{
                a = 43;
            }
            cout << a;
        }
        cout << endl;
    }
}

void make_shape(int before_move, int now_move, int i, int j){
    // 이전움직임과 현재 움직임 그리고 현재 목판에 기재되어있는 상황을 모두 고려해 
    // 이전칸에 넣어야할 문자 생성
    int output = shape[before_move][now_move];
    if(map[i][j] == 0){ // .
        map[i][j] = output;
    }
    if(map[i][j] != output){
        map[i][j] = 3;
    }
}
// 상 하 좌 우 0 1 2 3
void draw_all(int i, int j, int now, int history){
    if(now == s.size()){
        make_shape(history,history,i,j);
    }
    else{
        int check = 0;
        while(check == 0){
            if(now  == s.size()){
                make_shape(history,history,i,j);
                return;
            }
            if(s[now] == 'D' && i < (n-1)){
                check = 1;
                make_shape(history,1,i,j);
                draw_all(i+1,j,now+1,1);
            }
            else if(s[now] == 'U' && i > 0){
                check = 1;
                make_shape(history,0,i,j);
                draw_all(i-1,j,now+1,0);
            }
            else if(s[now] == 'R' && j <(n-1)){
                check = 1;
                make_shape(history,3,i,j);
                draw_all(i,j+1,now+1,3);
            }
            else if(s[now] == 'L' && j > 0){
                check = 1;
                make_shape(history,2,i,j);
                draw_all(i,j-1,now+1,2);
            }
            else{
                now++;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j] = 0;
        }
    }
    shape[0][0] = 1;
    shape[0][1] = 1;
    shape[0][2] = 3;
    shape[0][3] = 3;

    shape[1][0] = 1;
    shape[1][1] = 1;
    shape[1][2] = 3;
    shape[1][3] = 3;

    shape[2][0] = 3;
    shape[2][1] = 3;
    shape[2][2] = 2;
    shape[2][3] = 2;

    shape[3][0] = 3;
    shape[3][1] = 3;
    shape[3][2] = 2;
    shape[3][3] = 2;

    int check = 0;
    int i,j,now;
    now = 0;
    while(check == 0){
        if(now == s.size()){
            check = 1;
        }
        else{
            if(s[now] == 'D' && i < (n-1)){
                check = 1;
                map[0][0] = 1;
                draw_all(1,0,now+1,1);
            }
            else if(s[now] == 'R' && j <(n-1)){
                check = 1;
                map[0][0] = 2;
                draw_all(0,1,now+1,3);
            }
            else{
                now++;
            }
        }
    }
    print();
   
}