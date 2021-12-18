#include <stdio.h>
#include <stdlib.h>

int arr[2001] = {0};
int dpl[2001][3] = {0}; // 총길이, 맨좌측값 맨우측값
int dpr[2001][3] = {0};

int lis_algo(int n);

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int ans;
    ans = lis_algo(n);

    printf("\n dpl--------\n");
    for(i=0;i<n;i++){
        printf("%d %d %d\n",dpl[i][0],dpl[i][1],dpl[i][2]);
    }
    printf("\n dpr--------\n");
    for(i=0;i<n;i++){
        printf("%d %d %d\n",dpr[i][0],dpr[i][1],dpr[i][2]);
    }
    int max = 1;
    for(i=0;i<n;i++){
        if(max < dpl[i][0]){
            max = dpl[i][0];
        }
        if(max < dpr[i][0]){
            max = dpr[i][0];
        }
    }
    if(n == 0){
        printf("%d",0);   
    }
    else{
        printf("%d",max);
    }


}

int lis_algo(int n){
    int i,j;
    int maxl, maxr;
    for(i=0;i<n;i++){
        dpl[i][0] = 1;
        dpl[i][1] = arr[i];
        dpl[i][2] = arr[i];
        dpr[i][0] = 1;
        dpr[i][1] = arr[i];
        dpr[i][2] = arr[i];
        maxl,maxr = 1,1;
        for(j=0;j<i;j++){
            if(dpl[j][0]+1 >= dpl[i][0] && dpl[i][1] < dpl[j][1]){ // 이전 dpl에서 l에 추가가능한지
                if(dpl[j][0]+1 == dpl[i][0]){
                    if(dpl[j][2] < dpl[i][2]){
                        dpl[i][0] = dpl[j][0]+1;
                        dpl[i][2] = dpl[j][2];
                    }
                }
                else{
                    dpl[i][0] = dpl[j][0]+1;
                    dpl[i][2] = dpl[j][2];
                }
            }
            if(dpr[j][0]+1 >= dpl[i][0] && dpl[i][1] < dpr[j][1]){ // 이전 dpr에서 l에 추가가능한지
                if(dpr[j][0]+1 == dpl[i][0]){
                    if(dpl[j][2] < dpl[i][2]){
                        dpl[i][0] = dpr[j][0]+1;
                        dpl[i][2] = dpr[j][2];
                    }
                }
                else{
                    dpl[i][0] = dpr[j][0]+1;
                    dpl[i][2] = dpr[j][2];

                }
            }
            if(dpl[j][0]+1 >= dpr[i][0] && dpl[j][2] < dpr[i][2]){ // 이전 dpl에서 r에 추가가능한지
                if(dpl[j][0]+1 == dpr[i][0]){
                    if(dpl[j][1] > dpr[i][1]){
                        dpr[i][0] = dpl[j][0]+1;
                        dpr[i][1] = dpl[j][1];
                    }
                }
                else{
                    dpr[i][0] = dpl[j][0]+1;
                    dpr[i][1] = dpl[j][1];
                }
            }
            if(dpr[j][0]+1 >= dpr[i][0] && dpr[j][2] < dpr[i][2]){ // 이전 dpr에서 r에 추가가능한지
                if(dpr[j][0]+1 == dpr[i][0]){
                    if(dpl[j][1] > dpr[i][1]){
                        dpr[i][0] = dpr[j][0]+1;
                        dpr[i][1] = dpr[j][1];
                    }
                }
                else{
                    dpr[i][0] = dpr[j][0]+1;
                    dpr[i][1] = dpr[j][1];
                }
            }
        }
    }
    return 0;   
}
