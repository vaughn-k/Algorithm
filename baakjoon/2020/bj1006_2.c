#include <stdio.h>

int n,w;
int arr[10001][2] = {0};

int main(){
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){

    }
}

int ddp(int now, int state, int start){
    //state 
    // 0 : 위아래 비어있는상태
    // 1 : 위만 채워진상태
    // 2 : 아래만 채워진상태
    //start
    // 0 : 마지막과 연결 안된상태
    // 1 : 위만 연결된 상태
    // 2 : 아래만 연결된 상태

    int i;
    if(state == 0){
        if(now == n-1){
            if(arr[now][0]+arr[now][1] <= w){
                return 1;
            }
            else{
                return 2;
            }
        }
        else{
            if(arr[now][0]+arr[now][1] <= w){
                
            }
        }
    }
}