#include <stdio.h>
#include <stdlib.h>

long long dynamic_pinary_number(long long answer[][2],int n, int now, int state);


int main(){
    int i,j,n;
    long long answer[91][2];
    scanf("%d",&n);

    for(i=1;i<n+1;i++){
        for(j=0;j<2;j++){
            answer[i][j] = 0;
        }
    }

    printf("%lld",dynamic_pinary_number(answer,n,n,1));

}

long long dynamic_pinary_number(long long answer[][2],int n, int now, int state){
    long long total = 0LL;
    if(now == 1){
        return 1LL;
    }
    if(state == 0){ // 0,1 둘다가능
        if(answer[now-1][1] != 0){
            total = answer[now-1][1];
        }
        else{
            total = dynamic_pinary_number(answer,n,now-1,1);
        }
    }
    if(answer[now-1][0] != 0){
        total = total + answer[now-1][0];
    }
    else{
        total = total + dynamic_pinary_number(answer,n,now-1,0);
    }

    answer[now][state] = total;
    return total;
}