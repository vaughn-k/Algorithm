#include <stdio.h>
#include "array.h"

int arr[100001] = {0};
int dp[51][100001] = {0};
int kdp(int n, int k);

int main(){
    int n,k,i,j;
    int *arr2 = &arr[0];
    scanf("%d %d",&n,&k);
    // for(i=0;i<n;i++){
    //     scanf("%d",&arr[i]);
    // }

    for(i=0;i<n;i++){
        arr[i] = i+1;
    }
    shuffle(n,arr2);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    

    kdp(n,k);

    int total = 0;
    for(i=0;i<n;i++){
        total = (total + dp[k-1][i])%5000000;
    }
    printf("%d",total);

}

int kdp(int n, int k){
    int i,j,r;
    for(i=0;i<k+1;i++){
        for(j=0;j<n;j++){
            if(i == 0){
                dp[i][j] = 1; 
            }
            else{
                for(r=j+1;r<n;r++){
                    if(arr[j] < arr[r]){
                        dp[i][j] = (dp[i][j] + dp[i-1][r])%5000000;
                    }
                }
            }
        }
    }
    return 0;
}