// 9m

#include <stdio.h>

int po[102] = {0};

int main(){
    int n,m,i,j;

    for(i=0;i<=100;i++){
        po[i] = i*i;
    }

    int total = 0;
    int min = 99999;

    scanf("%d %d",&m,&n);
    for(i=0;i<=100;i++){
        if(po[i] >= m && po[i] <= n){
            if(min == 99999){
                min = po[i];
            }
            total = total + po[i];
        }
    }
    if(min == 99999){
        printf("-1");
    }
    else{
        printf("%d\n",total);
        printf("%d\n",min);
    }
}