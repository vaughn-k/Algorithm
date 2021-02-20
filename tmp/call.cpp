#include <iostream>
#include <cstdlib>

using namespace std; 
int count1 = 0;
int count2 = 0;


int half_cut(int n, int count){
    count1++; 
    if(n == 1){
        return 0;
    }
    // for(int i=0;i<=count;i++){
    //     cout << "+";
    // }
    // cout << "half_cut(";
    // cout << n;
    // cout << ")" << endl;
    if(n % 2 == 1){
        half_cut((n-1)/2, count+1);
        half_cut((n-1)/2+1, count+1);
    }
    else{
        half_cut(n/2, count+1);
    }
}

int one_cut(int n, int count){
    count2++;
    if(n == 1){
        return 0;
    }
    // for(int i=0;i<=count;i++){
    //     cout << "+";
    // }
    // cout << "one_cut(";
    // cout << n;
    // cout << ")" << endl;
    if(n % 2 == 1){
        one_cut(n-1, count+1);
        // cout << "(";
        // cout << n;
        // cout << ")" << endl;
    }
    else{
        one_cut(n/2, count+1);
    }
}

int main(){
    int input;
    cin >> input;
    half_cut(input, 0);
    cout << endl;
    one_cut(input, 0);

    cout << "count1 = ";
    cout << count1 << endl;
    cout << "count2 = ";
    cout << count2 << endl;
}