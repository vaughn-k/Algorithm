// 간단한 문제인줄 알았으나 생각보다 복잡했던문제
// lis 알고리즘과 lds 알고리즘을 동시에 이용하여 구하는문제로 
// 일반적인 dp로는 시간초과이며 lower_bound를 이용했다.
// 기준점을 정해두고 해당 기준점기준으로 최대 몇개가 만족하는지를 구하면되는 문제였다.

// 그런데 처음에 도전했던 dp는 어느부분이 틀렸는지 의문이다.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[2001] = {0};
int rev[2001] = {0};
int dp1[2001] = {0};

int lis(int n, int start);
int lis2(int n, int start);
int lower_bound(int target, int len);
int lower_bound2(int target, int len);

int main(){
    int i,j,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        rev[n-1-i] = arr[i];
    }
    int ans,ans2;
    int max = 0;
    for(i=0;i<n;i++){
        ans = lis(n,i);
        ans2 = lis2(n,i);
        if(max < ans+ans2-1){
            max = ans+ans2-1;
        }
    }
    printf("%d",max);
}

int lis(int n, int start){
    memset(dp1,0,sizeof(dp1));
    int i,j,len;
    len = 1;
    dp1[0] = arr[start];
    for(i=start+1;i<n;i++){
        len = len + lower_bound(arr[i],len);
    }
    return len;
}

int lis2(int n, int start){
    memset(dp1,0,sizeof(dp1));
    int i,j,len;
    len = 1;
    dp1[0] = rev[0];
    for(i=0;i<n-start;i++){
        len = len + lower_bound2(rev[i],len);
    }
    for(i=0;i<len;i++){
        if(rev[n-start-1] <= dp1[i]){
            return i+1;
        }
    }
}

int lower_bound(int target, int len){
    if(dp1[0] > target){
        return 0;
    }
    int start,end,mid;
    start = 0;
    end = len-1;
    if(dp1[end] < target){
        dp1[end+1] = target;
        return 1;
    }
    while(1){
        if(end-start <= 1){
            if(dp1[start] < target){
                dp1[end] = target;
            }
            else{
                dp1[start] = target;
            }
            return 0;
        }
        mid = (start+end)/2;
        if(dp1[mid] < target){
            start = mid;
        }
        else{
            end = mid;
        }
    }
}

int lower_bound2(int target, int len){
    int start,end,mid;
    start = 0;
    end = len-1;
    if(dp1[end] < target){
        dp1[end+1] = target;
        return 1;
    }
    while(1){
        if(end-start <= 1){
            if(dp1[start] < target){
                dp1[end] = target;
            }
            else{
                dp1[start] = target;
            }
            return 0;
        }
        mid = (start+end)/2;
        if(dp1[mid] < target){
            start = mid;
        }
        else{
            end = mid;
        }
    }
}


// int lis(int n, int start){
//     int i,j,max;
//     max = 1;
//     for(i=start;i<n;i++){
//         dp1[i] = 1;
//         for(j=0;j<i;j++){
//             if(dp1[j]+1 > dp1[i] && arr[j] < arr[i]){
//                 dp1[i] = dp1[j]+1;
//                 if(max < dp1[i]){
//                     max = dp1[i];
//                 }
//             }
//         }
//     }
//     return max;
// }
// int lis2(int n, int start){
//     int i,j,max;
//     max = 1;
//     for(i=start;i<n;i++){
//         dp2[i] = 1;
//         for(j=0;j<i;j++){
//             if(dp2[j]+1 > dp2[i] && rev[j] < rev[i]){
//                 dp2[i] = dp2[j]+1;
//                 if(max < dp2[i]){
//                     max = dp2[i];
//                 }
//             }
//         }
//     }
//     return max;
// }

