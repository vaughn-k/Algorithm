/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.09.22

소요시간 : 10m

문제명 - 백준 15654 N과 M(5)

알고리즘
    - 백트레킹

문제개요
    n개의 숫자가 주어지고 그중 m개를 선택해서 만들수 있는 모든 수열 사전순으로 출력

    공용으로 누적해놓는 배열(save)을 선언해두고 dfs로 돌면서 방문한 곳은 visited로
    체크하며 방문해서 m개째 방문했을 때 한번에 프린트


*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;
int visited[9];
int save[9];

void print(){
    for(int i=0;i<m;i++){
        cout << save[i] << " ";
    }
    cout << '\n';
}

void dfs(int select, int index){
    save[index] = v[select];
    visited[select] = 1;

    if(index+1 == m){
        visited[select] = -1;
        print();
        return;
    }

    for(int i=0;i<n;i++){
        if(visited[i] == -1){
            dfs(i,index+1);
        }
    }
    visited[select] = -1;
    return;
}

int main(){
    int tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        visited[i] = -1;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        dfs(i,0);
    }
}