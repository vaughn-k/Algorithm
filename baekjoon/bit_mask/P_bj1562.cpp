/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.01.22

소요시간 : 1h 46m

문제명 - 백준 1562 계단 수

알고리즘
    - dp / bitmask

문제개요
    설계는 거의 1시간전에 끝났는데 잡다한 오류로 굉장히 시간 잡아먹음..;;

    함수의 끝 조건
    if(index == N-1) 을 if(index == N) 으로해서 개고생했다.

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cmath>


using namespace std;
int N;
int dp[101][10][1024];
/* dp[현재 index][현재 number][현재 history]
dp = -1 : 아직 방문전
dp = 0 : 불가능
dp = 양수 : 해당개수만큼 가능
*/

// make_history(history, number) = history에 number를 이진수로 넣어준값을 리턴해줌
int make_history(int history, int number){
    int store = history;
    int i;
    history = history >> number;
    if(history % 2 == 1){
        return store;
    }
    else{
        return store + pow(2,number);
    }
}

unsigned long long chair_num(int index, int number, int history){
    // index : 현재 몇번째 숫자를 배정중인지
    // number : 현재 배정된 숫자
    // history : 현재까지 배정된 숫자
    if(index == N-1){
        if(history == (pow(2,10)-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[index][number][history] != -1){
        return dp[index][number][history];
    }
    unsigned long long total = 0;
    if(number == 0){
        total = total + 
        chair_num(index+1, number+1, make_history(history, number+1));
    }
    else if(number == 9){
        total = total + 
        chair_num(index+1, number-1, make_history(history, number-1));
    }
    else{
        total = total 
        + chair_num(index+1, number+1, make_history(history, number+1))
        + chair_num(index+1, number-1, make_history(history, number-1));
    }
    total = total % 1000000000;
    dp[index][number][history] = total;
    return total;
}

unsigned long long chair_num_control(){
    int i;
    unsigned long long total = 0;
    for(i=1;i<10;i++){
        total = total + chair_num(0,i,pow(2,i));
    }
    total = total % 1000000000;
    return total;
}

int main(){
    cin >> N;
    int i,j,k;
    for(i=0;i<N;i++){
        for(j=0;j<10;j++){
            for(k=0;k<1024;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << chair_num_control();

    return 0; 
}


xxxxxxxxxx
o.o.o.o.o.
o.o.o.o.o.
..........
xxxxxxxxxx
..........
xxxxxxxxxx
.........x
...x......
........x.
xxxxxxxxxx