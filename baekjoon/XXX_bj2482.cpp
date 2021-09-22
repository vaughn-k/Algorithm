#include <iostream>

using namespace std;

int n,k;
int save[1001][1001];
int mod = 1000000003;

int color(int sn, int sk){
    if(sn == sk){
        return 1;
    }
    if(sn < sk){
        return 0;
    }
    int ans;
    if(save[sn][sk] != -1){
        return save[sn][sk];
    }
    ans = color(sn-1,sk) + (color(sn-2,sk) * (sk-1))%mod;
    ans = ans%mod;
    save[sn][sk] = ans;
    return ans;
}

int main(){
    cin >> n >> k;
    int ans;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            save[i][j] = -1;
        }
    }
    ans = color(n,k);
    cout << ans;
}