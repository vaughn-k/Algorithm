#include <iostream>

using namespace std;

int n;
int t[1500000];
int p[1500000];
int d[1500000]; 
int tot = 0;
// d[i]일부터 얻을 수 있는 최대 이익

// dfs(i) = i번째부터 얻을 수 있는 최대 이익
int dfs(int now){
    tot++;
    int out1,out2;
    if(now >= n){
        return 0;
    }
    if(d[now] != -1){
        return d[now];
    }
    // 이번에 상담 받을때
    if(t[now]+now <= n){
        out1 = dfs(now + t[now]) + p[now];
    }
    else{
        out1 = 0;
    }
    // 이번에 상담 안받을때
    out2 = dfs(now+1);
    d[now] = max(out1,out2);
    return max(out1,out2);
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t[i] >> p[i];
        d[i] = -1;
    }
    cout << dfs(0) << endl;
    cout << tot;

}