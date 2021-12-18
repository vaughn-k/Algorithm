// 1

// 10m

// 취약점. 앞의 최소의 문자만을 비교하기 때문에 정상적인 입력이 아닐때 에러발생할 수 있다.
// -> 해결 위해서는 모든 문자를 모두 검사하고, 10개의 문자가 모두 아닐때의 경우도 고려해서 설계해야한다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
zero
one
two three
four five
six seven
eight
nine

*/

int solution(string s) {
    int answer = 0;
    int index = 0;
    string tmp;
    while(index < s.size()){
        if(s[index] != 'z' && s[index] != 'o' && s[index] != 't' && s[index] != 'f' && s[index] != 's' && s[index] != 'e' && s[index] != 'n'){
            tmp = "";
            tmp = tmp + s[index];
            answer = answer * 10 + stoi(tmp);
            index++;
        }
        else{
            if(s[index] == 'z'){ // zero
                answer = answer * 10;
                index = index + 4;
            }
            else if(s[index] == 'o'){ // one
                answer = answer * 10 + 1;
                index = index + 3;
            }
            else if(s[index] == 'e'){ // eight
                answer = answer * 10 + 8;
                index = index + 5;
            }            
            else if(s[index] == 'n'){ // nine
                answer = answer * 10 + 9;
                index = index + 4;
            }            
            else if(s[index] == 'f'){ // four / five
                if(s[index+1] == 'o'){ // four
                    answer = answer * 10 + 4;
                    index = index + 4;
                }
                else{
                    answer = answer * 10 + 5;
                    index = index + 4;
                }
            }
            else if(s[index] == 's'){ // six / seven
                if(s[index+1] == 'i'){ // six
                    answer = answer * 10 + 6;
                    index = index + 3;
                }
                else{ // seven
                    answer = answer * 10 + 7;
                    index = index + 5;
                }
            }
            else if(s[index] == 't'){ // two / three
                if(s[index+1] == 'w'){ // two
                    answer = answer * 10 + 2;
                    index = index + 3;
                }
                else{ // three
                    answer = answer * 10 + 3;
                    index = index + 5;
                }
            }
        }
        
    }
    
    return answer;
}

int main(){
    cout << solution("onetwothre");
}