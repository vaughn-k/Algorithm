// 거의 한달넘게 씨름했던 문제.
// dp를 하나 만들어서 각각 dpmax[i][j] : i = now, j : 좌우높이차 일때 둘중 긴쪽에 더할수 있는 숫자.
// 메모리가 5만kb 이고 시간도 300ms 이므로 통과는 했지만 좀더 효율적인 방법이 있는지 공부해볼 필요가 있다.


#include <stdio.h>
#include <stdlib.h>

int bl[51];
int dplarge[51][250001] = {0};
int n;
int max;
int maximum;

int block(int l, int s, int now);
int fmaximum(int x, int y);

int main(){
    int i;
    max = -2;
    maximum = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&bl[i]);
        maximum = maximum + bl[i];
    }
    block(0,0,0);
    
    if(max == 0){
        printf("%d",-1);  
    }
    else{
        printf("%d",max);
    }
}

int block(int l, int s, int now){
    int tmp1,tmp2,tmp3,m;
    if(l == s){
        if(l > max){
            max = l;
        }
    }
    if(now == n || l > maximum/2){
        if(l == s){
            return l;
        }
        else{
            return -1;
        }
    }
    if(dplarge[now][l-s] != 0){
        if(dplarge[now][l-s] < 0){
            return -1;
        }
        else{
            if(l+dplarge[now][l-s] > max){
                max = l+dplarge[now][l-s];
            }
            return l+dplarge[now][l-s];
        }
    }
    tmp1 = block(l+bl[now],s,now+1);
    if(s+bl[now] > l){
        tmp2 = block(s+bl[now],l,now+1);
    }
    else{
        tmp2 = block(l,s+bl[now],now+1);
    }
    tmp3 = block(l,s,now+1);
    m = fmaximum(tmp1,fmaximum(tmp2,tmp3));
    dplarge[now][l-s] = m-l;
    return m;
}

int fmaximum(int x, int y){
    return (x > y) ? x : y;
}