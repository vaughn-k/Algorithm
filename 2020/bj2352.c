#include <stdio.h>
#include <stdlib.h>

int arr[1000001] = {};
int lis[1000001] = {};


int lis_algo(int n);
int lower_bound(int target, int len);

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int ans;
    ans = lis_algo(n);
    printf("%d",ans);

}

int lis_algo(int n){
    int i;
    int len;
    len = 1;
    lis[0] = arr[0];
    for(i=1;i<n;i++){
        len = len + lower_bound(arr[i],len);
    }
    return len;
}

int lower_bound(int target, int len){
    int mid;
    int start,end;
    start = 0;
    end = len-1;
    if(lis[end] < target){
        lis[end+1] = target;
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
        if(target < lis[mid]){
            end = mid;
        }
        else{
            start = mid;
        }
    }
}