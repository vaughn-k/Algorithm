#include <stdio.h>

char arr[51];

int main(){
    int n,i,j,count;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        count = 0;
        scanf("%s",&arr);
        j = 0;
        if(vps(count)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}

int vps(int count){
    int check = 0;
    int i;
    for(i=0;i<51;i++){
        if(arr[i] == '(' || arr[i] == ')'){
            if(arr[i] == '('){
                check++;
            }
            else{
                check--;
            }
            if(check < 0){
                return 0;
            }
        }
        else{
            break;
        }
    }
    if(check != 0){
        return 0;
    }
    else{
        return 1;
    }
}

