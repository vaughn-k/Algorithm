// 이전의 lis 알고리즘을 이용한 회로문제를 한번 꼰 문제다.

// 이전의 회로문제에서는 하나의 배열이 정렬되어있어서 나머지 배열을 lis 알고리즘에 넣으면
// 되었지만 이번문제에서는 하나의 배열을 기준으로 다른배열을 정렬해주고 그 후에 lis 알고리즘을 실행시켜야했다.


#include <stdio.h>

int arr1[101] = {};
int arr2[101] = {};
int store[101] = {};
int dp[101] = {};

int lis(int n);
int partition(int n, int s, int e);
int qsort(int n, int s, int e);


int main(){
    int i,j,n,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&arr1[i],&arr2[i]);
    }
    
    partition(n,0,n-1);

    int ans;
    ans = lis(n);
    printf("%d",n-ans);
}

int lis(int n){
    int i,j;
    int max = 1;
    for(i=0;i<n;i++){
        dp[i] = 1;
        for(j=0;j<i;j++){
            if(dp[j]+1 > dp[i] && arr2[i] > arr2[j]){
                dp[i] = dp[j]+1;
                if(max < dp[i]){
                    max = dp[i];
                }
            }
        }
    }
    return max;
}

int partition(int n, int s, int e){
    if(s<e){
        int mid;
        mid = qsort(n,s,e);
        partition(n,s,mid);
        partition(n,mid+1,e);
    }
    else{
        return 0;
    }
    return 0;
}

int qsort(int n, int s, int e){
    if(s >= e){
        return -1;
    }
    int pivot,i,j,tmp;
    pivot = arr1[s];
    j = s+1;
    for(i=s+1;i<=e;i++){
        if(arr1[i] < pivot){
            tmp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = tmp;

            tmp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = tmp;
            j++;
        }
    }
    tmp = arr1[s];
    arr1[s] = arr1[j-1];
    arr1[j-1] = tmp;

    tmp = arr2[s];
    arr2[s] = arr2[j-1];
    arr2[j-1] = tmp;
    return j-1;
}