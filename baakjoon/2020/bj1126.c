// 51%쯤에서 틀림;

#define _CRT_OBSOLETE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int top[51] = {};
int store[51][500001] = {};
int dp(int n, int now, int left, int right);
int max(int a, int b, int c);
int max2(int a, int b);
int abs(int a);
int count[1] = {};
int bound[1] = {};


int main(){
    int n,i,maximum;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&top[i]);
        bound[0] = bound[0] + top[i];
    }
    if(bound[0] > 500000){
        printf("%d\n",-1);
        return 0;
    }
    printf("bound : %d\n",bound[0]);
    bound[0] = bound[0]/2;
    printf("bound : %d\n",bound[0]);

    clock_t start, end;
    // start = clock();
    maximum = dp(n,0,0,0);
    if(maximum <= 0){
        printf("%d\n",-1);
    }
    else{
        printf("%d\n",maximum);
    }
    // end = clock();
    // printf("count : %d\n",count[0]);
    // printf("time : %.3f\n",(float)(end-start)/CLOCKS_PER_SEC);

    
}

int dp(int n, int now, int left, int right){
    count[0] = count[0] + 1;
    if(left > bound[0] || right > bound[0]){
        return 0;
    }
    if(now == n){
        if(left == right){
            return left;
        }
        else{
            return 0;
        }
    }
    int ans = 0;
    if(store[now][abs(left-right)] != 0){
        return store[now][abs(left-right)]+max2(left,right);
    }
    
    int tmp1,tmp2,tmp3;
    tmp1 = dp(n, now+1, left+top[now], right);
    tmp2 = dp(n, now+1, left, right+top[now]);
    tmp3 = dp(n, now+1, left, right);
    ans = max(tmp1, tmp2, tmp3);

    store[now][abs(left-right)] = ans-max2(left,right);
    return ans;
}

int max2(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int max(int a, int b, int c){
    if(a >= b){
        if(a >= c){
            return a;
        }
        else{
            return c;
        }
    }
    else{
        if(b >= c){
            return b;
        }
        else{
            return c;
        }
    }
}

int abs(int a){
    if(a < 0){
        return a*(-1);
    }
    else{
        return a;
    }
}