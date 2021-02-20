// 58m
// int로 커버불가능해지는 c언어로 할때는 꼭 판단하기
// 숫자가 매우 커질수도 있어서 long long 으로 해주어야한다
// 추가로 long long + int = long long 가능하다. 굳이 모든 int 를 다 long long 으로 바꿔줄
// 필요는 없다.

#include <stdio.h>
#include <stdlib.h>


#define INF 100000000000;

long long dp(int n, int now, int now_i, int now_j, int type);
int atob(int a_x, int a_y, int b_x, int b_y);
int abs(int x);
long long min(long long a, long long b);

int client_x[100001] = {};
int client_y[100001] = {};
long long store[100001][4] = {};

int main(){
    int i,j,n,s_x,s_y;
    scanf("%d",&n);
    scanf("%d %d",&s_x,&s_y);
    for(i=0; i<n; i++){
        scanf("%d %d",&client_x[i],&client_y[i]);
    }

    long long final;
    final = dp(n,0,s_x,s_y,0);
    printf("%lli",final);

}


long long dp(int n, int now, int now_i, int now_j, int type){
    if(now_i < 0 || now_i > 100000 || now_j < 0 || now_j > 100000){
        return INF;
    }
    if(now == n){
        return 0;
    }
    if(store[now][type] != 0){
        return store[now][type];
    }
    long long tmp1,tmp2,tmp3,tmp4;
    tmp1 = atob(now_i,now_j,client_x[now],client_y[now]-1) + dp(n,now+1,client_x[now],client_y[now]-1,0);
    tmp2 = atob(now_i,now_j,client_x[now]+1,client_y[now]) + dp(n,now+1,client_x[now]+1,client_y[now],1);
    tmp3 = atob(now_i,now_j,client_x[now],client_y[now]+1) + dp(n,now+1,client_x[now],client_y[now]+1,2);
    tmp4 = atob(now_i,now_j,client_x[now]-1,client_y[now]) + dp(n,now+1,client_x[now]-1,client_y[now],3);
    long long ans = min(min(tmp1,tmp2),min(tmp3,tmp4));
    store[now][type] = ans; 
    return ans;
}

int atob(int a_x, int a_y, int b_x, int b_y){
    return abs(a_x-b_x)+abs(a_y-b_y);
}

int abs(int x){
    if(x < 0) return x*(-1);
    else return x;
}

long long min(long long a, long long b){
    if(a <= b) return a;
    else return b;
}