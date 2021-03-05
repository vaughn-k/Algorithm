/*
15m

그래프 - dfs - RGB 구역개수 구하기인데 적록색약 여부에 따라 RG를 같게보냐 아니냐에 따른 두가지 
구역개수 구하기

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> v;
int visited[101][101];
// 0 : 미방문 / 1 방문

bool color_check(char col1, char col2){
    if(col1 == col2){
        return true;
    }
    else if(col1 == 'R' && col2 == 'G'){
        return true;
    }
    else if(col1 == 'G' && col2 == 'R'){
        return true;
    }
    else{
        return false;
    }
}

void color_run_spec(char now, int x, int y){
    visited[x][y] = 1;
    if(x > 0){ // move left
        if(visited[x-1][y] == 0 && color_check(v[x-1][y],now)){
            color_run_spec(now,x-1,y);
        }
    }
    if(x < (n-1)){ // move right
        if(visited[x+1][y] == 0 && color_check(v[x+1][y],now)){
            color_run_spec(now,x+1,y);
        }
    }
    if(y > 0){ // move up
        if(visited[x][y-1] == 0 && color_check(v[x][y-1],now)){
            color_run_spec(now,x,y-1);
        }
    }
    if(y < (n-1)){ // move down
        if(visited[x][y+1] == 0 && color_check(v[x][y+1],now)){
            color_run_spec(now,x,y+1);
        }
    }
}

int color_run_spec(){
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                color_run_spec(v[i][j],i,j);
                total++;
            }
        }
    }
    return total;
}

void color_normal(char now, int x, int y){
    visited[x][y] = 1;
    if(x > 0){ // move left
        if(visited[x-1][y] == 0 && v[x-1][y] == now){
            color_normal(now,x-1,y);
        }
    }
    if(x < (n-1)){ // move right
        if(visited[x+1][y] == 0 && v[x+1][y] == now){
            color_normal(now,x+1,y);
        }
    }
    if(y > 0){ // move up
        if(visited[x][y-1] == 0 && v[x][y-1] == now){
            color_normal(now,x,y-1);
        }
    }
    if(y < (n-1)){ // move down
        if(visited[x][y+1] == 0 && v[x][y+1] == now){
            color_normal(now,x,y+1);
        }
    }
}

int color_run_normal(){
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                color_normal(v[i][j],i,j);
                total++;
            }
        }
    }
    return total;
}



int main(){
    string tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
    cout << color_run_normal() << " ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
    cout << color_run_spec();
}