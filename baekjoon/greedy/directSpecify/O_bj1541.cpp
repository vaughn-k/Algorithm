/*

백준 1541 - 잃어버린 괄호

그리디 - 숫자와 +- 기호가 나오고 중간에 괄호를 넣어서 가장 최소가 되는값 구하기

한번 -가 나오면 그 이후+들은 모두 괄호로 묶어 -로 만들수 있고 -후에 -가 나오면 계속해서 뺄수 있으므로

첫 -가 나온후부터는 모든 숫자를 다 뺄수있다.

아래코드에서는 조금 복잡하게되어있지만 위처럼 바꾼다면 더 간결해질것이다.

*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string s;
vector<int> vn;
vector<char> vc;

void parse_(){
    int start = 0;

    // 0 = 숫자 / 1 = 문자
    for(int i=0;i<s.size();i++){
        if(s[i] == '+' || s[i] == '-'){
            vn.push_back(stoi(s.substr(start,i-start)));
            vc.push_back(s[i]);
            start = i+1;
        }
        if(i == s.size()-1){
            vn.push_back(stoi(s.substr(start,i-start+1)));
        }
    }    
}

int main(){
    cin >> s;
    parse_();

    int tot = vn[0];
    bool nowMinus = false;
    for(int i=0;i<vc.size();i++){
        if(nowMinus){ 
            if(vc[i] == '-'){ // - -
                tot = tot - vn[i+1];
                nowMinus = true;
            }
            else{ // - +
                tot = tot - vn[i+1];
            }
        }
        else{
            if(vc[i] == '-'){ // + -
                tot = tot - vn[i+1];
                nowMinus = true;
            }
            else{ // + +
                tot = tot + vn[i+1];
            }
        }
    }
    cout << tot;
}
