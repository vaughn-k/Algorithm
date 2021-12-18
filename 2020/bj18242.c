#include <stdio.h>

char arr[101][101];
int si,sj;
int n,m;
int find();
int ul();

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",&arr[i]);
    }
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         printf("%c",arr[i][j]);
    //     }
    //     printf("\n");
    // }
    find();
    ul();
}

int find(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j] == '#'){
                si = i;
                sj = j;
                return 0;
            }
        }
    }
}

int ul(){
    int i,j;
    int k = 1;
    while(si+k < n && sj+k < m){
        if(arr[si+k][sj] == '#' && arr[si][sj+k] == '.'){
            printf("UP");
            return 0;
        }
        if(arr[si+k][sj] == '.' && arr[si][sj+k] == '#'){
            printf("LEFT");
            return 0;
        }
        if(arr[si+k][sj] == '.' && arr[si][sj+k] == '.'){
            break;
        }
        k++;
    }
    k = k-1;
    int t = 1;
    while(si+t < n && sj+t < m){
        if(arr[si+k][sj+t] == '#' && arr[si+t][sj+k] == '.'){
            printf("RIGHT");
            return 0;
        }
        if(arr[si+k][sj+t] == '.' && arr[si+t][sj+k] == '#'){
            printf("DOWN");
            return 0;
        }
        t++;
    }
    printf("what?");
}