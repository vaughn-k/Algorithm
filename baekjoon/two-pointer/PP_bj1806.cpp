/*
2h

백준 1806 - 부분합

알고리즘 : 두포인터

문제 개요 : n개의 자연수 배열에서 연속된 수들의 합이 S이상인 부분집합중 길이가 최소일때 그 길이 출력

처음에는 dp로 접근하려 했으나 S이하이기때문에 애매했고 따라서 두 포인터를 이용하여 

1. 0번째 숫자부터 합이 S이상이 되는 수열을 먼저 찾음

2. 그때 길이가 m일때 맨앞의 숫자를 빼고 그다음 숫자를 더해서 진행하다가 총합이 S보다 커질때

맨앞의 숫자를 뺄수있을때까지 계속 뺌

-> 이것이 가능한 이유는 0~n-1까지 돌면서 i번째에 도착했을때의 정의가 i번째원소를 마지막으로 포함했을때 최소 길이

이기 때문에 모든 경우를 포함하고 있기때문임. 
*/

#include <iostream>

using namespace std;

int n,target;
int p[100001];

int main(){
    cin >> n >> target;
    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    int minimum = 99999999; // 합이 S이상인 것중 가장 짧은 길이
    bool notFound = true;
    bool tmp = true;
    int total = 0;
    int s,e;
    s = 0;
    for(int i=0;i<n;i++){ // i 번째를 마지막으로 한 부분합
        if(notFound){ // 합이 S이상인것을 못찾았을때
            total = total + p[i];
            if(total >= target){ // 처음으로 합이 S이상인 것을 찾았을때
                minimum = i-s+1;
                notFound = false;
            }
        }
        else{
            total = total - p[s] + p[i]; // 현재 길이가 x인것을 찾았는데 그 이후로는 길이가 x이상인것은 찾을 필요가 없다.
            s = s + 1;
        }
        if(total >= target){ // 만약 minimum 개씩 합을 확인하다가 타겟보다 커지면
            tmp = true;
            while(tmp){ // 가장 왼쪽부터 하나씩 빼면서 최소길이를 구한다.
                if(total - p[s] >= target){
                    total = total - p[s];
                    s = s + 1;
                    minimum = minimum - 1;
                }
                else{
                    tmp = false;
                }
            }
        }
    }
    if(minimum >= 99999999){
        cout << 0;
    }
    else{
        cout << minimum;
    }
}

