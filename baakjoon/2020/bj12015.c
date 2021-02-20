#include <stdio.h>
#include <stdlib.h>

// bj11053 에서는 array의 최대 길이가 1000이기때문에
// n^2 nlogn 두 알고리즘 모두 통과를 했지만 이문제의 입력은
// 최대 1000000 이므로 n^2은 시간초과가 난다.
// 따라서 nlogn의 lis 알고리즘을 이용해야한다.

int arr[1000001] = {};
int lis[1000001] = {};

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


