#include <iostream>

using namespace std;

int n;
int t[1500001];
int p[1500001];
int d[1500001]; 
int tot = 0;
// d[i]일부터 얻을 수 있는 최대 이익

// dfs(i) = i번째부터 얻을 수 있는 최대 이익
int find(int x){
    tot++;
    if(x > n){
        return 0;
    } 
    if(d[x] != -1) {
        return d[x];
    }
    d[x] = max(find(x + t[x]) + p[x], find(x + 1));
    return d[x];
}

// int dfs(int now){
//     int out1,out2;
//     if(now >= n){
//         return 0;
//     }
//     if(d[now] != -1){
//         return d[now];
//     }
//     // 이번에 상담 받을때
//     if(t[now]+now <= n){
//         out1 = dfs(now + t[now]) + p[now];
//     }
//     else{
//         out1 = 0;
//     }
//     // 이번에 상담 안받을때
//     out2 = dfs(now+1);
//     d[now] = max(out1,out2);
//     return max(out1,out2);
// }

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> p[i];
        d[i] = -1;
    }

    for(int i = 1 ; i <=  n ; i ++){
        if(i + t[i] - 1> n) p[i] =0;
    }
    cout << find(1) << endl;
    cout << tot; 

}