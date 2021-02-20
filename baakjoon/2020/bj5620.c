#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct POSI{
    int x;
    int y;
}Posi;

Posi p[100001];

int sl(int s, int e);
int min(int x, int y);
int length(int i, int j);
int lower_bound(int s, int e, int min);
int upper_bound(int s, int e, int min);

int cmp(const void* a, const void* b){
    Posi* ptrA = (Posi*)a;
    Posi* ptrB = (Posi*)b;

    if (ptrA->x < ptrB->x) return -1;
    else if (ptrA->x == ptrB->x) return 0;
    else return 1;

}

// int cmp(const void *a, const void *b){
//     return (*(Posi*)a).x > (*(Posi*)b).x;
// }


int n;
int main(){
    int i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    int ans;
    qsort(p,n,sizeof(Posi),cmp);

    ans = sl(0,n-1);
    printf("%d",ans);
    
}

int sl(int s, int e){
    int i,j;
    int now;
    int left,right;
    int left_bound, right_bound;
    int mid;
    int minimum;
    if(e-s == 2){ // 구간안에 점이 3개
        int s1,s2,s3;
        s1 = length(s,s+1);
        s2 = length(s+1,s+2);
        s3 = length(s,s+2);
        return min(s1,min(s2,s3));
    }
    if(e-s == 1){ // 구간안에 점이 2개
        return length(s,e);
    }
    mid = (s+e)/2;
    left = sl(s,mid);
    right = sl(mid,e);
    minimum = min(left,right);
    // now = mid-1;
    // while((p[mid].x - p[now].x)*(p[mid].x - p[now].x) < minimum && now >= s){
    //     now--;
    // }
    // left_bound = now+1;
    // now = mid+1;
    // while((p[now].x - p[mid].x)*(p[now].x - p[mid].x) < minimum && now <= e){
    //     now++;
    // }
    // right_bound = now-1;
    // printf("min : %d\n",minimum);
    // printf("l m r : %d %d %d\n",left_bound,mid,right_bound);
    left_bound = lower_bound(s,mid-1,minimum);
    right_bound = upper_bound(mid+1,e,minimum);
    if(!(left_bound == mid || right_bound == mid)){
        for(i=left_bound;i<mid;i++){
            for(j=mid+1;j<=right_bound;j++){
                // printf("ok\n");
                if(minimum > length(i,j)){
                    minimum = length(i,j);
                }
            }
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

int lower_bound(int s, int e, int min){
    int mid = (s+e)/2;
    int check = 1;
    if(p[e].x * p[e].x > min){
        return e+1;
    }
    while(check){
        if(e == s){
            return s;
        }
        if(e-1 == s){
            if(p[s].x*p[s].x > min){
                return e;
            }
            else{
                return s;
            }
        }
        if(p[mid].x*p[mid].x > min){
            e = mid;
        }
        else{
            s = mid;
        }

    }
}

int upper_bound(int s, int e, int min){
    int mid = (s+e)/2;
    int check = 1;
    if(p[s].x * p[s].x > min){
        return s-1;
    }
    while(check){
        if(e == s){
            return s;
        }
        if(e-1 == s){
            if(p[e].x*p[e].x > min){
                return s;
            }
            else{
                return e;
            }
        }
        if(p[mid].x*p[mid].x > min){
            e = mid;
        }
        else{
            s = mid;
        }

    }
}