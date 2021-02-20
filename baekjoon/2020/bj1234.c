#include <stdio.h>

typedef struct COLOR{
    int r,g,b;
}Color;

int rr;
int gg;
int bb;
int type[11] = {0,1,2,3,2,1,4,1,2,3,2};
// 0 n=0
// 1 한가지만 가능
// 2 한가지 혹은 두가지가능
// 3 한가지 혹은 세가지가능
// 4 1,2,3가지 모두 가능

long long dp[11][101][101][101] = {0};
int main(){
    int n,i;
    scanf("%d",&n);
    scanf("%d",&rr);
    scanf("%d",&gg);
    scanf("%d",&bb);

}

int count(int n){
    int i;
    int r,g,b;
    for(i=n;i>=1;i--){
        if(i == n){
            if(type[n] == 1){
                if(rr >= 1){
                    dp[i][1][0][0] = 1;
                }
                if(gg >= 1){
                    dp[i][0][1][0] = 1;
                }
                if(bb >= 1){
                    dp[i][0][0][1] = 1;
                }
            }
            if(type[n] == 2 || type[n] == 4){
                if((i/2 <= rr)&&(i/2 <= bb)){ // 두가지 색 가능한지 확인
                    dp[i][i/2][0][i/2] = comb(i,i/2);
                }
                if((i/2 <= bb)&&(i/2 <= gg)){
                    dp[i][0][i/2][i/2] = comb(i,i/2);
                }
                if((i/2 <= gg)&&(i/2 <= rr)){
                    dp[i][i/2][i/2][0] = comb(i,i/2);
                }
                if(i<=rr){ // 한가지 색 가능한지 확인
                    dp[i][i][0][0] = 1;
                }
                if(i<=gg){ // 한가지 색 가능한지 확인
                    dp[i][0][i][0] = 1;
                }
                if(i<=bb){ // 한가지 색 가능한지 확인
                    dp[i][0][0][i] = 1;
                }
            }
            if(type[n] == 3 || type[n] == 4){
                if((i/3 <= rr)&&(i/3 <= bb)&&(i/3 <= gg)){
                    if(i == 3){
                        dp[i][i/3][i/3][i/3] = 1;
                    }
                    else if(i == 6){
                        dp[i][i/3][i/3][i/3] = fac(6)/(fac(3)*fac(3));
                    }
                    else{
                        dp[i][i/3][i/3][i/3] = fac(9)/(fac(3)*fac(3)*fac(3));
                    }
                }
            }
        }
        else{   
            for(r=0;r<=rr;r++){
                for(g=0;g<=gg;g++){
                    for(b=0;b<=bb;b++){
                        if(dp[i][r][g][b] != 0){
                            if(type[n] == 1){
                                if(rr >= 1){
                                    dp[i][1][0][0] = 1;
                                }
                                if(gg >= 1){
                                    dp[i][0][1][0] = 1;
                                }
                                if(bb >= 1){
                                    dp[i][0][0][1] = 1;
                                }
                            }
                            if(type[n] == 2 || type[n] == 4){
                                if((i/2 <= rr)&&(i/2 <= bb)){ // 두가지 색 가능한지 확인
                                    dp[i][i/2][0][i/2] = comb(i,i/2);
                                }
                                if((i/2 <= bb)&&(i/2 <= gg)){
                                    dp[i][0][i/2][i/2] = comb(i,i/2);
                                }
                                if((i/2 <= gg)&&(i/2 <= rr)){
                                    dp[i][i/2][i/2][0] = comb(i,i/2);
                                }
                                if(i<=rr){ // 한가지 색 가능한지 확인
                                    dp[i][i][0][0] = 1;
                                }
                                if(i<=gg){ // 한가지 색 가능한지 확인
                                    dp[i][0][i][0] = 1;
                                }
                                if(i<=bb){ // 한가지 색 가능한지 확인
                                    dp[i][0][0][i] = 1;
                                }
                            }
                            if(type[n] == 3 || type[n] == 4){
                                if((i/3 <= rr)&&(i/3 <= bb)&&(i/3 <= gg)){
                                    if(i == 3){
                                        dp[i][i/3][i/3][i/3] = 1;
                                    }
                                    else if(i == 6){
                                        dp[i][i/3][i/3][i/3] = fac(6)/(fac(3)*fac(3));
                                    }
                                    else{
                                        dp[i][i/3][i/3][i/3] = fac(9)/(fac(3)*fac(3)*fac(3));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int comb(n,k){
    return fac(n)/(fac(n-k)*fac(k));
}

int fac(n){
    int i;
    int ans = 1;
    for(i=1;i<=n;i++){
        ans = ans*i;
    }
    return ans;
}