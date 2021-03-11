/*
20m

백준 1715 - 카드 정렬하기

알고리즘
    - 그리디
    - 우선순위큐로 정렬후 top() 2개씩 합해서 total값 구하기
    
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> v;

priority_queue<int,vector<int>,greater<int> > pq;

int main(){
    int tmp, now1, now2, total;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        pq.push(tmp);
    }
    total = 0;
    while(pq.size() > 1){
        now1 = pq.top();
        pq.pop();
        now2 = pq.top();
        pq.pop();
        total = total + now1 + now2;
        pq.push(now1+now2);
    }
    cout << total;
}