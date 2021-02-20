#include <stdio.h>
#include <stdlib.h>

char arr[101];

int s(int x, int y){
    int tmp,tmp2;
    tmp = abs(x-y);
    tmp2 = 26-tmp;
    return tmp < tmp2 ? tmp : tmp2;
}

int abs(int x){
    return x < 0 ? x*(-1) : x;
}

int main(){
    scanf("%s",&arr);
    int i;
    // printf("%d\n",'A'-'B'); // 65
    // printf("%d\n",'Z'); // 90
    int total = 0;
    int n;
    int tmp,tmp2;
    n = strlen(arr);
    // printf("n : %d\n",n);
    for(i=0;i<n-1;i++){
        tmp = abs(arr[i]-arr[i+1]);
        tmp2 = 26-tmp;
        total = tmp < tmp2 ? total+tmp : total+tmp2;
    }
    tmp = abs('A'-arr[0]);
    tmp2 = 26-tmp;
    total = tmp < tmp2 ? total+tmp : total+tmp2;

    printf("%d",total);


}