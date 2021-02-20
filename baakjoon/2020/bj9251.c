#include <stdio.h>

char arr[1001]; 
char arr2[1001];
int dp[1002][1002] = {0};
int max(int a, int b);
int main(){
    scanf("%s",arr);
    scanf("%s",arr2);
    int i,j;
    for(i=0;i<strlen(arr)+1;i++){
        for(j=0;j<strlen(arr2)+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(arr[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);    
            }
        }
    }
    printf("%d",dp[strlen(arr)][strlen(arr2)]);
}

int max(int a, int b){
    if(a < b){
        return b;
    }
    else{
        return a;
    }
}