/* 3h++

****

쉽지않았던 문제였다.

그래프로 접근도 해보았지만 결국 dp임을 알았고 dp에서도 최소 거리를 구하는것은 비교적 먼저 도출했으나

각 사건별 경찰차 배치를 구하는 부분에서 많은 시간을 소모했다.

*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,w;
vector<pair<int,int> > p;
int store[1010][1010];
int police_store[1010][1010];
// 0 방문전

// 단 police1,2는 각각 -1, -2이며 한번이상 이동시 정상적인 0이상의 정수로 작용

int calculate_distance(int police, int target, int start){
    // start : 
    // 0 : 이상무
    // 1 : police가 1,1에 있다.
    // 2 : police가 n,n에 있다.
    int police_x,police_y,target_x,target_y;
    if(start == 1){
        police_x = 1;
        police_y = 1;
    }
    else if(start == 2){
        police_x = n;
        police_y = n;

    }
    else{
        police_x = p[police-1].first;
        police_y = p[police-1].second;
    }
    target_x = p[target-1].first;
    target_y = p[target-1].second;
    return abs(police_x-target_x) + abs(police_y-target_y);
}

int find_distance(int police1, int police2){
    /*
    두 경찰차가 현재 police1, police2 사건을 마지막으로 맡았을때
    이후로 최소 비용 출력
    ex) find_distance(3,5) 라고 하면
        이제 6번째 사건을 처리할 차례이므로
        첫번째 경찰차가 6번사건을 맡거나 = find_distance(6,5) + 3->6 거리
        두번째 경찰차가 6번사건을 맡아야한다. = find_distance(3,6) + 5->6 거리

        그리고 두 경찰차중 어느 경찰차가 움직여야하는 지를
        police_store[police1][police2]에 저장한다.(1 or 2)

    */


    // cout << police1 << " | " << police2 << endl;
    if(police1 == w || police2 == w){
        return 0;
    }

    int tmp1, tmp2, move;

    move = max(police1, police2) + 1;
    if(store[police1][police2] != -1){
        return store[police1][police2];
    }
    if(police1 == 0){
        tmp1 = find_distance(move,police2) + calculate_distance(police1, move, 1);
    }
    else{
        tmp1 = find_distance(move,police2) + calculate_distance(police1, move, 0);
    }
    if(police2 == 0){
        tmp2 = find_distance(police1,move) + calculate_distance(police2, move, 2);
    }
    else{
        tmp2 = find_distance(police1,move) + calculate_distance(police2, move, 0);
    }

    store[police1][police2] = min(tmp1,tmp2);

    if(tmp1 < tmp2){
        police_store[police1][police2] = 1;
    }
    else{
        police_store[police1][police2] = 2;
    }
    return min(tmp1,tmp2);
}

int main(){
    int tmp1,tmp2;
    cin >> n;
    cin >> w;
    for(int i=0;i<w;i++){
        cin >> tmp1;
        cin >> tmp2;
        p.push_back(make_pair(tmp1,tmp2));
    }

    for(int i=0;i<1010;i++){
        for(int j=0;j<1010;j++){
            store[i][j] = -1;
            police_store[i][j] = -1;
        }
    }

    cout << find_distance(0,0) << endl;

    int x = 0;
    int y = 0;
    
    for(int i=0;i<w;i++){
        cout << police_store[x][y] << endl;
        if(police_store[x][y] == 1){
            x = i+1;
        }
        else{
            y = i+1;
        }
    }
}