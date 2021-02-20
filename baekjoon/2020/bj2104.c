#include <stdio.h>

int main(){
    int i,j,n;
    int tmp = 0;
    n = 100000;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tmp++;
        }
    }
    printf("%d",tmp);
}