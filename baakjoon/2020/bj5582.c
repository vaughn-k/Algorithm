#include <stdio.h>
#include <stdlib.h>

// 18m; 
// lcs 알고리즘인줄 알았는데 이문제는 공통수열이 연속되어있어야한다.
// 오히려 더 쉬운데 해당 문자가 같을때마다 왼쪽 대각선값에서 1더해서 저장해주면 된다. 
// 점화식 : dp[i][j] = dp[i-1][j-1]+1;

char s[4001];
char q[4001];
int dp[4001][4001] = {0};
int lcs();
int max(int x, int y);

int main(){
    scanf("%s",&s);
    scanf("%s",&q);
    lcs();
}

int lcs(){
    int i,j;
    int n,m;
    int maximum = 0;
    n = strlen(s);
    m = strlen(q);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s[i] == q[j]){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j] > maximum){
                        maximum = dp[i][j];
                    }
                }
            }
        }   
    }
    // printf("\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    printf("%d",maximum);
}

int max(int x, int y){
    return x > y ? x : y;
}