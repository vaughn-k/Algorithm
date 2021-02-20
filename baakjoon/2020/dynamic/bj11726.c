#include <stdio.h>
#include <stdlib.h>

/*
이문제는 2xn 칸에 1x2, 2x1타일로 채울수 있는 총 방법의 수를 출력하는 문제이다.
앞뒤 관계가 서로 독립적이므로 1차원 answer이 가능하고
총갯수 / 최대최소 중 총 갯수이므로 return값을 축적해가며 최종 답을 이끌어내면된다

그런데 문제에서 
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
라고 해놓고 최종답에 10007 모듈러를 돌리면 답이 틀린다;
매 total값을 계산할때마다 모듈러를 돌려주어야한다.
음 그런데 사실 매번 빼주나 한번에 빼주나 같은거아닌가 싶은데

*/

unsigned long dynamic_tile(unsigned long answer[], int n);


int main(){
    int i,j,k,n;
    unsigned long answer[1001];

    scanf("%d",&n);

    for(i=0;i<n+1;i++){
        answer[i] = 0;
    }
    answer[1] = 1;
    answer[2] = 2;
    
    if(n == 1){
        printf("%d",1);
    }
    else if(n == 2){
        printf("%d",2);
    }
    else{
        printf("%lu",dynamic_tile(answer,n)%10007);
    }

    // for(i=1;i<n;i++){
    //     printf("%d : %lu\n",i,dynamic_tile(answer,i)%10007);
    // }


    // for(i=0;i<n+1;i++){
    //     printf("%d : %d\n",i,answer[i]);
    // }
}

unsigned long dynamic_tile(unsigned long answer[], int n){
    unsigned long total = 0;
    unsigned long tmp;
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    else{
        if(n-2 >= 1){
            if(answer[n-2] != 0){
                tmp = answer[n-2];
            }
            else{
                tmp = dynamic_tile(answer, n-2);
            }
                total = total + tmp;
        }
        if(n-1 >= 1){
            if(answer[n-1]){
                tmp = answer[n-1];
            }
            else{
                tmp = dynamic_tile(answer, n-1);    
            }
            total = total + tmp;
        }
    }
    answer[n] = total%10007;
    return total;
}