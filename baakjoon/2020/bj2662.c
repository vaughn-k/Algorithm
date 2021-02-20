#include <stdio.h>

int com[21][301] = {0};
int dp[21][301] = {0};
int main(){
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&com[j][i]);
        }
    }


}

int money(int n, int m){
    int i,j,k;
    int max = -1;
    for(i=0;i<n;i++){
        for(j=0;j<=m;j++){ // j원
            if(i == 0){
                dp[i][j] = com[i][j];
            }
            else{   
                for(k=0;k<j;k++){
                    
                }
            }
        }
    }
}