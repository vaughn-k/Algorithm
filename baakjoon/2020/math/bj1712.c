#include <stdio.h>
#include <stdlib.h>

/*
16m
문제를 끝까지 읽고 모든 경우의 수를 정확히 파악하자
ex> 손익분기점이 없다면 -1를 출력하라 등
*/

int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    int min;
    if(a < (c-b)){
        printf("%d",1);
    }
    else if(c <= b){
        printf("%d",-1);
    }
    else{
        printf("%d",a/(c-b)+1);
        
    }
    
}
