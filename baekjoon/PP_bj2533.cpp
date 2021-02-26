/*
3h++

백준 2533 - 사회망 서비스(SNS)

그래프 + dp

문제 개요 : 1~n개의 정점이 트리구조로 주어지고 모든 정점은 각각 얼리어답터이거나 아니다.

자신을 제외한 주변 모든 정점이 얼리어답터면 본인은 새로운 아이디어를 받아들인다.

가장 최소의 얼리어답터로 모든사람들이 새로운 아이디어를 받아들이게 하기 위한 최소 얼리어답터수 출력.

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int> > v;
int vt[1000002];
int dp[1000002][2];

int run(int now, int type){
    // cout << "in now : " << now << endl;
    // now 정점을 type으로 했을때 최소값 리턴
    // 0 : 일반인 / 1 : 얼리어답터
    int next;
    int r1;
    int r2;
    int total = 0;
    int check = 0;

    if(dp[now][type] != -1){
        return dp[now][type];
    }

    for(int i=0;i<v[now].size();i++){
        next = v[now][i];
        r1 = 99999999;
        r2 = 99999999;
        if(vt[next] == -1){ // 방문 전
            vt[next] = 1;
            if(type == 1){
                r1 = run(next,0);
            }
            r2 = run(next, 1);
            vt[next] = -1;
        }
        if(!(r1 >= 99999999 && r2 >= 99999999)){
            if(r1 < r2){
                total = total + r1;
            }
            else{
                total = total + r2;
            }
        }
    }

    if(type == 1){
        total = total + 1;
    }
    dp[now][type] = total;
    return total;
}

int main(){
    int x,y;
    cin >> n;
    for(int i=0;i<=n;i++){
        v.push_back(vector<int>());
        vt[i] = -1;
        for(int j=0;j<2;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<n-1;i++){
        cin >> x;
        cin >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vt[1] = 1;
    int ans1, ans2;
    ans1 = run(1,0);
    for(int i=0;i<=n;i++){
        vt[i] = -1;
    }
    vt[1] = 1;
    ans2 = run(1,1);
    cout << min(ans1,ans2);
} 


