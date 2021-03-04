#include <iostream>
#include <string>
#include <stack>

using namespace std;

int d[1002][1002];
stack<char> s;

int main(){
    string s1;
    string s2;
    cin >> s2;
    cin >> s1;
    int len = s1.size();
    int p1,p2;
    // p1 : 현재 s1의 인덱스
    // p2 : 현재 s2의 인덱스

    for(int i=0;i<len+1;i++){
        for(int j=0;j<len+1;j++){
            if(i == 0 || j == 0){
                d[i][j] = 0;
            }
            else{
                p1 = i-1;
                p2 = j-1;
                if(s1[p1] == s2[p2]){
                    d[i][j] = d[i-1][j-1] + 1;
                }
                else{
                    d[i][j] = max(d[i-1][j],d[i][j-1]);
                }
            }
        }
    }
    cout << d[len][len] << endl;
    int x,y;
    x = len;
    y = len;
    int now = d[len][len];
    while(d[y][x] != 0){
        // cout << "y : " << y << " | x : " << x << endl;
        if(d[y-1][x] == d[y][x-1]){
            // cout << x;
            // cout << s2[x-1];
            s.push(s2[x-1]);
            if(x == 1){
                y = y - 1;
            }
            else{
                x = x - 1;
                y = y - 1;
            }
        }
        else{
            if(x == 1){
                y = y - 1;
            }
            else{
                x = x - 1;
            }
        }
    }
    while(s.size() > 0){
        cout << s.top();
        s.pop();
    }
}