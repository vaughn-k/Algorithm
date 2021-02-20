#include <stdio.h>
#include <stdlib.h>
int partition(int arr[], int start, int end);
int quick(int arr[], int start, int end);

int main(){
    int arr1[50];
    int arr2[50];
    int num;
    int i;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<num;i++){
        scanf("%d",&arr2[i]);
    }

    quick(arr1,0,num-1);
    quick(arr2,0,num-1);



    int answer=0;
    for(i=0;i<num;i++){
        answer = answer + arr1[i]*arr2[num-i-1];
    }
    printf("%d",answer);

    
}

int partition(int arr[], int start, int end){
    int i;
    int temp;
    int pivot = arr[start];
    int low = start+1;
    int high = end;

    while(low <= high){
        while(pivot >= arr[low] && low <= end){
            low++;
        }
        while(pivot <= arr[high] && high >= (start+1)){
            high--;
        }
        if(low <= high){
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    temp = arr[start];
    arr[start] = arr[high];
    arr[high] = temp;
    return high;
}

int quick(int arr[], int start, int end){
     for(int i = 0 ; i < 20 ; i++){
        //printf("%d ",arr[i]);
    }
    int pivot;
    if(start <= end){
        pivot = partition(arr,start,end);
        quick(arr,start,pivot-1);
        quick(arr,pivot+1,end);
    }
}

