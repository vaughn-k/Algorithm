// 비트 마스킹 

#include <stdio.h>
int bit(int n);

int main(){
    int n,m,i;
    int t1 = 4; //11100

    n = 87;
    m = 35;

    for(i=0;i<17;i++){
        bit(i);
    }
    // printf("     n  : ");
    // bit(n);
    // printf("n << 3  : ");
    // bit(n<<3);
    // printf("n << 33 : ");
    // bit(n<<24);
    // printf("n >> 2  : ");
    // bit(n>>2);

    // n = (n << 3);
    // m = (m << 5);
    // printf("    n : ");
    // bit(n);
    // printf("    m : ");
    // bit(m);
    // printf("\n");
    // printf("n & m : ");
    // bit(n&m);
    // printf("n | m : ");
    // bit(n|m);
    // printf("n ^ m : ");
    // bit(n^m);
    // printf("%d",~m);
    // printf("%d\n",n&m);
    // printf("%d\n",n|m);
    // printf("%d\n",n^m);
    // printf("%d\n",~m);
    // printf("%d\n",n);


    // scanf("%d",&n);
    // scanf("%d",&m);
    // n = 1 << 7; // 왼쪽에서부터 k번째를 1로 채우려면 n + 1 << (k-1)
    // bit(n);
    // n = n + (1<<4) + (1<<2);
    // bit(n);
    // n = n - (1<<4) - (1<<2);
    // bit(n);
    // bit(n);
    // bit(m);
    // printf("ans : %d\n",n&m);
    // printf("ans : %d\n",n|m);
    // for(i=0;i<10;i++){
    //     bit(n);
    //     n = n << 1;
    // }
    // n = 1 << 2;
    // bit(n);
    // n = 8 >> 2;
    // bit(n);
}

int bit(int n){
    int r = n;
    int i = 0;
    printf("0");
    for(i=30;i>=0;i--){
        // printf("|%dn|",n);
        if((1<<i) <= n & n > 0){
            printf("1");
            n = n - (1<<i);
        }
        else{
            printf("0");
        }
        if(i%4 == 0){
            printf(" ");
        }
    }
    printf(" - n = %d\n",r);
    return 0;
}