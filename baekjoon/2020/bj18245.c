#include <stdio.h>
#include <stdlib.h>

char arr[10001];

int main(){
    int n,i,j;
    int start = 1;
    i = 1;
    int now;
    while(strcmp(arr,"Was\0it\0a\0cat\0I\0saw?")){
        if(strlen(arr) > 0){
            while(now < strlen(arr)){
                printf("%c",arr[now]);
                now = now + i;
            }
            printf("\n");
        }
        now = 0;
        scanf("%s",&arr);
        i++;
    }
}