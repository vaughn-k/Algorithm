#include <stdio.h>
#include <stdlib.h>

/*
7m
*/

int main(){
    int a,b,v,i,j;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&v);

    int day;
    int real; // 하루에 갈수 있는 거리
    int target; // 마지막으로 도약하기위해 가야하는 최소거리

    real = a-b;
    target = v-a;

    if(target%real == 0){
        printf("%d",target/real+1);
    }
    else{
        printf("%d",target/real+2);
    }
}