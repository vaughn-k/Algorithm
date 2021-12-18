/*
1h+

백준 1744 - 수 묶기

알고리즘
    - 그리디
    - 반례찾기

문제개요

반례찾기가 힘들었던 문제.

--------------------------------------------------------------------
case1. 양수기준 - (양수가 짝수개일때) 내림차순으로 정렬했을때 큰값 2개씩 곱해서 답을 도출하는가
input : 4 9 4 2 7
output : 71
--------------------------------------------------------------------
case2. 양수기준 - (양수가 홀수개일때) 내림차순으로 정렬했을 때 큰값 2개씩 곱한 후 마지막에 숫자를 더해서 답을 도출하는가
input : 7 9 7 4 2 8 8 7
output : 158
--------------------------------------------------------------------
case3. 음수기준 - 오름차순으로 정렬했을때 작은값 2개씩 묶어서 답을 도출하는가 (이유 : 음수는 작을수록 두 수를 곱했을때 커지므로)
input : 4 -9 -11 -2 -4
output : 107
--------------------------------------------------------------------
case4. 0이 존재하면서 음수의 개수가 홀수개 일때 마지막 음수를 0으로 처리하는지
input : 8 -10 -5 0 0 0 -11 -9 -2
output : 155
--------------------------------------------------------------------
case5. 1이 존재할때 1은 다른수와 곱하지 않고 바로 더하는지 (이유 : 1보다 큰 수 x와 1이 주어진다면 두수를 곱하는것보다 따로 더해주는게 더 크다)
input : 5 5 4 1 1 1
output : 23
--------------------------------------------------------------------

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vp;
vector<int> vm;
int n;

int main(){
    int tmp, total;
    int p,m,z,o;
    cin >> n;
    p = 0, m = 0, z = 0, o = 0;

    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp == 1){
            o++;
        }
        else if(tmp > 0){
            p++;
            vp.push_back(tmp);
        }
        else if(tmp < 0){
            m++;
            vm.push_back(tmp);
        }
        else{
            z++;
        }
    }
    int c;
    int t = 0;
    total = 0;
    if(p > 0){
        sort(vp.begin(), vp.end(), greater<int>());
        c = p/2;
        // 양수 계산
        for(int i=0;i<c;i++){
            t = i * 2;
            total = total + vp[t] * vp[t+1];
        }
        if(p%2 == 1){
            total = total + vp[p-1];
        }
    }
    if(m > 0){
        // 음수 계산
        sort(vm.begin(), vm.end());
        c = m/2;
        t = 0;
        for(int i=0;i<c;i++){
            t = i * 2;
            total = total + vm[t] * vm[t+1];
        }
        if(m%2 == 1){
            if(z <= 0){
                total = total + vm[m-1];
            }
        }
    }
    total = total + o;

    cout << total;
}