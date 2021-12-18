#include <stdio.h>
#include <stdlib.h>

int dynamic_coin(int coin[], int answer[], int n, int k); // k - now_k

int main(){
    int i,j,k,n;
    int coin[10001];
    int answer[10001];
    int ans;

    scanf("%d",&n);
    scanf("%d",&k);
    for(i=1;i<n+1;i++){
        scanf("%d",&coin[i]);   
    }

    for(i=1;i<n+1;i++){
        answer[i] = 0;   
    }

    ans = dynamic_coin(coin, answer, n, k);
    if(ans >= 100000){
        printf("%d",-1);
    }
    else{
        printf("%d",ans);
    }
}


int dynamic_coin(int coin[], int answer[], int n, int k){ // k - now_k
    // printf("a\n");/
    int min = 100000;
    int tmp;
    int i;
    if(k == 0){
        return 0;
    }
    else{
        for(i=1;i<n+1;i++){
            if(k-coin[i] >= 0 && answer[k-coin[i]] != 100000){
                if(answer[k-coin[i]] != 0){
                    tmp = 1 + answer[k-coin[i]];
                }
                else{
                    tmp = 1 + dynamic_coin(coin, answer, n, k-coin[i]);
                }
                if(tmp < min){
                    min = tmp;
                }
            }
        }
    }
    answer[k] = min;
    return min;
}