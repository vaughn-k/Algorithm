/*
30m

그래프 - bfs

그래프가 주어지고 루트(1번정점)가 주어져서 2번정점부터 자신의 부모정점을 출력하는 문제

bfs로 풀었지만 dfs로도 상관없을듯 싶다. 

다만 n의 최대값이 10만인데 출력을 endl로해서 시간초과가 남.

앞으로 출력시 endl 대신 '\n' 사용할것
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int> > v;
int pa[100002];
queue<int> q1;
queue<int> q2;

void bfs(){
    q1 = q2;
    while(q2.size() > 0){q2.pop();}

    int now;
    while(q1.size() > 0){
        now = q1.front();
        q1.pop();
        for(int i=0;i<v[now].size();i++){
            if(pa[v[now][i]] == 0){
                pa[v[now][i]] = now;
                q2.push(v[now][i]);
            }
        }
    }
    if(q2.size() > 0){
        bfs();
    }
}

int main(){
    int tmp1,tmp2;
    cin >> n;
    for(int i=0;i<=n;i++){
        pa[i] = 0;
        v.push_back(vector<int>());
    }
    for(int i=0;i<n-1;i++){
        cin >> tmp1;
        cin >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    q2.push(1);
    bfs();

    for(int i=2;i<=n;i++){
        cout << pa[i] << '\n';
    }
}