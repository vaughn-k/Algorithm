#include <stdio.h>

int n,t;
int seq[21] = {0};
int door(int now, int o1, int o2);  
int abs(int x);
int min(int x, int y);

int main(){
    int i,state,tmp,o1,o2;
    scanf("%d %d %d %d",&n,&o1,&o2,&t);
    state = (1<<o1) + (1<<o2);
    for(i=0;i<t;i++){
        scanf("%d",&seq[i]);
    }
    printf("%d",door(0,o1,o2));
}

int door(int now, int o1, int o2){
    int move;
    if(now == t){
        return 0;
    }

    if(seq[now] == o1 || seq[now] == o2){
        return door(now+1,o1,o2);
    }

    if((seq[now]-o1)*(seq[now]-o2) > 0){ // 열어야하는 문기준으로 열려있는 문이 둘다 같은 방향에 있음
        if(abs(seq[now]-o1) < abs(seq[now]-o2)){
            move = abs(seq[now]-o1);
            return move + door(now+1, seq[now],o2);    
        }
        else{
            move = abs(seq[now]-o2);
            return move + door(now+1,o1,seq[now]);    
        }
    }
    else{ // 열어야하는 문기준으로 열려있는 문이 다른방향에 있음
        return min(abs(seq[now]-o2)+door(now+1,o1,seq[now]),abs(seq[now]-o1)+door(now+1,seq[now],o2));
    }
}

int abs(int x){
    return x < 0 ? x*(-1) : x;
}

int min(int x, int y){
    return x < y ? x : y;
}