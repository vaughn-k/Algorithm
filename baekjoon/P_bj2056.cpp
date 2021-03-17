/*
30m

백준 2056 - 작업

알고리즘 
    - 그래프 순환 (dfs)
    - dp(1차원 메모이제이션)
    - 여러 컴포넌트(여러개의 루트)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t[10001];
int d[10001];
vector<vector<int> > v;
queue<int> root;

int dfs(int now){
    int maxi = 0;
    if(d[now] != -1){
        return d[now];
    }
    for(int i=0;i<v[now].size();i++){
        maxi = max(maxi,dfs(v[now][i]));
    }
    maxi = maxi + t[now];
    d[now] = maxi;
    return maxi;
}

int main(){
    int tmp,c;
    int n;
    cin >> n;
    for(int i=0;i<=n;i++){
        d[i] = -1;
        v.push_back(vector<int>());
    }
    for(int i=1;i<=n;i++){
        cin >> tmp >> c;
        t[i] = tmp;
        if(c == 0){
            root.push(i);
        }
        for(int j=0;j<c;j++){
            cin >> tmp;
            v[tmp].push_back(i);
        }
    }
    int ans = 0;
    while(root.size() > 0){
        ans = max(ans, dfs(root.front()));
        root.pop();
    }
    cout << ans;
}

/*
8
5 0
1 1 1
3 1 2
6 1 1
1 2 2 4
8 2 2 4
4 3 3 5 6
1000 0
*/