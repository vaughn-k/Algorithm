/*
30m

기본적인 dp - 메모이제이션
-> bottom-up으로 더 간단하게 해결가능하다.

수가 커져서 1000000009 로 나눈값을 출력해야하는데

마지막에 최종적으로 두개 합에서 안나누고 출력해서 시간소모함

*/

#include <iostream>

using namespace std;

int n;
int store[33334][3];

int three(int now, int left){
    if(now == n){
        if(left == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int total;
    if(store[now][left] != -1){
        return store[now][left];
    }
    else{
        total = (three(now+1, (left+1)%3) 
                + three(now+1, (left+2)%3)) % 1000000009;
        total = total + three(now+1,left);
        total = total % 1000000009;
        store[now][left] = total;
    }
    return total;
}

int main(){
    cin >> n;
    for(int i=0;i<33334;i++){
        for(int j=0;j<3;j++){
            store[i][j] = -1;
        }
    }
    cout << (three(1,1) + three(1,2))%1000000009;
}