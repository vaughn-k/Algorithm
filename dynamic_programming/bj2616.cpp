#include <iostream>

using namespace std;

int main(){
    unsigned long long x;
    x = 1;
    int now = 1;
    while(x < 60000000000000){
        x++;
        if(x%60000000 == 0){
            cout << now << "/1000000" << endl;
            now++;
        }
    }
}