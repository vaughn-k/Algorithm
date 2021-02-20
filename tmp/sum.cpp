#include <iostream>
#include <cstdlib>

using namespace std;

int PureSum(int n){
    int i, sum = 0;
    for(i=1;i<=n;i++){
        sum = sum+i;
    }
    return sum;
}

int FastSum(int n){
    if(n == 1){
        return 1;
    }
    if(n%2 == 1){
        return 2*FastSum((n-1)/2) + pow((n-1)/2,2) + n;
    }
    else{
        return 2*FastSum(n/2) + pow(n/2,2);
    }
}

int main(){
    int input;
    cout << "enter number that you want know sum : ";
    cin >> input;
    cout << "PureSum : ";
    cout << "---- start PureSum -----" << endl;
    cout << PureSum(input) << endl;
    cout << "---- end PureSum -----" << endl;
    cout << "FastSum : ";
    cout << "---- start FastSum -----" << endl;
    cout << FastSum(input) << endl;
    cout << "---- end FastSum -----" << endl;
}