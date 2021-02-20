/*
36m

그래프 - bfs

문제개요 : 물,벽,시작,도착 지점이 주어지고, 물은 한칸씩 상하좌우로 범람. 고슴도치가 물을피해 도착지에 갈수있는 최소거리 출력

물의 움직임을 먼저 bfs로 구현한후 고슴도치가 물이 범람한 상황에서 움직일수 있는 곳을 bfs로 구현한다.

주의할점은 물의 범람은 지속적으로 forest 배열에 기록되어 중복으로 방문하지않는데

고슴도치는 따로 기록을 해두지 않아 메모리 초과가 발생하였다.

따라서 고슴도치의 기록역시 있어야하는데 기존 forest에 중복해서 사용하면 혼란이 생길수 있어

visited[][]배열을 통해 방문여부를 체크하였다.


*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int r,c;
int forest[51][51];
int visited[51][51];
queue<pair<int, int> > water_q1;
queue<pair<int, int> > water_q2;
queue<pair<int, int> > s_q1;
queue<pair<int, int> > s_q2;


int move(){
    // 물 범람
    water_q1 = water_q2;
    while(water_q2.size() > 0){
        water_q2.pop();
    }
    pair<int, int> sub;
    while(water_q1.size() > 0){
        sub = water_q1.front();
        water_q1.pop();
        if(sub.first > 0){
            if(forest[sub.first-1][sub.second] == 0){
                forest[sub.first-1][sub.second] = 1;
                water_q2.push(make_pair(sub.first-1,sub.second));
            }
        }
        if(sub.first < (r-1)){
            if(forest[sub.first+1][sub.second] == 0){
                forest[sub.first+1][sub.second] = 1;
                water_q2.push(make_pair(sub.first+1,sub.second));
            }
        }
        if(sub.second > 0){
            if(forest[sub.first][sub.second-1] == 0){
                forest[sub.first][sub.second-1] = 1;
                water_q2.push(make_pair(sub.first,sub.second-1));
            }
        }
        if(sub.second < (c-1)){
            if(forest[sub.first][sub.second+1] == 0){
                forest[sub.first][sub.second+1] = 1;
                water_q2.push(make_pair(sub.first,sub.second+1));
            }
        }
    }

    // 고슴도치 이동
    s_q1 = s_q2;
    while(s_q2.size() > 0){
        s_q2.pop();
    }
    while(s_q1.size() > 0){
        sub = s_q1.front();
        s_q1.pop();
        if(forest[sub.first][sub.second] == 3){
            return 0;
        }

        if(sub.first > 0){
            if(forest[sub.first-1][sub.second] == 0 || forest[sub.first-1][sub.second] == 3){
                if(visited[sub.first-1][sub.second] == 0){
                    visited[sub.first-1][sub.second] = 1;
                    s_q2.push(make_pair(sub.first-1,sub.second));
                }
            }
        }
        if(sub.first < (r-1)){
            if(forest[sub.first+1][sub.second] == 0 || forest[sub.first+1][sub.second] == 3){
                if(visited[sub.first+1][sub.second] == 0){
                    visited[sub.first+1][sub.second] = 1;
                    s_q2.push(make_pair(sub.first+1,sub.second));
                }
            }
        }
        if(sub.second > 0){
            if(forest[sub.first][sub.second-1] == 0 || forest[sub.first][sub.second-1] == 3){
                if(visited[sub.first][sub.second-1] == 0){
                    visited[sub.first][sub.second-1] = 1;
                    s_q2.push(make_pair(sub.first,sub.second-1));
                }
            }
        }
        if(sub.second < (c-1)){
            if(forest[sub.first][sub.second+1] == 0 || forest[sub.first][sub.second+1] == 3){
                if(visited[sub.first][sub.second+1] == 0){
                    visited[sub.first][sub.second+1] = 1;
                    s_q2.push(make_pair(sub.first,sub.second+1));
                }
            }
        }
    }
    if(s_q2.size() > 0){
        return move() + 1;
    }
    else{
        return -10000000;
    }
}

int main(){
    char tmp;
    cin >> r;
    cin >> c;
    for(int i = 0; i < r; i++){
        for(int j=0; j<c; j++){
            visited[i][j] = 0;
            cin >> tmp;
            if(tmp == 'D'){
                forest[i][j] = 3;
            }
            else if(tmp == 'S'){
                forest[i][j] = 0;
                s_q2.push(make_pair(i,j));
            }
            else if(tmp == '.'){
                forest[i][j] = 0;
            }
            else if(tmp == '*'){
                forest[i][j] = 1;
                water_q2.push(make_pair(i,j));
            }
            else{ // tmp == 'X'
                forest[i][j] = 4;
            }
        }
    }
    int answer = move();
    if(answer < 0){
        cout << "KAKTUS";
    }
    else{
        cout << answer;
    }
}