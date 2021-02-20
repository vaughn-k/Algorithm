#include <stdio.h>

#define INF 987654321;

int book[501];
int dp[501][501];
int n;
int file(int s, int e);
int minimum(int x, int y);

int main(){
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&book[j]);
        }
        file(0,n-1);
    }

}

int file(int s, int e){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            printf("(%d %d)",j,j+i);//(j,j+i)
            if(i == 0){
                dp[j][i+j] = book[i+j];
            }
            if(i == 1){
                dp[j][i+j] = book[i+j] + book[j];
            }
            else{
                dp[j][i+j] = minimum(2*dp[j][i+j-1]+book[j+i],2*dp[j+1][i+j])+book[j]
                ;
            }
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }


}

int minimum(int x, int y){
    return x < y ? x : y;
}