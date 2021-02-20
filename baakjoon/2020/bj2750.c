#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int *)a > *(int *)b;
}

int arr[1001] = {0};

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(n),cmp);
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }

}
