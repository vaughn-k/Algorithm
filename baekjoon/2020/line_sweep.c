#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct POSI{
    int x;
    int y;
}Posi;

Posi p[500001];

int sl(int s, int e);
int min(int x, int y);
int length(int i, int j);

int cmp(const void* a, const void* b){
    Posi* ptrA = (Posi*)a;
    Posi* ptrB = (Posi*)b;

    if (ptrA->x < ptrB->x) return -1;
    else if (ptrA->x == ptrB->x) return 0;
    else return 1;

}

int n;
int main(){
    int i;

    // scanf("%d",&n);
    // for(i=0;i<n;i++){
    //     scanf("%d %d",&p[i].x,&p[i].y);
    // }
    // int ans;
    // qsort(p,n,sizeof(Posi),cmp);
    // for(i=0;i<n;i++){
    //     printf("%d %d\n",p[i].x,p[i].y);
    // }

    // ans = sl(0,n-1);
    // printf("%d",ans);
    int m;
    int tmp;
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++){
        m = rand()%2;
        if(m == 1){
            tmp = rand()%10000;
        }
        else{
            tmp = rand()%10000 * (-1);
        }
        p[i].x = tmp;
        m = rand()%2;
        if(m == 1){
            tmp = rand()%10000;
        }
        else{
            tmp = rand()%10000 * (-1);
        }
        p[i].y = tmp;
    }
    printf("sort start\n");
    qsort(p,n,sizeof(Posi),cmp);

    for(i=0;i<n;i++){
        printf("%d %d\n",p[i].x,p[i].y);
    }


    // scanf("%d",&n);
    // for(i=0;i<n;i++){
    //     scanf("%d %d",&p[i].x,&p[i].y);
    // }
    // for(i=0;i<n;i++){
    //     printf("%d %d\n",p[i].x,p[i].y);
    // }

    int ans;
    ans = sl(0,n-1);
    printf("%d",ans);
    
}

int sl(int s, int e){
    int i,j;
    int minimum;
    int check = 1;
    minimum = length(0,1);
    for(i=0;i<=n-2;i++){
        j = i+1;
        check = 1;
        while(check && j < n){
            if((p[j].x-p[i].x)*(p[j].x-p[i].x) < minimum){
                if((p[j].y-p[i].y)*(p[j].y-p[i].y) < minimum){
                    minimum = min(minimum,length(i,j));
                }
            }
            else{
                check = 0;
            }
            j++;
        }
    }
    return minimum;
}

int min(int x, int y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
}

int length(int i, int j){
    return (p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y);
}


