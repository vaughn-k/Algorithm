#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dpp(int i, int j, int n, int m);
int max(int a,int b,int c,int d);

char maze[51][51];
int dp[51][51];
int check[51][51];
// -2 -> 방문x
// -1 -> 무한대

int main(){

    int n,m,i,j;
    char tmp[51];
    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++){
        scanf("%s",maze[i]);
    }

    for(i=0; i<n; i++){
        memset(dp[i],-1,sizeof(int)*m);
        memset(check[i],0,sizeof(int)*m);
    }

    // printf("dp\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("check\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",check[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("maze\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",maze[i][j]-48);
    //     }
    //     printf("\n");
    // }

    int answer;
    answer = dpp(0,0,n,m);
    printf("%d\n",answer);
    // 72-H
    // 48빼면 그수
    // printf("==== dp ====\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

}

int dpp(int i, int j, int n, int m){

    if(i < 0 || j < 0 || i > (n-1) || j > (m-1)){
        return 0;
    }
    if(maze[i][j] == 72){
        return 0;
    }
    if(check[i][j] == 0){
        check[i][j] = 1;
    }
    else{
        return -2;
    }
    int maximum = 0;
    int tmp1,tmp2,tmp3,tmp4;
    if(dp[i][j] != -1){
        check[i][j] = 0;
        return dp[i][j];
    }
    int mz = maze[i][j] - 48;
    tmp1 = dpp(i+mz,j,n,m);
    tmp2 = dpp(i,j+mz,n,m);
    tmp3 = dpp(i-mz,j,n,m);
    tmp4 = dpp(i,j-mz,n,m);
    if(tmp1 == -2 || tmp2 == -2 || tmp3 == -2 || tmp4 == -2){
        check[i][j] = 0;
        dp[i][j] = -2;
        return -2;
    }
    maximum = max(tmp1,tmp2,tmp3,tmp4)+1;
    dp[i][j] = maximum;
    check[i][j] = 0;
    return maximum;
}

int max(int a,int b,int c,int d){
    int top1,top2;
    if(a >= b){
        top1 = a;
    }
    else{
        top1 = b;
    }
    if(c >= d){
        top2 = c;
    }
    else{
        top2 = d;
    }
    if(top1 >= top2){
        return top1;
    }
    else{
        return top2;
    }
}