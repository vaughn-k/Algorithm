/*
44m
너비우선탐색(bfs)

이전에 풀었던 토마토(7576)문제와 매우 비슷하다. 오히려 토마토보다 쉬운문제였다.
다만 변수를 중복해서 사용해서 시간을 잡아먹었다.
예를 들어 for문에서 i,j를 사용했는데, 다른 변수로 i를 다시 사용해서 i값이 계속 변화하여 의도치않은 결과가 나왔다.

각 기본변수(i,j x,y a,b ...) 등등은 항상 사용하던 용도로만 가급적 사용하고, 의미있는 변수이름을 사용하도록하자.

*/

#include <iostream>
#include <queue>
#include <utility>
#include <string>


using namespace std;

int N,M,tmp;;
int maze[101][101];
int answer;
int minimum;
int check = 1;
string input;

queue<pair<int,int> > q1;
queue<pair<int,int> > q2;

int is_ok(int i, int j){
    if(i == N-1 && j == M-1 && check == 1){
        check = 0;
        answer = minimum;
    }

    if(i < 0 || i > N-1 || j < 0 || j > M-1){
        return 0;
    }
    else{
        if(maze[i][j] == 0){
            return 0;
        }
        else{
            maze[i][j] = 0;
            q2.push(make_pair(i,j));
            return 1;
        }
    }
}

void maze_go(){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    int len = q1.size();
    int x,y;
    if(len > 0){
        minimum++;
        for(int i=0;i<len;i++){
            x = q1.front().first;
            y = q1.front().second;
            is_ok(x+1,y);
            is_ok(x,y+1);
            is_ok(x-1,y);
            is_ok(x,y-1);
            q1.pop();
        }
        if(q2.size() > 0){
            maze_go();
        }
    }
}


int main(){
    cin >> N;
    cin >> M;
    for(int i=0;i<N;i++){
        cin >> input;
        for(int j=0;j<M;j++){
            maze[i][j] = input[j]-48;
        }
    }
    q2.push(make_pair(0,0));
    maze[0][0] = 0;
    maze_go();
    cout << answer+1;

}

