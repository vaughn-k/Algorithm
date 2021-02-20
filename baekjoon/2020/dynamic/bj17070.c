#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,j,k,n;
    int house[1001][3];
    int answer[1001][3];

    scanf("%d",&n);
    for(i=1;i<n+1;i++){
        for(j=0;j<3;j++){
            scanf("%d",&house[i][j]);
        }
    }

    for(i=1;i<n+1;i++){
        for(j=0;j<3;j++){
            answer[i][j] = 0;
        }
    }
    int c1,c2,c3;
    c1 = dynamic_house(house,answer,n,1,0);
    c2 = dynamic_house(house,answer,n,1,1);
    c3 = dynamic_house(house,answer,n,1,2);

    if(c1 < c2){
        if(c1 < c3){
            printf("%d",c1);
        }
        else{
            printf("%d",c3);
        }
    }
    else{
        if(c2 < c3){
            printf("%d",c2);
        }
        else{
            printf("%d",c3);
        }
    }

    // for(i=1;i<n+1;i++){
    //     for(j=0;j<3;j++){
    //         printf("%d ",answer[i][j]);
    //     }
    //     printf("\n");
    // }
}

int dynamic_house(int house[][3], int answer[][3], int n, int now, int color){ // color : 0,1,2
// now부터 x컬러로 색칠했을때 최솟값
    int min = 1000000;
    int tmp, tmp2;

    if(now == n){
        return house[now][color];
    }

    else{
        if(color == 0){
            if(answer[now+1][1] != 0){
                tmp = answer[now+1][1];
            }
            else{
                tmp = dynamic_house(house,answer,n,now+1,1);
            }
            if(answer[now+1][2] != 0){
                tmp2 = answer[now+1][2];
            }
            else{
                tmp2 = dynamic_house(house,answer,n,now+1,2);
            }
            if(tmp < tmp2){
                min = house[now][color] + tmp;
            }
            else{
                min = house[now][color] + tmp2;
            }
        }
        else if(color == 1){
            if(answer[now+1][0] != 0){
                tmp = answer[now+1][0];
            }
            else{
                tmp = dynamic_house(house,answer,n,now+1,0);
            }
            if(answer[now+1][2] != 0){
                tmp2 = answer[now+1][2];
            }
            else{
                tmp2 = dynamic_house(house,answer,n,now+1,2);
            }
            if(tmp < tmp2){
                min = house[now][color] + tmp;
            }
            else{
                min = house[now][color] + tmp2;
            }
        }
        else{ // (color == 2)
             if(answer[now+1][0] != 0){
                tmp = answer[now+1][0];
            }
            else{
                tmp = dynamic_house(house,answer,n,now+1,0);
            }
            if(answer[now+1][1] != 0){
                tmp2 = answer[now+1][1];
            }
            else{
                tmp2 = dynamic_house(house,answer,n,now+1,1);
            }
            if(tmp < tmp2){
                min = house[now][color] + tmp;
            }
            else{
                min = house[now][color] + tmp2;
            }
        }
    }
    answer[now][color] = min;
    return min;
}