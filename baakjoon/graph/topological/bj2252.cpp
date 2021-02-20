// 30m outofbound 에러나옴

// 그래프 위상정렬

// 이문제 역시  1916 번처럼 인덱스가 1부터 시작할때 벡터생성을 하나 적게해서 bounds에러가 났다.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n,m;
vector<vector<int> > v;
stack<int> s;
int visited[32005];

void dfs(int now){
    visited[now] = 1;
    int len = v[now].size();
    for(int i=0;i<len;i++){
        if(visited[v[now][i]] == 0){
            dfs(v[now][i]);

        }
    }
    s.push(now);
}


void dfs_start(){
    for(int now = 1; now <= n; now++){
        if(visited[now] == 0){
            dfs(now);
        }
    }
}

void print_stack(){
    while(s.size() > 0){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){
    cin >> n;
    cin >> m;
    int a,b;
    for(int i=0; i<=n; i++){
        v.push_back(vector<int>());
        visited[i] = 0;
    }
    for(int i=0; i<m; i++){
        cin >> a;
        cin >> b;
        v[a].push_back(b);
    }

    dfs_start();
    print_stack();
}