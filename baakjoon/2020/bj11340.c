#include <stdio.h>

int exam(int a, int b, int c){
    int total;
    int final;
    total = a*15 + b*20 + c*25;
    int i;
    for(i=75;i<=100;i++){
        if((total+i*40) >= 9000){
            printf("%d\n",i);
            return 1;
        }
    }   
    printf("impossible\n");
    return 1;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int a,b,c;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        exam(a,b,c);
    }
}

