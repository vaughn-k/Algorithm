#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main(){
    string st1 = "";
    string st2 = "";
    time_t start,end;
    int n;
    cin >> n;
    int p;
    cout << "s1 test start ~~~~" << endl;
    start = clock();
    for(int i=0;i<n;i++){
        st1 = st1 + 'a';
    }
    end = clock();
    cout << "s1 run time : " << (end-start)/1000000 << endl;

    cout << "s2 test start ~~~~" << endl;
    for(int i=0;i<n;i++){
        st2 = st2.append(1,'a');
    }


    // string st1 = "";
    // string st2 = "";

    // st1 = st1 + 'a';
    // st2 = st2.append(1,'a');

    cout << st1 << endl;
    cout << st2 << endl;

    
}