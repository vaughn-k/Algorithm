#include <stdio.h>
int mat[4][4] = {};
int visit[4][4] = {};

int back(int s);

int main(){
    scanf("%1d",&A[i][j]); // 연속된 입력들 하나씩 받기

    // int a[10][10] = {1,};
    // int b[10] = {};
    // // a[0] = 10;
    // // printf("%d\n",a[0]);
    // int i,j;
    // for(i=0; i<10; i++){
    //     for(j=0; j<10; j++){
    //         printf("%d ",a[i][j]);
    //     }
    //     printf("\n");
    // }

    // for(i=0; i<10; i++){
    //     printf("%d ",b[i]);
    // }

    int a,b,c;
    int i,j;

    for(i=0;i<5;i++){
        scanf("%d%d%d",&a,&b,&c);
        mat[a-1][b-1] = c;
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    back(0);
}


int back(int s){
    int i,j;
    
    for(i=0;i<4;i++){
        if(!(visit[s][i]) && mat[s][i] != 0){
            printf("%d 에서 %d 방문 거리 = %d\n",s,i,mat[s][i]);
            visit[s][i] = 1;
            if(s != i){
                back(i);
            }
            visit[s][i] = 0;
        }
    }
    return 0;
}