#include <stdio.h>

// 변수의 값이 21억을 초과하므로 long long 으로 바꿔주었는데 정작 마지막 출력파트에서 int변수로 받아버려서 틀렸다;
// longlong은 자주쓰지않는만큼 써야할 일이 생기면 각별히 주의해야한다.
// 또한 warning으로 뜬 문구라고해서 넘어가지말고 주의깊게 보자 

int fix[101][4] = {0};
long long dp[101][101] = {0};
long long go(int n, int m, int k,int now_n, int now_m, int bn, int bm);

int main(){
    int n,m,k,i,j;
    scanf("%d %d",&n,&m);
    scanf("%d",&k);
    n++;m++;
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            dp[i][j] = -1;
        }
    }
    for(i=0;i<k;i++){
        scanf("%d %d %d %d",&fix[i][0],&fix[i][1],&fix[i][2],&fix[i][3]);
    }
    long long ans;
    ans = go(n,m,k,0,0,0,0);
    printf("%lld\n",ans);
}


long long go(int n, int m, int k,int now_n, int now_m, int bn, int bm){
    long long total;
    long long tmp1,tmp2;
    int i;
    for(i=0;i<k;i++){
        if((bn==fix[i][0] && bm==fix[i][1] && now_n==fix[i][2] && now_m==fix[i][3])||(bn==fix[i][2] && bm==fix[i][3] && now_n==fix[i][0] && now_m==fix[i][1])){
            return 0;
        }
    }
    if(now_n == n-1 && now_m == m-1){
        return 1;
    }
    if(now_n >= n || now_m >= m){
        return 0;
    }
    if(dp[now_n][now_m] != -1){
        return dp[now_n][now_m];
    }
    tmp1 = go(n,m,k,now_n,now_m+1,now_n,now_m);
    tmp2 = go(n,m,k,now_n+1,now_m,now_n,now_m);
    total = tmp1 + tmp2;
    dp[now_n][now_m] = total;
    return total;
}