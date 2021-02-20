#include <stdio.h>
#include <stdlib.h>

// 의견

/*
문제이해를 제대로 하지못해 몇시간을 허비했다
문제에서 첫계단을 밟고 두번째계단을 밟을수는 있지만 연속된 3개의 계단을 밟지 못한다고 하였다.
그런데 이 의미는 처음에는 계단에서 출발하는것이 아니기에 첫출발시와 중간에서의 count가 달라져야하기에 이부분에서 많은 시간을
허비하였다.

다이나믹 프로그래밍으로 구현하였으며 불가능한 계단을 오르지않고 그 전에 조건문으로 걸러내어 가능한 계단들만
오르게(다음함수가 실행되게)하였다.
따라서 진행하다가 불가능한 부분이 나오면 answer 배열값이 -1000 으로 바뀌며 가장 비효율적인 길로 바뀌어 다른 차선책을 
max 값으로 채택되게 하였다. (사실 0보다만 작은 값이면 상관없을듯싶다)

이문제가 다른 DP문제들과 다른점은 현재 같은 위치(계단)에 있어도 현재까지 연속되었던 1의 횟수(count)에 따라 최고 max값이
달라진다는 점이다. 따라서 1차원배열이였던 answer배열이 2차원으로 사용한 이유가 그것이다.
** 앞전까지의 결과가 뒷부터의 결과와 "독립적인가 아닌가" 의 여부가 key point 이다.
*/

int dynamic_stairs(int answer[][3],int stairs[], int n, int now, int count);



int main(){

    int i,j,k,max;
    int n; // 계단의 개수
    int *stairs; // 계단당 점수
    int answer[301][3]; // 해당 계단에서의 최대점수
    scanf("%d",&n);
    

    stairs = (int*)malloc(sizeof(int)*(n+1));
    for(i=1;i<(n+1);i++){
        scanf("%d",&stairs[i]);
    }
    for(i=1;i<(n+1);i++){
        for(j=0;j<3;j++){
            answer[i][j] = 0;
            // printf("answer[%d][%d] = %d\n",i,j,answer[i][j]);
        }
    }

    printf("%d", dynamic_stairs(answer, stairs, n, 0, -1));
}

int dynamic_stairs(int answer[][3],int stairs[], int n, int now, int count){ 
    // 1이 연속3번인가?
    // 최종계단을 초과했는가?
    int max = -1000;
    int tmp;
    if(now == n){ // 끝 
        return 0;
    }
    else{ // now < n
        //1계단 오를때
        if(now+1 <= n && count < 1){
            if(answer[now+1][count+1] != 0){
                // printf("tmp1 : %d + %d\n",stairs[now+1],answer[now+1][count+1]);
                tmp = stairs[now+1] + answer[now+1][count+1];
            }
            else{
                // printf("tmp2 : %d + %d\n",stairs[now+1],dynamic_stairs(answer,stairs,n,now+1,count+1));
                tmp = stairs[now+1] + dynamic_stairs(answer,stairs,n,now+1,count+1);
            }
            if(tmp > max){
                max = tmp;
            }
        }
        
        //2계단 오를때
        if(now+2 <= n){
            if(answer[now+2][0] != 0){
                // printf("tmp3 : %d + %d\n",stairs[now+2],answer[now+2][0]);
                tmp = stairs[now+2] + answer[now+2][0];
            }
            else{
                // printf("tmp4 : %d + %d\n",stairs[now+2],dynamic_stairs(answer,stairs,n,now+2,0));
                tmp = stairs[now+2] + dynamic_stairs(answer,stairs,n,now+2,0);
            }
            if(tmp > max){
                max = tmp;
            }
        }
    }
    // printf("asnwer[%d][%d] : %d\n",now,count,max);
    answer[now][count] = max;
    return max;
}