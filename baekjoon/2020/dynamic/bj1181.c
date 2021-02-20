#include <stdio.h>
#include <stdlib.h>


int compare(char pivot[], char arr[]){ // TRUE - pivot이 사전순으로 앞이거나 같다.  FALSE - Pivot이 사전순으로 뒤다
    // printf("비교중 : %s : %s\n",pivot,arr);
    if(strlen(pivot) < strlen(arr)){
        // printf("%s 가 %s보다 앞선다.\n",pivot,arr);
        return 0;
    }
    else if(strlen(pivot) >= strlen(arr)){
        // printf("%s 가 %s보다 앞선다.\n",arr,pivot);
        return 1;
    }
    else{
        for(int i=0; i<strlen(pivot); i++){
            if(pivot[i] < arr[i]){
                // printf("%s 가 %s보다 앞선다.\n",pivot,arr);
                return 0;
            }
            else if(pivot[i] >= arr[i]){
                // printf("%s 가 %s보다 앞선다.\n",arr,pivot);
                return 1;
            }          
        }
    }
    // printf("%s 가 %s보다 앞선다.\n",pivot,arr);
    return 1;
}

int compare2(char pivot[], char arr[]){ // TRUE - pivot이 사전순으로 앞이거나 같다.  FALSE - Pivot이 사전순으로 뒤다
    // printf("비교중 : %s : %s\n",pivot,arr);
    if(strlen(pivot) < strlen(arr)){
        // printf("%s 가 %s보다 앞선다.\n",pivot,arr);
        return 1;
    }
    else if(strlen(pivot) >= strlen(arr)){
        // printf("%s 가 %s보다 앞선다.\n",arr,pivot);
        return 0;
    }
    else{
        for(int i=0; i<strlen(pivot); i++){
            if(pivot[i] < arr[i]){
                // printf("%s 가 %s보다 앞선다.\n",pivot,arr);
                return 1;
            }
            else if(pivot[i] >= arr[i]){
                // printf("%s 가 %s보다 앞선다.\n",arr,pivot);
                return 0;
            }          
        }
    }
    // printf("%s 가 %s보다 앞선다.\n",pivot,arr);
    return 1;
}

int main(){

    char str[20000][50];
    int num,i;

    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%s",str[i]);
    }

    quick(str,0,num-1);

    printf("\n\n");
    for(i=0;i<num;i++){
        printf("%s\n",str[i]);
    }


    // printf("%d\n",str[1]);
    // printf("%d\n",str[2]);

}


int partition(char arr[][50], int start, int end){
    int i;
    char temp[50];
    char pivot[50];
    for(i=0;i<strlen(arr[start]);i++){ 
        pivot[i] = arr[start][i];
    }
    int low = start+1;
    int high = end;

    while(low <= high){
        // printf("one\n");
        // printf("%s, %s\n",pivot,arr[low]);
        // printf("%d\n",compare(pivot,arr[low]));
        // printf("%s, %s\n",pivot,arr[high]);
        // printf("%d\n",compare(pivot,arr[high]));
        while(compare(pivot,arr[low]) && low <= end){
            // printf("two\n");
            low++;
        }
        while(compare2(pivot,arr[high]) && high >= (start+1)){
            high--;
            // printf("three\n");
        }
        if(low <= high){
            for(i=0;i<50;i++){ // temp배열 초기화
                temp[i] = '\0';
            }
            for(i=0;i<strlen(arr[low]);i++){ // temp = arr[low];
                temp[i] = arr[low][i];
            }
            for(i=0;i<50;i++){ // arr[low]배열 초기화
                arr[low][i] = '\0';
            }
            for(i=0;i<strlen(arr[high]);i++){ // arr[low] = arr[high];
                arr[low][i] = arr[high][i];
            }
            for(i=0;i<50;i++){ // arr[high]배열 초기화
                arr[high][i] = '\0';
            }
            for(i=0;i<strlen(temp);i++){ // arr[high] = temp;
                arr[high][i] = temp[i];
            }
        
        }
    }

    for(i=0;i<50;i++){ // temp배열 초기화
        temp[i] = '\0';
    }
    for(i=0;i<strlen(arr[start]);i++){ //   temp = arr[start];
        temp[i] = arr[start][i];
    }
    for(i=0;i<50;i++){ // arr[start]배열 초기화
        arr[start][i] = '\0';
    }
    for(i=0;i<strlen(arr[high]);i++){ // arr[start] = arr[high];
        arr[start][i] = arr[high][i];
    }
    for(i=0;i<50;i++){ // arr[high]배열 초기화
        arr[high][i] = '\0';
    }
    for(i=0;i<strlen(temp);i++){ // arr[high] = temp;
        arr[high][i] = temp[i];
    }
    return high;
}

int quick(char arr[][50], int start, int end){
    // printf("start!\n");
    int pivot;
    if(start <= end){
        pivot = partition(arr,start,end);
        quick(arr,start,pivot-1);
        quick(arr,pivot+1,end);
    }
}



