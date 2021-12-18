#include <stdio.h>
#include <stdlib.h>

int dynamic_make_one(int answer[], int n, int now);


int main(){

    int i,j,k;
    int n;
    int *answer;
    scanf("%d",&n);
    

    answer = (int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<(n+1);i++){
        answer[i] = 0;
    }
    printf("%d",dynamic_make_one(answer,n,n));
}

int dynamic_make_one(int answer[], int n, int now){ 
    int min = 1000003;
    int tmp;
    if(now == 1){
        return 0;
    }
    if(now%3 == 0){
        if(answer[now/3] != 0){
            tmp = answer[now/3]+1;
        }
        else{
            tmp = dynamic_make_one(answer,n,now/3)+1;
        }
        if(tmp < min){
            min = tmp;
        }
    }
    if(now%2 == 0){
        if(answer[now/2] != 0){
            tmp = answer[now/2]+1;
        }
        else{
            tmp = dynamic_make_one(answer,n,now/2)+1;
        }
        if(tmp < min){
            min = tmp;
        }
    }
    if(answer[now-1] != 0){
            tmp = answer[now-1]+1;
        }
    else{
        tmp = dynamic_make_one(answer,n,now-1)+1;
    }
    if(tmp < min){
        min = tmp;
    }
    answer[now] = min;
    return min;
}