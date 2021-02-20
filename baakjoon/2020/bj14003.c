#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int arr[1000001] = {};
int lis[1000001] = {};
int real[1000001] = {};
int track[1000001] = {};
int final[1000001] = {};

int shuffle(int n);
int lis_algo(int n);
int lower_bound(int target, int len, int now);
void find_arr(int start);

int main(){
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        real[i] = -1;
    }

    // for(i=0;i<n;i++){
    //     arr[i] = i+1;
    //     real[i] = -1;
    // }
    // shuffle(n);
    // shuffle(n);
    // shuffle(n);
    // printf("\n");
    // for(i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");

    // clock_t start, end;
    // float res;
    // int ans;
    // start = clock();
    // ans = lis_algo(n);
    // printf("%d\n",ans);
    // find_arr(ans);
    // end = clock();
    // res = (float)(end - start)/CLOCKS_PER_SEC;
	// printf("소요된 시간 : %.3f \n", res);
    int ans;
    ans = lis_algo(n);
    printf("%d\n",ans);
    find_arr(ans);


}

int lis_algo(int n){ // lower_bound(이분탐색)를 이용한 nlogn 의 시간복잡도
    int i,j;
    int len = 0; // 현재 lis 배열의 마지막 원소 인덱스
    lis[0] = arr[0];
    track[0] = 0;
    for(i=1;i<n;i++){
        len = len + lower_bound(arr[i],len,i);
    }
    return len+1;
}

void find_arr(int start){
    int i;
    int count = start;
    start = track[start-1];
    for(i=0;i<count;i++){
        final[count-i-1] = arr[start];
        // printf("%d [%d] \n",i,arr[start]);
        start = real[start];
    }
    // printf("%d ",arr[start]);

    for(i=0;i<count;i++){
        printf("%d ",final[i]);
    }
}

int lower_bound(int target, int len, int now){ // 자신보다 큰 애들중에 가장 작은애 자리를 뺏는다
    int start,end,mid;
    start = 0;
    end = len;
    if(target > lis[end]){
        lis[end+1] = target;
        real[now] = track[end];
        track[end+1] = now;
        return 1;
    }

    while(1){
        if(end-start == 1){
            if(lis[start] < target){
                lis[end] = target;
                real[now] = track[end-1];
                track[end] = now;
            }
            else{
                lis[start] = target;
                if(start == 0){
                    real[now] = -1;
                    track[start] = now;
                }
                else{
                    real[now] = track[start-1];
                    track[start] = now;
                }
            }
            return 0;
        }
        if(end == start){
            if(lis[end] >= target){
                lis[end] = target;
                real[now] = track[end-1];
                track[end] = now;
            }
            return 0;
        }
        mid = (start+end)/2;
        if(lis[mid] < target){
            start = mid;
        }
        else{
            end = mid;
        }
    }
    return 0;
}

int shuffle(int n){
    srand(time(NULL));
    int rn, rn2, i, tmp;
    for (i = 0; i < n; i++)
    {
        rn = rand()%(n);
        rn2= rand()%(n);
        tmp = arr[rn];
        arr[rn] = arr[rn2];
        arr[rn2] = tmp;
    }
}