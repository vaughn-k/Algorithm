// 그래프 이론에서 너비우선 탐색 - pair를 속성으로 가지는 queue를 이용함.
// 2차원 배열을 사용해서 각 지점들의 상태 표현

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int M,N;
int input[1001][1001];
int maximum = -1;
int leftCount = 0; // 현재 더 익혀야할 토마토수

queue<pair<int, int> > now_queue;
queue<pair<int, int> > next_queue;


void check_around_tomato(int i, int j){
    // (i,j) 주변에 자신이 익힐수 있는, 상태가 0인 토마토들을 next 큐에 pair 형태로 넣어준다. 
    if(i != N-1){ // down
        if(input[i+1][j] == 0){
            next_queue.push(make_pair(i+1,j));
            input[i+1][j] = 1;
            leftCount--;
        }
    }
    if(i != 0){ // up
        if(input[i-1][j] == 0){
            next_queue.push(make_pair(i-1,j));
            input[i-1][j] = 1;
            leftCount--;
        }
    }
    if(j != M-1){ // right
        if(input[i][j+1] == 0){
            next_queue.push(make_pair(i,j+1));
            input[i][j+1] = 1;
            leftCount--;
        }
    }
    if(j != 0){ // left
        if(input[i][j-1] == 0){
            next_queue.push(make_pair(i,j-1));
            input[i][j-1] = 1;
            leftCount--;
        }
    }
}

void tomato(){
    now_queue = next_queue;
    while(next_queue.size() > 0){
        next_queue.pop();
    }

    int len;
    len = now_queue.size();
    if(len > 0){
        for(int i=0;i<len; i++){
            check_around_tomato(now_queue.front().first, now_queue.front().second);
            now_queue.pop();
        }
        maximum++;
        tomato();
    }
}

int main(){

    cin >> M;
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tmp;
            input[i][j] = tmp;
            if(tmp == 1){
                next_queue.push(make_pair(i,j));
            }
            if(tmp == 0){
                leftCount++;
            }
        }
    }

    tomato();
    if(leftCount > 0){
        cout << -1;
    }
    else{
        cout << maximum;
    }
}
