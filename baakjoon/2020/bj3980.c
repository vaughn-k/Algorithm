#include <stdio.h>

// maxi 초기값을 0으로해서 현재 posi상태에서 불가능할 경우 그냥 0을 리턴했던 문제 수정 - -1111로 초기화함으로서 해결
// 마지막 프린트에 \n이 있어야했다;; 이건좀..
#define MINF -987654321;

int arr[12][12];
int n;
int socc(int posi, int now);
int max(int x, int y);

int main(){
    int j,i,k;
    scanf("%d",&n);
    for(k=0;k<n;k++){
        for(i=0;i<11;i++){
            for(j=0;j<11;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        printf("%d\n",socc(0,0));
    }
}

int socc(int posi, int now){
    // state : 현재 포지션이 정해진 선수 = 1, 아니면 0
    // posi : 현재 채워진 포지션 = 1, 아니면 0
    int maxi = MINF;
    int i,j;
    if(now == 11){
        return 0;
    }
    for(i=0;i<11;i++){
        if(((posi & (1<<i)) == 0) && (arr[now][i] != 0)){
            maxi = max(maxi,socc(posi+(1<<i),now+1)+arr[now][i]);
        }
    }
    return maxi;
}

int max(int x, int y){
    return x > y ? x : y;
}