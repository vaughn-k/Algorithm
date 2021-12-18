#include <stdio.h>

// 14m
// lis 알고리즘을 이용하는 문제이다.
// 문제를 보고 lis를 떠올리는게 중요한 문제였다

int arr[201];
int dp[201];

int lis(int n);
int lower(int target, int len);

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("%d",n-lis(n));
}

int lis(int n){
    int i,j;
    int length;
    length = 1;
    dp[0] = arr[0];
    for(i=1;i<n;i++){
        length = lower(arr[i],length);
    }
    return length;
}

int lower(int target, int len){ //최종 dp길이를 리턴
    int s,e,m;
    s = 0;
    e = len-1;
    m = (s+e)/2;
    if(dp[e] < target){
        dp[e+1] = target;
        return len+1;
    }
    while(1){
        if(e-s <= 1){
            if(target < dp[s]){
                dp[s] = target;
            }
            else{
                dp[e] = target;
            }
            return len;
        }
        if(dp[m] < target){
            s = m;
            m = (s+e)/2;
        }
        else{
            e = m;
            m = (s+e)/2;
        }
    }
}