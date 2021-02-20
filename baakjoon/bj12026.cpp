/*
20m

기본적인 dp 메모이제이션

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;
int store[1001];

char next_BOJ(char c){
    if(c == 'B'){
        return 'O';
    }
    else if(c == 'O'){
        return 'J';
    }
    else{
        return 'B';
    }
}

int BOJ_load(int now){
    if(now == n-1){
        return 0;
    }
    char c = next_BOJ(s[now]);
    int minimum = 99999999;
    if(store[now] != -1){
        minimum = store[now];
    }
    else{
        for(int i=now+1; i<s.size();i++){
            if(s[i] == c){
                minimum = min(minimum, BOJ_load(i) + (i-now)*(i-now));
                // cout << minimum << endl;
            }
        }
        store[now] = minimum; 
    }
    return minimum;
}

int main(){
    cin >> n;
    cin >> s;
    for(int i=0;i<1000;i++){
        store[i] = -1;
    }
    int answer = BOJ_load(0);
    if(answer >= 99999999){
        cout << -1;
    }
    else{
        cout << answer;
    }
}