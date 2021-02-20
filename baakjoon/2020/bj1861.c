#include <stdio.h>
#include <stdlib.h>

int tree[1000001];
// int dp[1000000001];

int cmp(const void *a, const void *b){
    if(*(int *)a < *(int *)b){
        return 1;
    }
    else{
        return -1;
    }
}

int cut(int n, int m){
    int i,j;
    int now = 0; // 현재 나무번호
    int total = 0; // 현재까지 얻은 나무개수
    int once = 0; // 현재까지 한번 자를때마다 생성되는 나무개수

    for(i=tree[0];i>=0;i--){ // i = 나무들중 가장 높은 나무 높이
        while(tree[now] == i){
            once++;
            now++;
        }
        total = total + once;
        if(total >= m){
            printf("%d",i-1);
            return 0;
        }
    }
    return 0;
}

int main(){
    int n,m,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&tree[i]);
    }
    qsort(tree,n,sizeof(int),cmp);
    cut(n,m);
}

