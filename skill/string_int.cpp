#include <string>
#include <vector>
#include <iostream>

using namespace std;

string f1(string input){ // 대문자를 소문자로 치환
    string output = ""; // 새로만들 문자열은 항상 초기화해두자
    int t; // 문자의 아스키코드값
    char c; // 해당문자 char
    for(int i=0;i<input.size();i++){
        t = input[i];
        if(t >= 65 && t <= 90){
            t = t + 32;
        }
        c = t;
        output += c;
    }
    return output;
}

void change(){
    int beforeInt = 1000;
    long long beforeLonglong = 10000000000;
    string beforeString = "20000";

    int afterInt;
    long long afterLonglong;
    string afterString;
    // int, long -> string

    afterString = to_string(beforeInt);
    cout << "string : " << afterString << endl;

    afterString = "";
    afterString = to_string(beforeLonglong);
    cout << "string : " << afterString << endl;



    // string -> int, long
    afterLonglong = stoll(beforeString);
    cout << "longlong : " << afterLonglong << endl;

    afterInt = stoi(beforeString);
    cout << "int : " << afterInt << endl;


}


int main(){
    // cout << f1("ABCDE") << endl;
    change();
}