/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.04.01

소요시간 : 50m

문제명 - 백준 14891 톱니바퀴
   
알고리즘
    - 구현
    - 원형 구조에서 index 관리

문제개요
    이가 8개인 톱니바퀴 4개와 각 이마다 S,N극이 주어지고 
    k개의 회전 명령이 주어진다(회전명령 : i번째 톱니를 시계or반시계 방향으로)

    이때 주변 톱니중 붙어있는 이가 서로 다른극이면 그 톱니도 회전하게 된다.
    이때 k번 회전하였을때 12시방향 톱니에 따른 최종 점수 출력

    실제 메커니즘 자체는 어렵지 않았는데 연쇄적으로 톱니가 돌아가는 부분에서 오래걸렸다.
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> v;
vector<pair<int, int> > order;

int info[4][8];
int k;
int topNumber[] = {0,0,0,0};
int score[] = {1,2,4,8};

// void print(){
//     cout << "--------------" << endl;
//     for(int i=0;i<4;i++){
//         cout << topNumber[i] << " ";
//     }
//     cout << "--------------" << endl;
// }

pair<int,int> returnNum(int id){
    int left,right;
    left = topNumber[id] - 2;
    right = topNumber[id] + 2;
    if(left < 0){
        left = left + 8;
    }
    if(right > 7){
        right = right - 8;
    }
    // cout << "l r : " << left << " " << right << endl;
    return make_pair(v[id][left],v[id][right]);
}

void rotate(int id, int direction){
    // 1 : 시계, -1 : 반시계
    topNumber[id] = topNumber[id] - direction;
    if(topNumber[id] < 0){
        topNumber[id] = 7;
    }
    else if(topNumber[id] > 7){
        topNumber[id] = 0;
    }
}

void run(int index){
    // cout << "run : " << index << endl;
    pair<int,int> now;
    now = order[index];

    int turn[] = {0,0,0,0};
    turn[now.first] = now.second;

    pair<int,int> centerInfo;
    pair<int,int> sideInfo;

    int center;
    int side;
    int nowDirection;
    // 우측 톱니바퀴
    center = now.first;
    side = now.first+1;
    nowDirection = now.second;
    // cout << "now left running " << endl;
    while(side <= 3){
        centerInfo = returnNum(center);
        sideInfo = returnNum(side);
        if(centerInfo.second != sideInfo.first){ // 서로 다른 극
            turn[side] = nowDirection * -1;
            nowDirection = nowDirection * -1;

        }
        else{
            break;
        }
        center++;
        side++;
    }

    // cout << "now right running " << endl;
    // 좌측 톱니바퀴
    center = now.first;
    side = now.first-1;
    nowDirection = now.second;

    while(side >= 0){
        centerInfo = returnNum(center);
        sideInfo = returnNum(side);
        if(centerInfo.first != sideInfo.second){ // 서로 다른 극
            turn[side] = nowDirection * -1;
            nowDirection = nowDirection * -1;
        }
        else{
            break;
        }
        center--;
        side--;
    }

    // cout << "left right end " << endl;
    for(int i=0;i<4;i++){
        if(turn[i] != 0){
            rotate(i,turn[i]);
        }
    }
}

int main(){
    int number,rotate;
    string s;
    for(int i=0;i<4;i++){
        cin >> s;
        v.push_back(s);
    }
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> number >> rotate;
        number--;
        order.push_back(make_pair(number,rotate));
    }

    for(int i=0;i<k;i++){
        run(i);
        // print();
    }

    int tot = 0;
    // cout << " now?" << endl;
    for(int i=0;i<4;i++){
        if(v[i][topNumber[i]] == '1'){
            tot += score[i];
        }
    }
    cout << tot;
}