/*
22m

그래프 - 컴포넌트개수의 최대값 구하기

n by n 행렬에 각 높이가 주어지고, k이하인곳들은 물에 범람하여 물에 범람하지 않은 곳의 개수를 구하는것

물에 범람하지 않은 컴포넌트가 몇개인지 구하고 물이 범람하는 높이에따라 가장 많은 컴포넌트를 만들수있는 최대값을 구하는 문제

가능한 물 높이만큼 컴포넌트 구하는 알고리즘을 적용하면 된다.
*/

#include <iostream>

using namespace std;

int n;
int location[101][101];
int visited[101][101];


void clear(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
}

void safe(int height, int i, int j){
    if(i > 0){ // move left
        if(location[i-1][j] > height && visited[i-1][j] == 0){
            visited[i-1][j] = 1;
            safe(height,i-1,j);
        }
    }
    if(i < (n-1)){ // move right
        if(location[i+1][j] > height && visited[i+1][j] == 0){
            visited[i+1][j] = 1;
            safe(height,i+1,j);
        }
    }
    if(j > 0){ // move up
        if(location[i][j-1] > height && visited[i][j-1] == 0){
            visited[i][j-1] = 1;
            safe(height,i,j-1);
        }
    }
    if(j < (n-1)){ // move down
        if(location[i][j+1] > height && visited[i][j+1] == 0){
            visited[i][j+1] = 1;
            safe(height,i,j+1);
        }
    }
}

int safe_run(int height){
    int total = 0;
    // 높이 h 이하인 점은 물에 잠긴다. = 높이 h 초과인 컴포넌트의 개수
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(location[i][j] > height && visited[i][j] == 0){
                // 높이가 h 초과이다 && 아직 방문하기 전이다.
                total++;
                visited[i][j] = 1;
                safe(height,i,j);
            }
        }
    }
    return total;
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> location[i][j];
        }
    }
    
    int maximum = 1;
    for(int i=1;i<100;i++){
        clear();
        maximum = max(maximum, safe_run(i));
    }
    cout << maximum;
}