#include <stdio.h>
#include <stdlib.h>

// 이문제에서는 n^2 nlogn 둘다 성공한다.
// array 길이가 최대 1000이기 때문에 둘다 성공하는것 같다.
// array

int arr[1001] = {};
int lis[1001] = {};

int newdp(int n);
int lis_algo(int n);
int lower_bound(int target, int len);


int main(){
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int ans;
    ans = lis_algo(n);
    printf("%d",ans);


}

int newdp(int n){ // dp를 이용한 lis algorithm - n^2 의 시간복잡도
    int i,j;
    int max = 1;
    for(i=0;i<n;i++){
        lis[i] = 1;
        for(j=0;j<i;j++){
            if(arr[j] < arr[i] && lis[j]+1 > lis[i]){
                lis[i] = lis[j]+1;
                if(max < lis[i]){
                    max = lis[i];
                }
            }
        }
    }
    return max;
}

int lis_algo(int n){ // lower_bound(이분탐색)를 이용한 nlogn 의 시간복잡도
    int i,j;
    int len = 0; // 현재 lis 배열의 마지막 원소 인덱스
    lis[0] = arr[0];
    for(i=1;i<n;i++){
        len = len + lower_bound(arr[i],len);
    }
    return len+1;
}


int lower_bound(int target, int len){ // 자신보다 큰 애들중에 가장 작은애 자리를 뺏는다
    int start,end,mid;
    start = 0;
    end = len;
    if(target > lis[end]){
        lis[len+1] = target;
        return 1;
    }

    while(1){
        if(end-start == 1){
            if(lis[start] < target){
                lis[end] = target;
            }
            else{
                lis[start] = target;
            }
            return 0;
        }
        if(end == start){
            if(lis[end] >= target){
                lis[end] = target;
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
