/* 1h

백준 1629번 - 곱셈

알고리즘 분류 - 거듭제곱을 이용한 곱셈

a^m = (a^m/2)^2 로 나누어 곱셈의 횟수를 log 수준으로 줄여 시간을 단축하여 해결

*/

#include <iostream>
#include <stack>

using namespace std;
stack<int> s;

unsigned long long  a,b,c,tmp,ans;

int main(){
    cin >> a >> b >> c;
    tmp = b;
    
    while(tmp != 1){
        if(tmp%2 == 1){ // 홀수
            tmp = tmp - 1;
            s.push(1);
        }
        else{
            tmp = tmp/2;
            s.push(0);
        }
    }
    ans = a;
    while(s.size() > 0){
        if(s.top() == 0){
            ans = ans * ans % c;
        }
        else{
            ans = ans * a  % c;
        }
        s.pop();
    }

    cout << ans % c;

}