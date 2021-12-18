/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.18

소요시간 : 20m

문제명 - 백준 1826 - 연료 채우기
   
알고리즘
    - 그리디
    - 우선순위큐(2개 전달형)
    - 거리제한 + 최소로 주유소 선택

문제개요
    n개의 주유소가 있고 각 주유소마다 출발지부터 거리(dist)와 방문시 채울수 있는 연료(fuel)가
    있다. 

    0부터 l까지 p연료를 가지고 출발할때 최소의 주유소만 들려서 도착하게 할때 그 최솟값 도출

    현재 가지고 있는 연료로 갈수있는 주유소들을 큐에 넣고, 아직 도착을 못했다면 그 큐에서 가장 
    많은 연료를 주입할수있는 주유소를 선택한다.


*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,l,p;


struct Station{
    int dist;
    int fuel;
};

struct cmpDist{
    bool operator()(Station a, Station b){
        return a.dist > b.dist;
    }
};

struct cmpFuel{
    bool operator()(Station a, Station b){
        return a.fuel < b.fuel;
    }
};

priority_queue<Station, vector<Station>, cmpDist> list; // 전체 주유소
priority_queue<Station, vector<Station>, cmpFuel> posible; // 현재 기름으로 갈수있는 주유소들

int main(){
    
    Station station;
    int tmp1,tmp2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        station.dist = tmp1;
        station.fuel = tmp2;
        list.push(station);
    }
    cin >> l >> p;

    int position = p; // 현재위치
    int tot = 0;
    while(position < l){ // 현재까지의 기름으로 도착지에 못갈을때
        while(list.size() > 0){
            if(list.top().dist <= position){ // 현재 기름으로 갈수있는 주유소들 따로 분류
                posible.push(list.top());
                list.pop();
            }
            else{
                break;
            }
        }
        if(posible.size() == 0){ // 위에서 현재 기름으로 갈수있는 주유소들을 모두 posible 큐에 넣었는데
        // 이 큐가 비어있다는 것은 모든 갈수있는 주유소를 다 가도 목적지에 못간다는 의미이다.
            cout << -1;
            return 0;
        }
        position = position + posible.top().fuel;
        posible.pop();
        tot++;
    }
    cout << tot;
}