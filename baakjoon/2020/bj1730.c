#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int len;
char arr[1001];
char map[101][101];
int ddp(int now, int x, int y, int state);

int main(){
    int i,j;
    scanf("%d",&n);
    scanf("%s",&arr);
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            map[i][j] = '.';
        }
    }
    // printf("%d",'D'); 68
    // printf("%d",'U'); 85
    // printf("%d",'R'); 82
    // printf("%d",'L'); 76
    len = strlen(arr);
    ddp(0,0,0,0);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}  

int ddp(int now, int x, int y, int state){
    // state 1 : 수직, 2 : 수평
    if((0 <= x) && (x < n) && (0 <= y) && (y < n) && (map[y][x] == '+')){
        if(arr[now] == 68){
            ddp(now+1,x,y+1,1);
        }
        else if(arr[now] == 85){
            ddp(now+1,x,y-1,1);
        }
        else if(arr[now] == 82){
            ddp(now+1,x+1,y,2);
        }
        else{
            ddp(now+1,x-1,y,2);
        }
        return 0;
    }
    else if(arr[now] == 68 && y != n-1){ // D
        if(state == 2 || map[y][x] == '-'){
            map[y][x] = '+';
        }
        else{
            map[y][x] = '|';
        }
        ddp(now+1,x,y+1,1);
    }
    else if(arr[now] == 85 && y != 0){ // U
        if(state == 2 || map[y][x] == '-'){
            map[y][x] = '+';
        }
        else{
            map[y][x] = '|';
        }
        ddp(now+1,x,y-1,1);
    }
    else if(arr[now] == 82 && x != n-1){ // R
        if(state == 1 || map[y][x] == '|'){
            map[y][x] = '+';
        }
        else{
            map[y][x] = '-';
        }
        ddp(now+1,x+1,y,2);
    }
    else if(arr[now] == 76 && x != 0){ // L
        if(state == 1 || map[y][x] == '|'){
            map[y][x] = '+';
        }
        else{
            map[y][x] = '-';
        }
        ddp(now+1,x-1,y,2);
    }
    else if(now == len){
        if(map[y][x] == '.'){
            if(state == 1){
                map[y][x] = '|';
            }
            else{
                map[y][x] = '-';
            }
        }
        else{
            if((state == 1 && map[y][x] == '-') || (state == 2 && map[y][x] == '|')){
                map[y][x] = '+';
            }
        }
        return 0;
    }
    else{
        ddp(now+1,x,y,state);
        return 0;
    }
}