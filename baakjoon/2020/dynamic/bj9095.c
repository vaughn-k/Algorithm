#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,j,k,n,input;

    int *number;
    int arr[11];

    scanf("%d",&input);
    for(i=0;i<input;i++){
        scanf("%d",&arr[i]);
    }
    number = (int*)malloc(sizeof(int)*12);
    for(i=0;i<11;i++){
        number[i] = 0;
    }
    number[1] = 1;
    number[2] = 2;
    number[3] = 4;

    for(i=0;i<input;i++){
        number[i] = 0;
    }
    
       


    for(i=0;i<input;i++){
        dynamic_total(number,arr[i],arr[i]);
    }


    for(i=0;i<input;i++){
        printf("%d\n",number[arr[i]]);
    }


}

int dynamic_total(int number[], int final, int now){ // 0인채로는 못들어온다
    if(now == 1){
        number[final]++;
        return 0;
    }
    else if(now == 2){
        number[final] = number[final]+2;
        return 0;
    }
    else if(now == 3){
        number[final] = number[final]+4;
        return 0;
    }
    else if(number[now] != 0){
        number[final] = number[final] + number[now];
    }
    else{
        dynamic_total(number,final,now-3);
        dynamic_total(number,final,now-2);
        dynamic_total(number,final,now-1);
    }
    return 0;
}