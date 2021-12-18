/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.23

소요시간 : 5h+

문제명 - 백준 13460 - 구슬 탈출2
   
알고리즘
    - 구현

문제개요
    빨간구슬과 파란구슬, 구멍이 주어지고 벽들로 구성된 맵이 주어진다.
    판을 상하좌우로 기울여서 구슬들을 굴려 오로지 빨간구슬만을 구멍에 넣을때 최소횟수 출력
    (파란구슬이 들어갈경우 실패, 10회초과시 실패)

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <stack>

using namespace std;

char map[11][11];

struct Marble{
    int i;
    int j;
};

Marble hole;
int n,m;
stack<Marble> redStack;
stack<Marble> blueStack;

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
// 0 1 2 3 u d l r

void print(){
    cout << "-------------" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

int moveMarble(char color, int direction){
    Marble move;
    int initI,initJ;
    if(color == 'B'){
        move = blueStack.top();
    }
    else{
        move = redStack.top();
    }
    initI = move.i;
    initJ = move.j;
    map[move.i][move.j] = '.';
    while(map[move.i][move.j] == '.' || map[move.i][move.j] == 'O'){
        if(map[move.i][move.j] == 'O'){ 
            if(color == 'B'){ // 파란구슬이 먼저 구멍에 도착하면 실패
                // map[initI][initJ] = 'B';
                blueStack.push(move);
                return 1000; 
            }
            else{ // 빨간구슬이 먼저 구멍에 도착하면 성공
                // map[initI][initJ] = 'R';
                redStack.push(move);
                return 1;
            }
        }
        // cout << color << "구슬은 " << move.i << "," << move.j << "로 이동! "<< endl;
        move.i = move.i + di[direction];
        move.j = move.j + dj[direction];
    }
    move.i = move.i - di[direction];
    move.j = move.j - dj[direction];

    map[move.i][move.j] = color;
    if(color == 'R'){
        redStack.push(move);
    }
    else{
        blueStack.push(move);
    }
    return 0; // 별탈없이 구슬 이동완료
}

int go(int direction, int ct){ // u/d/r/l

    if(ct == 11){
        // cout << "불가능! "<< endl;
        return 1000;
    }
    // cout << "direc : " << direction << " cout : " << ct << endl;
    // print();
    Marble moveRed = redStack.top();
    Marble moveBlue = blueStack.top();
    char first = 'B';
    
    if(direction == 0){ // 같은 라인에 있을 때 - up
        if(moveRed.i < moveBlue.i){ // 빨간구슬 먼저출발
            first = 'R';
        }
        else{
            first = 'B';
        }
    }
    if(direction == 1){ // 같은 라인에 있을 때 - down
        if(moveRed.i > moveBlue.i){ // 빨간구슬 먼저출발
            first = 'R';
        }
        else{
            first = 'B';
        }
    }
    if(direction == 2){ // 같은 라인에 있을 때 - left
        if(moveRed.j < moveBlue.j){ // 빨간구슬 먼저출발
            first = 'R';
        }
        else{
            first = 'B';
        }
    }
    if(direction == 3){ // 같은 라인에 있을 때 - right
        if(moveRed.j > moveBlue.j){ // 빨간구슬 먼저출발
            first = 'R';
        }
        else{
            first = 'B';
        }
    }

    int stateB,stateR;

    if(first == 'B'){
        stateB = moveMarble('B',direction);
        stateR = moveMarble('R',direction);
    }
    else{
        stateR = moveMarble('R',direction);
        stateB = moveMarble('B',direction);
    }

    if(stateB == 1000){ // 파란공 구멍에 빠졌을 때
        blueStack.pop();
        map[blueStack.top().i][blueStack.top().j] = 'B';
        if(stateR == 1){ // 빨간공도 구멍에 빠졌을 때
            // cout << " blue red all hole" << endl;
            redStack.pop();
            map[redStack.top().i][redStack.top().j] = 'R';
        }
        else{ // 빨간공은 구멍에 안빠졌을 때
            // cout << " blue hole" << endl;
            map[redStack.top().i][redStack.top().j] = '.';
            redStack.pop();
            map[redStack.top().i][redStack.top().j] = 'R';
        }
        return 1000;
    }
    else if(stateR == 1){ // 빨간공 구멍에 빠졌을 때 + 파란공은 구멍에 안빠졌을 때
        // cout << " red hole && blue not hole" << endl;
        redStack.pop();
        map[redStack.top().i][redStack.top().j] = 'R';

        map[blueStack.top().i][blueStack.top().j] = '.';
        blueStack.pop();
        map[blueStack.top().i][blueStack.top().j] = 'B';
        return ct;
    }

    int minimum = 1000;
    int state;
    for(int i=0;i<4;i++){
        if(i != direction){
            state = go(i,ct+1);
            // cout << "state : " << state << endl;
            minimum = min(minimum, state);
        }
    }
    map[redStack.top().i][redStack.top().j] = '.';
    map[blueStack.top().i][blueStack.top().j] = '.';
    redStack.pop();
    blueStack.pop();
    map[redStack.top().i][redStack.top().j] = 'R';
    map[blueStack.top().i][blueStack.top().j] = 'B';
    return minimum;
}

int mainLoop(){
    int minimum = 1000;
    int state;
    for(int i=0;i<4;i++){
        state = go(i,1);
        minimum = min(minimum,state);
    }
    if(minimum == 1000){
        minimum = -1;
    }
    return minimum;
}

int main(){
    Marble red;
    Marble blue;
    string s;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            map[i][j] = s[j];
            if(map[i][j] == 'B'){
                blue.i = i;
                blue.j = j;
            }
            else if(map[i][j] == 'R'){
                red.i = i;
                red.j = j;
            }
            else if(map[i][j] == 'O'){
                hole.i = i;
                hole.j = j;
            }
        }
    }
    redStack.push(red);
    blueStack.push(blue);
    cout << mainLoop();
}

/*
3 10
##########
#.O....BR#
##########

10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##O..#
#...#....#
##########

10 10
##########
#R#...##.#
#.#.#.##.#
#.#.#.##.#
#.#.#..#.#
#.#.#.####
#.#.O.#.B#
#.###.#..#
#.....#..#
##########

3 10
##########
#.....BRO#
##########

7 10
##########
#..###..##
#....#####
###O..####
##B..##..#
##.#R#..##
##########

5 5
#####
#R..#
#..O#
#B..#
#####
*/

