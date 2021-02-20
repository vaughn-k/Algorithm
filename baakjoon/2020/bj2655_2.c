#include <stdio.h>
#include <stdlib.h>

// 두변수조건을 고려하면서 한변수의 최대값을 갖게하는 조합을 구한뒤 그 조합구성원소들까지 구하기


typedef struct BLOCK{
    int weight;
    int size;
    int height;
    int track;
    int number;
}Block;

Block bl[101] = {};
int dp[101] = {}; // dp[i] = 블럭들을 size가 큰순으로 정렬한후 해당원소를 마지막으로 갖는 최대 높이값

int top(int n);
int cmp(const void* a, const void* b){
    return (*(Block*)a).size < (*(Block*)b).size;
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        bl[i].number = i;
        bl[i].track = -1;
        scanf("%d %d %d",&bl[i].size, &bl[i].height, &bl[i].weight);
    }
    qsort(bl,n,sizeof(Block),cmp);

    int ans;
    ans = top(n);
    tracking(ans);
}

int top(int n){
    int i,j;
    int max = 1;
    int maxi = -1;
    for(i=0;i<n;i++){
        dp[i] = bl[i].height;
        if(max < dp[i]){
            max = dp[i];
            maxi = i;
        }
        for(j=0;j<i;j++){
            if(bl[j].weight > bl[i].weight && dp[j]+bl[i].height > dp[i]){
                dp[i] = dp[j]+bl[i].height;
                bl[i].track = j;
                if(max < dp[i]){
                    max = dp[i];
                    maxi = i;
                }
            }
        }
    }
    return maxi;
}

int tracking(int s){
    int next = s;
    int count = 0;
    while(next != -1){
        count = count+1;
        next = bl[next].track;
    }
    printf("%d\n",count);
    next = s;
    while(next != -1){
        printf("%d\n",bl[next].number+1);
        next = bl[next].track;
    }
    return 0;
}