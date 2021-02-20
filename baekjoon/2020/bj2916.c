#include <stdio.h>
#include <stdlib.h>

int seta_n[10]= {};
int seta_k[10]= {};
int store[360] = {};

int dp(int now, int n, int total); 
int find(int k);


int main(){
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&seta_n[i]);
        store[seta_n[i]] = 1;
        store[360-seta_n[i]] = 1;
    }
    for(i=0;i<k;i++){
        scanf("%d",&seta_k[i]);
    }

    dp(0,n,0);
    find(k);

}

int dp(int now, int n, int total){
    if(total > 360){
        total = total - 360;
    }
    if(total > 0){
        store[total] = 1;
        store[360-total] = 1;
    }
    if(now == n){
        // 저장
        return 0;
    }
    dp(now+1,n,total+seta_n[now]);
    dp(now+1,n,total-seta_n[now]);
    dp(now+1,n,total);
    return 0;
}

int find(int k){
    int i;
    for(i=0;i<k;i++){
        if(store[seta_k[i]] == 1){
            printf("YES\n");
        } 
        else{
            printf("NO\n");
        }
    }
}