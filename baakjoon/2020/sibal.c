#include <stdio.h>
#include <stdlib.h>

typedef struct Position{
    int x;
    int y;
}Posi;

Posi pp[100001];

int cmp(const void* a, const void *b){
    return (*(Posi*)a).x < (*(Posi*)b).x;
}

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&pp[i].x,&pp[i].y);
    }
    printf("\nsort after\n");
    qsort(pp,n,sizeof(Posi),cmp);
    for(i=0;i<n;i++){
        printf("%d %d\n",pp[i].x,pp[i].y);
    }
}