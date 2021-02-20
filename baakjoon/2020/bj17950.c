// 36m 원리는 간단했는데 생각보다 오래걸리네..
// 이처럼 숫자가 매우 클 경우 범위가 int를 벗어나는지 아닌지 꼭 확인해봐야한다.

#include <stdio.h>

long long arr[1000001];

int main(){
    int h,x,i;
    long long ans = 0;
    scanf("%d %d",&h,&x);
    for(i=0;i<h;i++){
        scanf("%d",&arr[i]);
    }
    ans = arr[h-1];

    for(i=h-2;i>=0;i--){
        ans = (ans*x + arr[i])%(1000000007); 
    }
    printf("%lld",(ans*x)%(1000000007));
}

