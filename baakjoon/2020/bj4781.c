#include <stdio.h>

typedef struct CANDY{
    int c,p;
}Candy;

Candy ca[5001];
int dp[5001][10001];

int main(){
    int n,m,i,j;
    float tmp;

    // scanf("%d %f",&n,&tmp);
    // m = tmp*100;
    // for(i=0;i<n;i++){
    //     scanf("%d %f",&ca[i].c,&tmp);
    //     ca[i].p = tmp*100;
    // }
    printf("11111");
    // for(i=0;i<n;i++){
    //     printf("%d %d\n",ca[i].c,ca[i].p);
    // }
    // printf("22222");
    // dpp(n,m);
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("%d")
}

// int dpp(int n, int m){
//     printf("helloe");
//     int i,j,k;
//     int tmp = 0;
//     int np, nc;
//     int check = 1;
//     int check2 = 1;
//     int now_max;
//     for(i=0;i<10000;i++){ // i = 사탕번호
//         check = 1;
//         j = 0;
//         while(check){
//             printf("what11?");
//             np = ca[i].p * j;
//             nc = ca[i].c * j;
//             if(i == 0){
//                 if(np <= m){
//                     dp[0][np] = nc;
//                 }
//                 else{
//                     check = 0;
//                 }
//             }
//             else{
//                 if(np <= m){
//                     k = 0;
//                     check2 = 1;
//                     while(check2){
//                         printf("k+np = %d\n",k+np);
//                         if(k+np <= m){
//                             if(dp[i-1][k]+nc > dp[i][k+np]){
//                                 dp[i][k+np] = dp[i-1][k] + nc;
//                             }
//                         }
//                         else{
//                             check2 = 0;
//                         }
//                         k++;
//                     }

//                 }
//                 else{
//                     check = 0;
//                 }
//             }
//             j++;
//         }
//     }
//     printf("%d",tmp);
// }

// int max(int x, int y){
//     return x > y ? x : y;
// }