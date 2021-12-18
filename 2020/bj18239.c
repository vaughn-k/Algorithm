#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n == 2){
        printf("YES\n");
        printf("swap %d %d\n",1,2);
        printf("swap %d %d\n",1,2);
        printf("swap %d %d\n",1,2);
        printf("swap %d %d\n",1,2);
        printf("swap %d %d\n",1,2);
    }
    printf("YES\n");
    printf("swap %d %d\n",1,n-m);
    printf("swap %d %d\n",n-m+1,n);
    printf("swap %d %d\n",1,n);
    printf("swap %d %d\n",1,n);
    printf("swap %d %d\n",1,n);
}