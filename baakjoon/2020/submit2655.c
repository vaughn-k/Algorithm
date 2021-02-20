#include <stdio.h>
#include <stdlib.h>

int size[101] = {};
int weight[101] = {};
int height[101] = {};
int number[101] = {};
int submax[101] = {};
int max[101] = {0};
int max_h[1] = {};
int count_h[1] = {};

int start(int n);
int top(int n, int now, int nsize, int total, int count);
int copy(int count,int n);
int partition(int n,int s,int e);
int quicksort(int n,int s,int e);
void swap(int* a, int* b);

int main(){
    int i,j,n;
    max_h[0] = 0;
    count_h[0] = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&size[i],&height[i],&weight[i]);
        number[i] = i;
        max[i] = -1;
    }

    partition(n,0,n-1);
    start(n);
    printf("%d\n",count_h[0]+1);
    for(i=n-1;i>=0;i--){
        if(max[i] != -1){
            printf("%d\n",number[max[i]]+1);
        }
    }

}
int start(int n){
    int i;
    for(i=0;i<n;i++){
        top(n,i,10001,0,0);
    }
}

int top(int n, int now, int nsize, int total, int count){
    if(total > max_h[0]){
        max_h[0] = total;
        count_h[0] = count;
        copy(count,n);
    }
    if(nsize < size[now]){
        return 0;
    }
    if(now == n-1){
        if(total+height[now] > max_h[0]){
            submax[count] = now;
            max_h[0] = total+height[now];
            count_h[0] = count;
            copy(count,n);
            submax[count] = -1;

        }
        return 0;
    }
    // 진행은 정렬된 weight 순으로 진입후에 size가능한지 확인
    int i,j;
    for (i = now+1; i < n; i++){
        submax[count] = now;
        top(n,i,size[now],total+height[now],count+1); // now벽돌을 선택하고 다음으로 i번째 벽돌을 선택
        submax[count] = -1;
        
    }
    
}
int copy(int count,int n){
    int i;
    for (i = 0; i < n; i++)
    {
        if(i < count+1){
            max[i] = submax[i];
        }
        else{
            max[i] = -1;
        }
    }
}

int partition(int n,int s,int e){
    if(s >= e){
        return 0;
    }
    int mid = quicksort(n,s,e);
    partition(n,s,mid-1);
    partition(n,mid+1,e);
}

int quicksort(int n,int s,int e){
    if(s >= e){
        return 0;
    }
    int pivot = weight[s];
    int i,j,tmp;
    j = s+1;
    for(i=s+1;i<=e;i++){
        if(weight[i] > pivot){
            swap(&weight[i],&weight[j]);
            swap(&height[i],&height[j]);
            swap(&size[i],&size[j]);
            swap(&number[i],&number[j]);
            j++;
        }
    }
    swap(&weight[s],&weight[j-1]);
    swap(&height[s],&height[j-1]);
    swap(&size[s],&size[j-1]);
    swap(&number[s],&number[j-1]);
    return j-1;
}

void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}