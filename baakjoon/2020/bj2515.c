// 2차시도 : 1h13m

// 너무 복잡하게 생각을 했다. 이문제같은 경우 k번째 그림을 마지막에 놓을때 그때의 최대이익이 그 이후에도
// 변함이 없는가에 대한 부분에서 계속 의문이 생겼었다. 이부분은 확실히 하고 넘어가는것이 좋을거같고
// k번째 그림을 마지막에 놓을때 최소 보이는 길이를 넘고 안넘는 경계치 인덱스가 어딘지 파악해두는것이 중요하고
// 그 이후 최대값을 저장해놓으므로써 j번 순환하는것을막았다.
// n이 30만이기때문에 n^2은 시간초과고 최소 nlogn 이하로 구현해야함을 알수있다.

#include <stdio.h>

int height[300001] = {};
int price[300001] = {};
int dpp[300001] = {}; // dp price i번째 건물 맨끝에 세울때 최대 수익

int main(){
    int n,s,i,j;
    scanf("%d %d",&n,&s);
    for(i=0;i<n;i++){
        scanf("%d %d",&height[i],&price[i]);
    }
    qsort(arr+1, n, sizeof(Picture), cmp);

    int max = 0;
    dpp[0] = price[0];
    int m = 0;
    int max_index = 0;
    int now_max = 0;
    for(i=1;i<n;i++){
        while(height[i] - height[m] >= s && m <= i){
            if(now_max < dpp[m]){ // m이전까지 최대이익을 갖는 인덱스 최신화
                now_max = dpp[m];
                max_index = m;
            }
            m++; // m전까지가 해당그림과 겹치지 않는 그림들이다.
        }
        dpp[i] = now_max + price[i];
    }
    for(i=m;i<n;i++){
        if(now_max < dpp[i]){
            now_max = dpp[i];
        }
    }
    // printf("m = %d\n",m);
    // printf("dpp \n");
    // for(i=0;i<n;i++){
    //     printf("%d ",dpp[i]);
    // }
    printf("%d",now_max);
}

