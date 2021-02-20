#include <stdio.h>

int n;
int arr[3];
int dmax[2][3] = {0};
int dmin[2][3] = {0};
int tran(int x);
int min(int x, int y);
int max(int x, int y);

int main(){
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);
        if(i == 0){
            for(j=0;j<3;j++){
                dmax[0][j] = arr[j];
                dmin[0][j] = arr[j];
            }
        }
        else{
            for(j=0;j<3;j++){
                if(j == 0){
                    dmin[tran(i)][j] = arr[j] + min(dmin[tran(i+1)][j],dmin[tran(i+1)][j+1]);
                    dmax[tran(i)][j] = arr[j] + max(dmax[tran(i+1)][j],dmax[tran(i+1)][j+1]);
                }
                else if(j == 1){
                    dmin[tran(i)][j] = arr[j] + min(dmin[tran(i+1)][j-1],min(dmin[tran(i+1)][j],dmin[tran(i+1)][j+1]));
                    dmax[tran(i)][j] = arr[j] + max(dmax[tran(i+1)][j-1],max(dmax[tran(i+1)][j],dmax[tran(i+1)][j+1]));
                }
                else{
                    dmin[tran(i)][j] = arr[j] + min(dmin[tran(i+1)][j],dmin[tran(i+1)][j-1]);
                    dmax[tran(i)][j] = arr[j] + max(dmax[tran(i+1)][j],dmax[tran(i+1)][j-1]);
                }
            }

        }
    }
    printf("%d ",max(dmax[tran(n-1)][0],max(dmax[tran(n-1)][1],dmax[tran(n-1)][2])));
    printf("%d",min(dmin[tran(n-1)][0],min(dmin[tran(n-1)][1],dmin[tran(n-1)][2])));
}

int tran(int x){
    return x%2 == 1 ? 1 : 0;
}

int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y){
    return x > y ? x : y;
}