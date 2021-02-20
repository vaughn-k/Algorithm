#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 987654321

char room[21][21];
int dp[21][21];
int tmp[4] = {0};
int n,m;
int si,se;
int cd[12][2] = {0};
int count; // 더러운칸 개수
// cd[0] = 시작점위치
// cd[1]~ = 더러운칸 위치

int dfs(int ni, int nj, int ti, int tj);
int min(int x, int y);
void printmap(int a, int b);

int main(){
    int i,j;
    int check = 1;
    int minimum = INF;
    while(check){
        scanf("%d %d",&m,&n);
        if(n != 0 && m != 0){
            for(i=0;i<n;i++){
                scanf("%s",&room[i]);
            }

        }
        else{
            check = 0;
        }
        count = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(room[i][j] == '*'){
                    count++;
                    cd[count][0] = i;
                    cd[count][1] = j;
                }
                if(room[i][j] == 'o'){
                    cd[0][0] = i;
                    cd[0][1] = j;
                }

            }
        }

        int s;
        int k;
        for(i=count;i>0;i--){ // i : 목적지
            int a,b;
            // for(a=0;a<n;a++){
            //     for(b=0;b<m;b++){
            //         printf("%d",dp[a][b]);
            //     }
            //     printf("\n");
            // }
            for(j=0;j<i;j++){ // j : 출발지
                for(k=0;k<n;k++){
                    memset(dp[k], 0, sizeof(int)*m);
                }    
                s = dfs(cd[j][0],cd[j][1],cd[i][0],cd[i][1]);
                // printmap(cd[i][0],cd[i][1]);
                printf("[%d][%d] 에서 [%d][%d]로 가는데 거리 : %d\n",cd[j][0],cd[j][1],cd[i][0],cd[i][1],s);
            } 
        }
    }
}

int dfs(int ni, int nj, int ti, int tj){
    // printmap(ti,tj);
    // usleep(300000);
    // printf("%d %d\n",ni,nj);
    if(ni < 0 || ni >= n || nj < 0 || nj >= m){
        return INF;
    }
    if(room[ni][nj] == 'x' || room[ni][nj] == 'n'){
        return INF;
    }
    if(ni==ti && nj==tj){
        return 0;
    }
    if(dp[ni][nj] != 0){
        return dp[ni][nj];
    }
    room[ni][nj] = 'n';
    int mm = INF;
    tmp[0] = 1 + dfs(ni+1,nj,ti,tj); // up
    tmp[1] = 1 + dfs(ni,nj+1,ti,tj); // right
    tmp[2] = 1 + dfs(ni-1,nj,ti,tj); // down
    tmp[3] = 1 + dfs(ni,nj-1,ti,tj); // left
    mm = min(min(tmp[0],tmp[1]),min(tmp[2],tmp[3]));
    room[ni][nj] = '.';
    dp[ni][nj] = mm;
    return mm;
}

int min(int x, int y){
    return x < y ? x : y;
}

void printmap(int a, int b){
    int i,j;
    printf("\ntarget position : [%d][%d]---\n",a,b);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%c",room[i][j]);
        }
        printf("\n");
    }
}