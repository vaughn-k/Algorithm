// 4m

#include <stdio.h>

int div(int n, int f){
    int i,tmp;
    tmp = (n/100)*100;
    for(i=0;i<100;i++){
        if((tmp+i)%f == 0){
            if(i < 9){
                printf("0%d",i);
            }
            else{
                printf("%d",i);
            }
            return 0;
        }
    }
    return 0;
}

int main(){
    int n,f,i,j;
    scanf("%d %d",&n,&f);
    div(n,f);
}

