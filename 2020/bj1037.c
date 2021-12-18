#include <stdio.h>
#include <stdlib.h>


int arr[51];

int cmp(const void *a, const void *b){
    if(*(int *)a < *(int *)b){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp);

    printf("%d",arr[0]*arr[n-1]);
}
