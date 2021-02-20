#include <stdio.h>
#include <stdlib.h>

int blocktop(int **answer, int block[], int left, int right, int n, int now, int total, int now_max[]);
int min(int a,int b);

int main(){
    int i,j,k,max;
    int n;
    int block[55];
    int **answer;
    int now_max[1];
    now_max[0] = -1;
    scanf("%d",&n);
    
    answer = (int**)malloc(sizeof(int*)*500002);
    for(i=0;i<500002;i++){
        answer[i] = (int*)malloc(sizeof(int)*51);
    }

    for(i=0;i<n;i++){
        scanf("%d",&block[i]);
    }
    for(i=0;i<500001;i++){
        for(j=0;j<51;j++){
            answer[i][j] = -2;
        }
    }
    int ans;
    ans = blocktop(answer,block,0,0,n,0,0,now_max);
    if(ans == -1 || ans == 0){
        printf("%d",-1);
    }
    else{
        printf("%d",ans);
    }

}

int blocktop(int **answer, int block[], int left, int right, int n, int now, int total, int now_max[]){
    if(now == n){
        if(left != right){
            return -1;
        }
        else{
            if(now_max[0] < left){
                now_max[0] = left;
            }
            return left;
        }      
    }

    if(answer[abs(right-left)][now] != -2){
        return answer[abs(right-left)][now] + min(left,right);
    }

    int tmp1,tmp2,tmp3,maximum;
    // 해당 블록을 왼쪽에 쌓음
    tmp1 = blocktop(answer,block,left+block[now],right,n,now+1,total-block[now],now_max);
    // 해당 블록을 오른쪽에 쌓음
    tmp2 = blocktop(answer,block,left,right+block[now],n,now+1,total-block[now],now_max);
    // 해당 블록은 쌓지 않음
    tmp3 = blocktop(answer,block,left,right,n,now+1,total-block[now],now_max);

    if(tmp1 > tmp2){
        if(tmp1 > tmp3){
            maximum = tmp1;
        }
        else{
            maximum = tmp3;
        }
    }
    else{
        if(tmp2 > tmp3){
            maximum = tmp2;
        }
        else{
            maximum = tmp3;
        }
    }
    if(maximum != -1){
        answer[abs(right-left)][now] = maximum - min(left,right);
    }
    else{
        answer[abs(right-left)][now] = maximum;
    }
    
    return maximum;
}

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}