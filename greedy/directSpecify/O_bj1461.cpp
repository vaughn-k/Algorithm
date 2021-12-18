/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.18

소요시간 : 40m

문제명 - 백준 1461 - 도서관
   
알고리즘
    - 그리디
    - 우선순위큐

문제개요
    n개의 양,음의 정수로 책 위치가 주어지고 m개의 책을 들고 다닐수 있고, 마지막 책을 놓은후 돌아
    올 필요없을때 가장 짧은 거리로 모든 책을 위치로 가져다놓는 거리는?

    양수끼리, 음수끼리 우선순위 큐로 정렬한후 처음원소를 빼고 total에 더하고 m-1개는 무시하는
    과정을 반복한후 전체합을 2배한다. (왕복이므로) 
    
    그리고 문제의 조건에 따라 마지막 책은 양수,음수중 가장 멀리가야하는 책의 거리를 한번 빼서 
    최종 답 도출

*//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pqMinus;
priority_queue<int, vector<int>, less<int> > pqPlus;

int n,m;

int main(){
    int tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp > 0){
            pqPlus.push(tmp);
        }
        else{
            pqMinus.push(tmp);
        }
    }

    int tot = 0;
    int cnt = m;

    int maxi;
    if(pqMinus.size() == 0){
        maxi = pqPlus.top();
    }
    else if(pqPlus.size() == 0){
        maxi = abs(pqMinus.top());
    }
    else{
        maxi = max(abs(pqMinus.top()),pqPlus.top());
    }
    while(pqMinus.size() > 0){
        if(cnt == m){
            // cout << pqMinus.top() << endl;
            tot = tot + abs(pqMinus.top());
        }
        cnt--;
        if(cnt == 0){
            cnt = m;
        }
        pqMinus.pop();
    }
    cnt = m;
    while(pqPlus.size() > 0){
        if(cnt == m){
            // cout << pqPlus.top() << endl;
            tot = tot + abs(pqPlus.top());
        }
        cnt--;
        if(cnt == 0){
            cnt = m;
        }
        pqPlus.pop();
    }
    tot = tot * 2 - maxi;
    cout << tot;
}