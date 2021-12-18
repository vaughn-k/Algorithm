#include <stdio.h>

#define INF 98765432;

typedef struct DDR_DR{
    int max;
    int po;
}DDR_dr;

DDR_dr dd[100001][5];
int arr[100001][5] = {0};

int main(){
    int n,i;
    n = 1;
    scanf("%d",&arr[0]);
    i = 0;
    while(arr[i] != 0){
        scanf("%d",&arr[++i]);
    }
    n = i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    // for(i=0;i<8000000;i++){
    //     n++;
    // }
    // printf("%d",n
}

int ddr(int n){
    int i,j,k;
    int min = INF;
    int a,b;
    for(i=0;i<n;i++){
        if(i==0){
            dd[i][0].max = 2;
            dd[i][0].po = arr[i];
        }
        else{
            for(j=0;j<5;j++){
                if(arr[i] != j){
                    for(k=0;k<5;k++){
                        a = dd[]
                        dd[i][j] = 
                        dd[i-1][]
                    }
                }
            }
        }
    }
}

int input_p(int a, int b){
    if(a == 0 || b || 0){
        return 2;
    }
    if(a == b){
        return 1;
    }
    if(abs(a-b) == 2){
        return 4;
    }
    if(abs(a-b) == 1 || abs(a-b) == 3){
        return 3;
    }
}

int abs(int a){
    if(a < 0){
        return a*(-1);
    }
    else{
        return a;
    }
}