#include <stdio.h>

int arr[1001][1001]; 
int dplr[1001][1001]; // i,j기준으로 연속으로 왼쪽에 1개수(자신포함)
int dpud[1001][1001]; // i,j기준으로 연속으로 위쪽에 1개수(자신포함)
int max;
int n,m;

int make_dp();
int ddp();
int min(int x, int y);

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%1d",&arr[i][j]);
        }
    
    }
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }

    make_dp();
    // printf("--------------\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",dplr[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("--------------\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",dpud[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("--------------\n");
    ddp();
    printf("%d",max*max);

}

int make_dp(){
    int i,j;
    int count = 0;

    // dplr 생성
    for(i=0;i<n;i++){
        count = 0;
        for(j=0;j<m;j++){
            if(arr[i][j] == 0){
                if(j == 0){
                    dplr[i][j] = 0;
                }
                else{
                    count = 0;
                    dplr[i][j] = 0;
                }
            }
            else{
                count++;
                dplr[i][j] = count;
            }
        }
    }
    count = 0;
    // dpud 생성
    for(j=0;j<m;j++){
        count = 0;
        for(i=0;i<n;i++){
            if(arr[i][j] == 0){
                if(i == 0){
                    dpud[i][j] = 0;
                }
                else{
                    count = 0;
                    dpud[i][j] = 0;
                }
            }
            else{
                count++;
                dpud[i][j] = count;
            }
        }
    }
    return 0;
}

int ddp(){
    max = 0;
    int i,j,k;
    int c;
    int m_lr;
    int m_ud;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(dplr[i][j] >= 1 && dpud[i][j] >= 1){
                if(max == 0){
                    max = 1;
                }
                c = min(dplr[i][j],dpud[i][j]);
                m_lr = dplr[i][j];
                m_ud = dpud[i][j];
                // printf("\nc : %d\n",c);
                for(k=1;k<c;k++){
                    if()
                    m_lr = min(m_lr,dplr[i-k][j]);
                    m_ud = min(m_ud,dpud[i][j-k]);
                }
                c = min(m_lr,m_ud);
                // printf("c : %d\n\n",c);
                if(max < c){
                    max = c;
                }
                // while(c >= 1){
                //     if(dplr[i-c+1][j] >= c && dpud[i][j-c+1] >= c){
                //         if(max < c){
                //             max = c;
                //             c = 0;
                //         }
                //     }
                //     c--;
                // }
            }
        }
    }
    return 0;
}

int min(int x, int y){
    return x < y ? x : y;
}