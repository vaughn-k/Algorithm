#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int before_code[1001] = {};
int after_code[1001] = {};
int ab_code[1001] = {};

int dp(int n,int start, int end, int minimum);
int dpp(int start, int end, int minimum);
int abs(int x);
int min(int a, int b);


int main(){
    int i,j,n,count;

    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&before_code[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d",&after_code[i]);
    }
    for(i=0; i<n; i++){
        ab_code[i] = after_code[i] - before_code[i];
        // printf("%d ",ab_code[i]);
    }

    int ans;
    ans = dp(n,0,n-1,0);
    printf("%d\n",ans);


}

int dp(int n, int start, int end, int minimum){
    int i,total,now_max;
    int type;
    type = 1;

    // none : 정해진게 아무것도 없음 1
    // plus : 양수인것만 정해짐 2
    // minus : 음수인것만 정해짐 3
    // p_up : 양수이면서 증가한다 4 
    // p_down : 양수이면서 감소한다 5
    // m_up : 음수이면서 증가한다 6
    // m_down : 음수이면서 감소한다 7
    total = 0;
    for(i=0;i<n+1;i++){
        if(type == 1){
            if(ab_code[i] > 0){
                type = 2;
                now_max = ab_code[i];
            }
            else if(ab_code[i] < 0){
                type = 3;
                now_max = ab_code[i];
            }
        }
        else if(type == 2){
            if(ab_code[i] > 0){
                if(ab_code[i-1] < ab_code[i]){
                    type = 4;
                    now_max = ab_code[i];          
                }
                else if(ab_code[i-1] > ab_code[i]){
                    type = 5;
                }
            }
            else if(ab_code[i] < 0){
                total = total + now_max;
                type = 3;
                now_max = ab_code;
            }
            else{
                total = total + now_max;
                now_max = 0;
                type = 1;
            }
        }
        else if(type == 3){
            if(ab_code[i] < 0){
                if(abs(ab_code[i-1]) < abs(ab_code[i])){
                    type = 6;
                    now_max = abs(ab_code[i]);          
                }
                else if(abs(ab_code[i-1]) > abs(ab_code[i])){
                    type = 7;
                }
            }
            else if(ab_code[i] > 0){
                total = total + now_max;
                type = 2;
                now_max = abs(ab_code);
            }
            else{
                total = total + now_max;
                now_max = 0;
                type = 1;
            }

        }

    }
    return total;
}

int dpp(int start, int end, int minimum){
    int i;
    for(i=start; i<end+1; i++){
        ab_code[i] = ab_code[i] - minimum;
    }
}

int abs(int x){
    if(x >= 0){
        return x;
    }
    else{
        return x*(-1);
    }
}

int min(int a, int b){
    if(abs(a) >= abs(b)){
        return b;
    }
    else{
        return a;
    }
}