/*
56m

일반적인 1012 처럼 구역나눠서 그래프 총 개수 구하는 문제인 줄 알고 쉽게 해결할줄 알았는데

이문제는 행렬의 크기가 1000*999/2 크기로 약 1000000만개의 행렬이므로 메모리 초과가 발생했다.

따라서 행렬을 이용하지 않고 벡터를 이용하여 간선의 정보만을 가지고 탐색을 해야했다.

*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int t,m,n,k;
int Count = 0;
vector<vector<int> > v;
int graph[1001];
// graph[x] = 1 -> 아직 방문 안한 상태
// graph[x] = 0 -> 방문 한 상태



void sub_loop(int now){
    for(int i=0;i<v[now].size();i++){
        if(graph[v[now][i]] == 1){
            graph[v[now][i]] = 0;
            sub_loop(v[now][i]);
        }
    }
}

void main_loop(){
    for(int i=0;i<n;i++){
        if(graph[i] == 1){
            Count++;
            graph[i] = 0;
            sub_loop(i);
        }
    }
}

int main(){
    int tmp1, tmp2;
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        v.push_back(vector<int>());
        graph[i] = 1;
    }

    for(int i=0;i<m;i++){
        cin >> tmp1;
        cin >> tmp2;
        v[tmp1-1].push_back(tmp2-1);
        v[tmp2-1].push_back(tmp1-1);
    }

    main_loop();

    cout << Count;
}
