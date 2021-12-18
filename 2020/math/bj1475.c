#include <stdio.h>
#include <stdlib.h>

/*
30m
*/

int main(){
    int set[10];
    char input[7];
    int i;
    for(i=0;i<10;i++){
        set[i] = 0;
    }
    scanf("%s",&input);
    for(i=0;i<strlen(input);i++){
        if(input[i]-48 == 6 || input[i]-48 == 9){
            set[6] = set[6]+1;
        }
        else{
            set[input[i]-48]++;
        }
    }

    set[6] = set[6]/2+set[6]%2;

    int max = -1;
    for(i=0;i<10;i++){
        if(set[i] > max){
            max = set[i];
        }
    }

    printf("%d",max);
}