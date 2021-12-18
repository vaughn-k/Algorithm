#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int n,i;
    int tmp;
    scanf("%d",&n);

    srand(time(0));
    for(i=0;i<n;i++){
        tmp = rand()%500000;
        printf("%d\n",tmp);
    }
}
