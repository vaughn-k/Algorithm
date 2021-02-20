#include <stdio.h>

int main(){
    int n,i;
    int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
    int check = 1;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        tmp1 = i/100000;
        tmp2 = (i-(i/100000)*100000)/10000;
        tmp3 = (i-(i/10000)*10000)/1000;
        tmp4 = (i-(i/1000)*1000)/100;
        tmp5 = (i-(i/100)*100)/10;
        tmp6 = (i-(i/10)*10);
        if(n == tmp1+tmp2+tmp3+tmp4+tmp5+tmp6+i){
            printf("%d",i);
            check = 0;
            break;
        }
    }
    if(check){
        printf("%d",0);
    }
}