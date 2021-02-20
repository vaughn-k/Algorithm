// lis 문제집에 있길래 당연히 lis인줄 알았으나 그냥 순회;;

#include <stdio.h>

int arr[100001] = {0};
int rev[100001] = {0};

int inc(int n);
int dec(int n);


int main(){
    int i,j,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        rev[n-1-i] = arr[i];
    }
    int ans,ans2;
    ans = inc(n);
    ans2 = dec(n);
    if(ans < ans2){
        printf("%d",ans2);
    }
    else{
        printf("%d",ans);
    }
}

int inc(int n){
    int max = 1;
    int count = 1;
    int i,j;
    for(i=0;i<n-1;i++){
        if(arr[i] <= arr[i+1]){
            count++;
        }
        else{
            if(max < count){
                max = count;
            }
            count = 1;
        }
    }
    return max;
}
int dec(int n){
    int max = 1;
    int count = 1;
    int i,j;
    for(i=0;i<n-1;i++){
        if(rev[i] <= rev[i+1]){
            count++;
        }
        else{
            if(max < count){
                max = count;
            }
            count = 1;
        }
    }
    return max;
}