#include <stdio.h>
//10m

int main(){
    int i,n;
    int s1,s2,s3;
    scanf("%d",&n);
    int total = 0;
    for(i=1;i<n+1;i++){
        if(i <= 99){
            total = total + 1;
        }
        else{
            s1 = i/100;
            s2 = i/10-10*s1;
            s3 = i-(i/10)*10;
            if(s1-s2 == s2-s3){
                total = total + 1;
            }
        }
    }
    printf("%d",total);
}
