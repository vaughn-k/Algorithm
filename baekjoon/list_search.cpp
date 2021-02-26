#include <iostream>

// n by m 리스트에서 0과1 (0 = 길, 1 = 벽) 이 주어지고 
// (0,0) 에서 (n,m) 까지 탐색이 가능한지 출력

using namespace std;

int n,m;
int g1[100][100];
int g2[100][100];

int move_1(int i, int j){
    if(i == n && j == m){
        return 1;
    }

    if(i > 0){ // 위로 이동

    }
    if(i < n-1){ // 아래로 이동

    }
    if(j > 0){ // 

    }
    if(j < m-1){

    }

}

int main(){
    int tmp;
    cin >> n;
    cin >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tmp;
            g1[i][j] = tmp;
            g2i][j] = tmp;
        }
    }

    move1();
    move2();
}