/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.09.22

소요시간 : 12m

문제명 - 백준 2186 문자판
   
알고리즘
    - dfs순환 + 메모이제이션(dp)(변수3개)
    - 상하좌우 * k 번 순환

문제개요

    문자들이 주어지고, 만들어야하는 문자열이 주어진다.

    그리고 한칸을 선택해 시작해서 상하좌우 k칸을 움직여서 target문자열을 만드는 경우의 수를 출력

    다른 부분은 여타 nxm dp문제와 다를것이 없었는데 다만 기존에는 상하좌우 한칸씩만 이동할 수 있었는데
    이 문제에서는 상하좌우 k칸씩 이동할 수 있어서, 가중치를 주어서 순환하였다.

   
*//////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,m,k;
vector<string> v;
string target;
int di[] = {0,0,-1,1};
int dj[] = {1,-1,0,0};
int save[101][101][81];

int dfs(int ni, int nj, int find){
    if(find == target.size()){
        return 1;
    }
    int goi,goj;
    int tot = 0;
    if(save[ni][nj][find] != -1){
        return save[ni][nj][find];
    }
    for(int p=0;p<4;p++){
        for(int mul=1;mul<=k;mul++){
            goi = ni + di[p] * mul;
            goj = nj + dj[p] * mul;
            if(goi >= 0 && goj >= 0 && goi < n && goj < m){
                if(v[goi][goj] == target[find]){
                    tot += dfs(goi,goj,find+1);
                }
            }
        }
    }
    save[ni][nj][find] = tot;
    return tot;
}

int main(){
    string s;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            for(int q=0;q<81;q++){
                save[i][j][q] = -1;
            }
        }
    }
    cin >> target;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == target[0]){
                ans += dfs(i,j,1);
            }
        }
    }
    cout << ans;
}
