#include <stdio.h>

typedef struct LIGHT{
    int po, w;
} Light;

Light lw[1001] = {};
long long dp[1001][1001][2] = {};
int n,m;



int fw(int le, int ri, int now, int amount);

int main(){
    int i;
    scanf("%d %d",&n,&m);
    m--;
    for(i=0;i<n;i++){
        scanf("%d %d",&lw[i].po,&lw[i].w);
    }
    int left,right;
    left = m-1; 
    right = m+1;
    printf("%d",fw(left,right,m,0));
}

int fw(int le, int ri, int now, int amount){
    // printf("le : %d, ri : %d, now : %d\n",le,ri,now);
    long long minimum,tmp1,tmp2;
    if(le == -1 && ri == n){
        return 0;
    }
    if(le == -1){
        // printf("w : %d\n",lw[ri].w * (amount+(lw[ri].po-lw[now].po)));
        minimum = fw(le,ri+1,ri,amount+(lw[ri].po-lw[now].po)) + lw[ri].w * (amount+(lw[ri].po-lw[now].po));
        return minimum;
    }
    else if(ri == n){
        // printf("w : %d\n",lw[le].w * (amount+(lw[now].po-lw[le].po)));
        minimum = fw(le-1,ri,le,amount+(lw[now].po-lw[le].po)) + lw[le].w * (amount+(lw[now].po-lw[le].po));
        return minimum;
    }
    else{
        if(le+1 == now){
            if(dp[le][ri][0] != 0){
                printf("ok\n");
                return dp[le][ri][0];
            }
        }
        else{
            if(dp[le][ri][1] != 0){
                printf("ok\n");
                return dp[le][ri][1];
            }
        }
        // printf("w : %d\n",lw[le].w * (amount+(lw[now].po-lw[le].po)));
        tmp1 = fw(le-1,ri,le,amount+(lw[now].po-lw[le].po)) + lw[le].w * (amount+(lw[now].po-lw[le].po));
        // printf("w : %d\n",lw[ri].w * (amount+(lw[ri].po-lw[now].po)));
        tmp2 = fw(le,ri+1,ri,amount+(lw[ri].po-lw[now].po))+ lw[ri].w * (amount+(lw[ri].po-lw[now].po));
        if(tmp1 < tmp2){
            minimum = tmp1;
        }
        else{
            minimum = tmp2;
        }
    }
    if(le+1 == now){
        dp[le][ri][0] = minimum;
    }
    else{
        dp[le][ri][1] = minimum;
    }
    return minimum;
}

