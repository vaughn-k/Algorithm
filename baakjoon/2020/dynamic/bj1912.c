#include <stdio.h>
#include <stdlib.h>

int main(){

    int answer[100001][2];
    int check[100001][2];
    int integer[100001];

    int i,j,k,n;

    for(i=0;i<n+1;i++){
        for(j=0;j<2;j++){
            check[i][j]=0;
            answer[i][j]=0;
        }
    }

    scanf("%d",&n);
    for(i=1;i<n+1;i++){
        scanf("%d",&integer[i]);
    }

    printf("%d",dynamic_continue_total(answer, check, integer, n, 0, 0));



}

int dynamic_continue_total(int answer[][2], int check[][2], int integer[], int n, int now, int state){
    /*
    state 0 = 아직 1이 없음
    state 1 = 현재 1진행중
    state 2 = 1 끝나서 앞으로 0만 나올수 있음;
    */
    int max=0;
    int tmp;
    int tmp2;
    if(now == n){
        return 0;
    }
    else{
        if(state == 0){
            if(now+1 == n){ // 만약 맨 마지막에서 2번째까지 0이였다면 맨 마지막은 무조건 1이 되야한다.
                max = integer[n];
                return max;
            }
            else{
                if(check[now+1][0] == 1){
                    tmp = integer[now+1] + answer[now+1][0];
                }
                else{                
                    tmp = dynamic_continue_total(answer, check, integer, n, now+1, 0); // 0선택
                }

                if(check[now+1][1] == 1){
                    tmp2 = integer[now+1] + answer[now+1][1];
                }
                else{
                    tmp2 = integer[now+1] + dynamic_continue_total(answer, check, integer, n, now+1, 1);
                }
                if(tmp > tmp2){
                    max = tmp;
                }
                else{
                    max = tmp2;
                }
            }
        }
        else if(state == 1){
            tmp = 0; // 0선택
            if(check[now+1][1] == 1){
                tmp2 = integer[now+1] + answer[now+1][1];
            }
            else{
                tmp2 = integer[now+1] + dynamic_continue_total(answer, check, integer, n, now+1, 1);
            }
            if(tmp > tmp2){
                max = tmp;
            }
            else{
                max = tmp2;
            }
        }
        else{ // state == 2
            return 0;
        }
    }
    check[now][state] = 1;
    answer[now][state] = max;
    return max;
    
}