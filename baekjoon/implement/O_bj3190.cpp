/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.24

소요시간 : 2h

문제명 - 백준 3190 - 뱀
   
알고리즘
    - 구현

문제개요
    뱀게임에서 움직일 방향들이 주어졌을때 최대 몇초동안 생존해있을 수 있는지 구하기

    자잘한 실수들 많음.

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>

using namespace std;

int n;
int c;

int map[101][101];
// 0 : 비어있음
// 1 : 사과
// 2 : 현위치
// 3 : 벽

struct Posi{
    int i;
    int j;
};

int timer[10001];
queue<char> direcQueue;

queue<Posi> queuePosi1;
queue<Posi> queuePosi2;

int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};
// char cycle[] =  {'U','R','D','L'}; 


// void print(){
//     cout << "--------------" << endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout << map[i][j];
//         }
//         cout << endl;
//     }
//     cout << "--------------" << endl;
// }
int changeDirection(int origin, char change){
    char after;
    int b;
    if(change == 'L'){
        b = -1;
    }
    else{
        b = 1;
    }
    origin = origin + b;
    if(origin == -1){
        origin = 3;
    }
    if(origin == 4){
        origin = 0;
    }
    return origin;
}

int move(int direction, int totCount){
    // print();
    // cout << "------------" << endl;
    // cout << "now direc : " << direction << endl;
    queuePosi1 = queuePosi2;
    while(queuePosi2.size() > 0){
        queuePosi2.pop();
    }
    Posi posi = queuePosi1.front();
    // 한칸 전진
    bool apple;
    posi.i = posi.i + di[direction];
    posi.j = posi.j+ dj[direction];
    // cout << posi.i << "," << posi.j << endl;
    if(posi.i < 0 || posi.j < 0 || posi.i > n-1 || posi.j > n-1){ // 벽에 닿음
        // cout << "wall "<< endl;
        return totCount;
    }
    
    else if(map[posi.i][posi.j] == 2){ // 한칸전진했는데 자신과 부딪힘
        // cout << "self kill" << endl;
        return totCount;
    }
    else if(map[posi.i][posi.j] == 1){ // 한칸전진했는데 사과
        map[posi.i][posi.j] = 2;
        apple = true;
    }
    else if(map[posi.i][posi.j] == 0){ // 한칸전진했는데 빈칸
        map[posi.i][posi.j] = 2;
        apple = false;
    }
    // cout << "go" << endl;
    queuePosi2.push(posi);
    while(queuePosi1.size() > 0){
        if(queuePosi1.size() == 1 && apple == false){
            // cout << "one" << endl;
            map[queuePosi1.front().i][queuePosi1.front().j] = 0;
        }
        else{
            // cout << "two" << endl;
            queuePosi2.push(queuePosi1.front());
        }
        queuePosi1.pop();
    }
    // cout << "right?" << endl;
    // if(!apple){
    //     queuePosi2.pop();
    // }

    // cout << "length : " << queuePosi2.size() << endl;

    if(timer[totCount] != 1){ // 현재방향으로 더 가야할 때
        return move(direction, totCount+1);
    }
    else{ // 방향 전환을 해야할 때
        if(direcQueue.size() > 0){ // 앞으로 가야할 방향이 남아있을 때
            char nowDirect = direcQueue.front();
            // cout << "방향 전환 now : " << direction << " | after : " << nowDirect << endl;
            direcQueue.pop();
            return move(changeDirection(direction, nowDirect), totCount+1);
        }
        else{ // 현재 방향으로 계속 가야할때
            return move(direction, totCount+1); 
        }
    }
}


int main(){
    cin >> n >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = 0;
        }
    }
    int t1,t2;
    char c1;
    for(int i=0;i<c;i++){
        cin >> t1 >> t2;
        t1--;t2--;
        // t2
        map[t1][t2] = 1;
    }
    cin >> c;
    for(int i=0;i<10001;i++){
        timer[i] = 0;
    }
    for(int i=0;i<c;i++){
        cin >> t1 >> c1;
        // t1--; c1--;
        timer[t1] = 1;
        direcQueue.push(c1);
        
    }

    Posi posi;
    posi.i = 0;
    posi.j = 0;
    queuePosi2.push(posi);
    map[0][0] = 2;
    cout << move(1,1);
}