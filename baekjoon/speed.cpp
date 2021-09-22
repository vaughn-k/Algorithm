#include <iostream>

using namespace std;

int a = 0;
void run(){
    // cout << a << endl;
    a++;
    if(a > 500000){
        return;
    }
    else{
        run();
    }
}

int main(){
    run();
    a = 0;
    run();
    a = 0;
    run();
}