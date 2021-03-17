/*
백준 2212 - 센서

알고리즘 
    - 그리디
    - 우선순위큐

문제개요
    직선상에 n개의 센서가 주어지고 k개의 집중국을 세워 각 집중국이 담당해야할 수신영역의 합을 최소로 해야할때 그값은?

    각 센서들의 앞뒤 거리를 내림차순으로 정렬하여 앞의 k-1개를 제외한 나머지 거리들의 합을 구해주면 된다.

    2개 이상의 집중국을 세울때 두 집중국 사이의 두 센서의 거리를 하나 무시할수 있기때문에 그 값이 최대한 커야 최종 수신거리를 줄일수 있다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k;
int dt[10001];

priority_queue<int,vector<int>,greater<int> > pq1;
priority_queue<int,vector<int>,less<int> > pq2;

int main(){
    int tmp;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        pq1.push(tmp);
    }
    int before,now;
    now = pq1.top();
    pq1.pop();
    while(pq1.size() > 0){
        before = now;
        now = pq1.top();
        pq1.pop();

        pq2.push(abs(now-before));
    }
    int tot = 0;
    while(pq2.size() > 0){
        if(k > 1){
            k--;
        }
        else{
            tot = tot + pq2.top();
        }
        pq2.pop();
    }
    cout << tot;
}
