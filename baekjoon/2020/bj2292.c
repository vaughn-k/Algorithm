#include <stdio.h>

int main(){
    int n;
    int i;
    scanf("%d",&n);
    int now = 1;
    int s = 6;
    int check = 1;
    int count = 1;
    while(check){
        if(n <= now){
            printf("%d",count);
            check = 0;
        }
        now = now + s;
        s = s+ 6;
        count++;
    }
}