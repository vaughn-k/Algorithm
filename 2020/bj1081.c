#include <stdio.h>

int main(){
    int n,m;
    int i,j;
    scanf("%d %d",&n,&m);
    int total = 0;
    for(i=n;i<m+1;i++){
        total = total + i;
    }
    printf("%d\n",total);
}