#include <iostream>

using namespace std;

int n,k;
int save[201][201];

int dfs(int nn, int kk){
    if(nn == 0 || kk == 1){
        return 1;
    }
    if(save[nn][kk] != -1){
        return save[nn][kk];
    }
    int tot = 0;
    for(int i=0;i<=nn;i++){
        tot = tot + dfs(nn-i,kk-1);
        tot = tot%1000000000;
    }
    save[nn][kk] = tot;
    return tot;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<201;i++){
        for(int j=0;j<201;j++){
            save[i][j] = -1;
        }
    }
    int answer;
    answer = dfs(n,k);
    cout << answer;
}