#include <iostream>
#include <string>

using namespace std;
string a;



// 확인 연산 n번째에 1이 있는가?
bool check(int input, int index){
    int move = 1;
    move = move << index;
    int ans = input & move;
    if(ans > 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // int a,b;
    // a = 10;
    // b = 10;
    // a = a << 1;
    // cout << a;
    // b = b >> 1;
    // cout << b;
    // for(int i=0;i<=4;i++){
    //     cout << check(1,i) << endl;
    // }
    string a = "abcde";
    a = a+'b';
    cout << a;
}
