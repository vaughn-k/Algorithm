#include <stdio.h>
#include <stdlib.h>

/*
의견 : 전형적인 DP문제로 총횟수 | 최대,최소 중 최대값을 묻는 문제로써 합계를 return해주고 결과를 answer에 저장하면서
진행한다. 앞뒤 상황이 독립이므로 1차원 answer로 충분하다.
물건의 개수가 무한정한 0/1 kanpsack 문제와 비슷하다. 
그러나 효율순으로 정렬하지않고 돌려도 무방한듯하다.
어떤 순서로 정렬하던지 어차피 끝까지 돌아야하기에 그 순서는 중요하지 않은듯하다.

if문내의 answer[] 이 안의 index를 잘못써놔서 몇시간을 헤맸다
생각하면서 코딩해야한다;
*/

int main(){
    int answer[1001];
    int pack[1001];
    int i,j,n;

    scanf("%d",&n);
    for(i=1;i<n+1;i++){
        scanf("%d",&pack[i]);
    }


    for(i=0;i<n+1;i++){
        answer[i] = 0;
    }

    printf("%d",dynamic_card(answer,pack,n,0));

    // for(i=0;i<n+1;i++){
    //     printf("pack[%d] : %d\n",i,pack[i]);
    // }
    // for(i=0;i<n+1;i++){
    //     printf("answer[%d] : %d\n",i,answer[i]);
    // }

}

int dynamic_card(int answer[], int pack[], int now, int count){
    int max = -10000;
    int tmp;
    if(now == 0){
        return 0;
    }

    if(now == 1){
        return pack[1];
    }


    for(int i=0;i<now;i++){ // now-i : 한번에 살 카드수 0~now
        if(answer[i] != 0){
            tmp = pack[now-i] + answer[i];
        }
        else{
            tmp = pack[now-i] + dynamic_card(answer,pack,i,count+1);
        }
        // for(int i=0;i<count;i++){
        //     printf("   ");
        // }
        // printf("now : %d | 산카드수 : %d | tmp : %d\n",now,now-i,tmp);
        if(tmp > max){
            max = tmp;
        }
    }
    answer[now] = max;
    return max;
}