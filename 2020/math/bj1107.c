#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
signal SIGSEGV (Address boundary error)
는 정해진 배열을 over했을때 발생한다.
ex) a[100] 으로 선언하고 a[120]에 접근했을때

다양한 경우중에 가장 start가 되는 경우와 last가 되는 경우까지 모두 살펴봐야함.

*/

int make(int answer[], int pos[], int n, int now, int count, int total);
int count_number2(int n);


int main(){
    int answer[999999];
    int target, n;
    int impos[10];
    int pos[10];
    int i,j;
    int final;
    int final2;
    int final3;

    for(i=0;i<999901;i++){
        answer[i] = 0;
    }

    scanf("%d",&target);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&impos[i]);
    }
    
    int check = 0;
    int number = 0;
    for(i=0;i<10;i++){
        check = 0;
        for(j=0;j<n;j++){
            if(i == impos[j]){
                check = 1;
            }
        }
        if(check == 0){
            pos[number] = i;
            number++;
        }
    }
    make(answer, pos, 10-n, 0, 0, 0);
    int min = 1000000;
    int min_i = 0;
    for(i=0;i<999901;i++){
        if(answer[i] == 1){
            if(abs(i-target) < min){
                min_i = i;
                min = abs(i-target);
            }
        }
    }
    final = count_number2(min_i)+min;
    final2 = abs(target-100);

    if(final < final2){
        final3 = final;
    }
    else{
        final3 = final2;
    }
    printf("%d\n",final3);

    return 0;

}

int make(int answer[], int pos[], int n, int now, int count, int total){ // n : 가능한 버튼개수
    int i;
    if(count > 0){
        total = total*10 + now;
        answer[total] = 1;
        if(count == 6){
            return 0;
        }
    }
    for(i=0;i<n;i++){
        make(answer, pos, n, pos[i], count+1, total);
    }

}

int count_number2(int n){
    if(n < 10){
        return 1;
    }
    else if(n < 100){
        return 2;
    }
    else if(n < 1000){
        return 3;
    }
    else if(n < 10000){
        return 4;
    }
    else if(n < 100000){
        return 5;
    }
    else{
        return 6;
    }
}
