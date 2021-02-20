#include <stdio.h>
#include <stdlib.h>

typedef struct M_NUMBER{
    int r;
    int index;
    int ans;
}M_number;

int cmp(const void* a, const void* b){
    return (*(int*)a) > (*(int*)b);
}
int cmp_st(const void* a, const void* b){
    return (*(M_number*)a).r > (*(M_number*)b).r;
}

M_number mrr[100001];
int nrr[100001] = {0};
int mr[100001] = {0};

int main(){
    int n,m,i,j,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&nrr[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&mrr[i].r);
        mrr[i].index = i;
    }
    qsort(nrr,n,sizeof(int),cmp);
    qsort(mrr,m,sizeof(M_number),cmp_st);

    i = 0;
    j = 0;
    while(j < m){
        if(i >= n){
            mrr[j].ans = 0;
            j++;
        }
        else if(nrr[i] < mrr[j].r){
            i++;
        }
        else if(nrr[i] > mrr[j].r){
            mrr[j].ans = 0;
            j++;
        }
        else{
            mrr[j].ans = 1;
            j++;
        }
    }

    for(i=0;i<m;i++){
        mr[mrr[i].index] = mrr[i].ans;
    }
    for(i=0;i<m;i++){
        printf("%d\n",mr[i]);
    }
}