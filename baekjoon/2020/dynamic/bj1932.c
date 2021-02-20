#include <stdio.h>
#include <stdlib.h>

/*
25m
*/

int dynamic_triangle(int triangle[][501], int answer[][501], int n, int now, int select);

int main(){
    int i,j,k,n;
    int triangle[501][501];
    int answer[501][501];
    

    scanf("%d",&n);
    for(i=1;i<n+1;i++){
        for(j=1;j<=i;j++){
            scanf("%d",&triangle[i][j]);
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<=i;j++){
            answer[i][j] = -1;
        }
    }
    printf("%d",dynamic_triangle(triangle,answer,n,1,1)+triangle[1][1]);
}

int dynamic_triangle(int triangle[][501], int answer[][501], int n, int now, int select){
    int max = -1000;
    int tmp, tmp2;
    int i,j;
    if(now == n){
        return 0;
    }
    else{
        if(answer[now+1][select] != -1){
            tmp = triangle[now+1][select] + answer[now+1][select];
        }
        else{
            tmp = triangle[now+1][select] + dynamic_triangle(triangle,answer,n,now+1,select);
        }

        if(answer[now+1][select+1] != -1){
            tmp2 = triangle[now+1][select+1] + answer[now+1][select+1];
        }
        else{
            tmp2 = triangle[now+1][select+1] + dynamic_triangle(triangle,answer,n,now+1,select+1);
        }
        if(tmp > tmp2){
            max = tmp;
        }
        else{
            max = tmp2;
        }
    }
    answer[now][select] = max;
    return max;
}