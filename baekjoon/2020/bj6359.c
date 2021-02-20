// 18m

#include <stdio.h>

int room[101][101] = {0};
int dp[101] = {0};

int main(){
    int t,i,j,k,tmp,total;
    scanf("%d",&t);

    for(i=1;i<101;i++){
        total = 0;
        for(j=1;j<101;j++){
            if(i==1){
                room[1][j] = 1;
            }
            else if(j%i == 0){
                room[i][j] = room[i-1][j] * (-1);
            }
            else{
                room[i][j] = room[i-1][j];
            }
        }
    }

    for(i=1;i<101;i++){
        for(j=1;j<=i;j++){
            if(room[i][j] == 1){
                dp[i] = dp[i] + room[i][j];
            }
        }
    }

    for(i=0;i<t;i++){
        scanf("%d",&tmp);
        printf("%d\n",dp[tmp]);
    }
}