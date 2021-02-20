#include <stdio.h>
#include <stdlib.h>
// 2h
// 알고리즘때배웠던 행렬곱 최대? 그거랑 비슷한느낌
// 호텔하고도 비슷한거같음
// 행렬곱 최대와 다른점은 ??
// 격자판 상에서 좌변과 아래변으로 그 사이변을 유추할수 있던 행렬곱과 다르게
// 모든 경우를 전부 고려해야한다는 점에서 차이가 있는거같지만 행렬곱은? ;;

#define INF 98765432;

int people[257] = {};
int total[257][257] = {};
int minp[257][257] = {};

int make_minp(int n);
int make_total(int n, int start, int end);
int min(int a, int b);
int abs(int x);

int main(){

    int i,j,n,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&people[i]);
    }

    make_minp(n);
    ans = make_total(n,0,n-1);

    printf("%d\n",ans);

}

int make_minp(int n){
    int i,j;
    int x,y;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            x = j-i;
            y = j;
            if(x == y){
                minp[x][y] = people[x];
            }
            else{
                minp[x][y] = min(minp[x][y-1],minp[x+1][y]);
            }
        }
    }
    return 0;
}

int make_total(int n, int start, int end){
    // printf("%d %d\n",start,end);
    if(start == end){
        return 0;
    }
    if(start+1 == end){
        return abs(people[end]-people[start]);
    }
    int i,j;
    int tmp=0;
    int minimum = INF;
    if(total[start][end] != 0){
        return total[start][end];
    }
    for(i=start;i<end;i++){
        tmp = make_total(n,start,i) + make_total(n,i+1,end) + abs(minp[start][i]-minp[i+1][end]);
        if(minimum > tmp){
            minimum = tmp;
        }
    }
    total[start][end] = minimum;
    return minimum;

}

int min(int a, int b){
    if(a >= b) return b;
    else return a;
}

int abs(int x){
    if(x < 0) return x*(-1);
    else return x;
}