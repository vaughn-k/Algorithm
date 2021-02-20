#include <stdio.h>
#include <stdlib.h>

/*
1h 10m
자잘한 실수가 너무 많았다.
int answer[n+1];
이렇게정의하는 등..

*/

int dynamic_sugar(int answer[], int n, int now);


int main(){
    int i,j,k,n;
    int answer[5001];
    int ans;

    scanf("%d",&n);
    for(i=0;i<n+1;i++){
        answer[i] = 0;
    }

    ans = dynamic_sugar(answer,n,n);
    if(ans < 0){
        printf("%d",-1);
    }
    else{
        printf("%d",ans);
    }
}

int dynamic_sugar(int answer[], int n, int now){
    
    int i;
    int min = 99999;
    int tmp;
    int check = 0;
    if(now == 0){
        return 0;
    }
    else{
        // 3씩
        for(i=3;i<=5;i=i+2){ // 3,5
            if(now-i >= 0 && answer[now-i] >= 0){ // 무게초과 방지
                if(answer[now-i] > 0){
                    tmp = answer[now-i] + 1;
                }
                else{
                    tmp = dynamic_sugar(answer, n, now-i) + 1;
                }
                if(tmp >= 0){ // 가능한 경우가 있다.
                    check = 1;
                    if(tmp < min){
                        min = tmp;
                    }
                }
            }
        }
        if(check == 0){ // 현재 now에서 불가능
            answer[now] = -100;
            return -100;
        }
    }
    answer[now] = min;
    return min;
}