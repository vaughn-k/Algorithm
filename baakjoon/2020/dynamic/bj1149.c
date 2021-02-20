#include <stdio.h>
#include <stdlib.h>

int house[20][20];
int answer[20][20];
int n;

int main(){

    int i,j,k;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&house[i][j]);
        }
    }

    printf("%d",dynamic_house(0,1,1));

}

int dynamic_house(int r, int c, int type){ // type : 1 : right / 2 : down / 3 : cross
    if(r == n-1 && c == n-1){
        return 1;
    }
    int tmp = 0;
    if(type == 1){
        if(c < n && house[r][c+1] != 1){ // 우측으로 진입가능 && 벽아닐때
            tmp = tmp + dynamic_house(r,c+1,1);
            if(r < n && house[r+1][c+1] != 1 && house[r+1][c] != 1){ // 대각선, 우측, 아래 진입가능 && 벽아닐때
                tmp = tmp + dynamic_house(r+1,c+1,3);
            }
        }
    }
    if(type == 2){
        if(r < n && house[r+1][c] != 1){ // 아래로 진입가능 && 벽아닐때
            tmp = tmp + dynamic_house(r+1,c,2);
            if(r < n && house[r+1][c+1] != 1 && house[r][c+1] != 1){ // 대각선, 우측, 아래 진입가능 && 벽아닐때
                tmp = tmp + dynamic_house(r+1,c+1,3);
            }
        }

    }
    else{
        if(c < n && house[r][c+1] != 1){ // 우측으로 진입가능 && 벽아닐때
            tmp = tmp + dynamic_house(r,c+1,1);
            if(r < n && house[r+1][c] != 1){ // 아래로 진입가능 && 벽아닐때
                tmp = tmp + dynamic_house(r+1,c,2);
                if(house[r+1][c+1] != 1){ // 대각선, 우측, 아래 진입가능 && 벽아닐때
                    tmp = tmp + dynamic_house(r+1,c+1,3);
                }
            }
        }
        else{
            if(r < n && house[r+1][c] != 1){ // 아래로 진입가능 && 벽아닐때
                tmp = tmp + dynamic_house(r+1,c,2);
            }
        }
    }
    return tmp;
}