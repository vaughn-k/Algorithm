/*
1h+

백준 10775 - 공항

알고리즘
    그리디
    
문제개요
    g개의 공항이 있고, p개의 비행기가 순서대로 도착하는데 각 비행기마다 g이하의 번호가 주어지는데 이는
    1~g 번까지 중에 하나의 공항에 도킹할수 있음을 의미한다. 이때 몇개의 비행기까지 도킹할수 있는지 출력

    만약 어떤 비행기가 1~k 까지 공항 중에 하나에 도킹해야한다면, 어디부터 도킹하는것이 최대한 많은 비행기들을 도킹 시킬 수 있을까?
    자신이 도킹할수 있는 최대 공항번호가 클수록 최대한 큰쪽에 도킹을 하는것이 greedy한 접근이라고 볼수있다.
    단적인 예를 들면 만약 1번공항까지 도킹할수 있는 비행기 a와, 5번공항까지 도킹할수 있는 비행기 b가 있을때 
    만약 b비행기가 먼저와서 1번공항에 도킹해버리면 a비행기는 도킹할수 없다. 
    
    더 높은 공항번호에 도킹할수 있는 비행기들이 더 적고 선택권이 많기때문에 최대한 낮은 곳에 도킹할수 밖에 없는 비행기 들을 위해
    항상 자신의 가능한 공항번호중 가장 큰 공항에 도킹하는것이 greedy하다.

    또한 이대로 설계한다면 모두 같은 최대값을 가졌을때 최악의 시간복잡도는 n^2 이므로 이를 줄이기 위해 주어진 번호별로
    자신이 어디까지 움직여야 도킹이 가능한지를 저장해놓고 해당값을 갱신해가며 중복 순회를 낮추게되면 시간복잡도를 낮출수 있다.
*/

#include <iostream>

using namespace std;

int g,p;
int visited[100002];
int d[100002];
int air[100002];

int findEmpty(int x){
    int jump;
    jump = d[x];
    while(visited[jump] != 0){
        jump--;
        if(jump == 0){
            return -1;
        }
    }
    visited[jump] = 1;
    d[x] = jump;
    return x;
}

int main(){
    cin >> g >> p;
    
    for(int i=1;i<=g;i++){
        visited[i] = 0;
        d[i] = i;
    }
    for(int i=0;i<p;i++){
        cin >> air[i]; 
    }
    int now,nowGate;
    int count = 0;
    for(int i=0;i<p;i++){
        now = air[i];
        nowGate = findEmpty(now);
        if(nowGate == -1){
            cout << count;
            return 0;
        }
        else{
            count++;
        }
    }
    cout << count;
    return 0;
}
