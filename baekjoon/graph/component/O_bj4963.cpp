// 30m

/*
그래프 순환 기본문제인데

if(){
    if(){
        code
        return 1;
    }

    -> 여기부분 else시 리턴값이 없어서 실수발생
}
else{
    return 0;
}

이런식으로 설계해서 의도치않은 값이 리턴되었다.
조건문 설계시 예외없이 설계할것

*/

#include <iostream>

using namespace std;

int w,h;
int island[52][52];
int check[52][52];
// 0 not visited
// 1 visited
int tmp;
int total;

int go(int x, int y){
    if(x >= 0 && x < h && y >= 0 && y < w){
        if(island[x][y] == 1 && check[x][y] == 0){
            // 가려고하는 x,y가 섬이면서, 아직 방문 안한상태
            check[x][y] = 1;
            return 1;
        }
    }

    return 0;

}

void sub_loop(int x, int y){
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(go(x+i,y+j) == 1){
                sub_loop(x+i,y+j);
            }
        }
    }
}

void main_loop(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(check[i][j] == 0 && island[i][j] == 1){
                sub_loop(i,j);
                total++;
            }
        }
    }
}

int main(){
    cin >> w;
    cin >> h;
    while(!(w == 0 && h == 0)){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> island[i][j];
                check[i][j] = 0;
            }
        }
        total = 0;
        main_loop();
        cout << total << endl;

        cin >> w;
        cin >> h;
    }
}