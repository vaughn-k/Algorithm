#include <iostream>

using namespace std;

int main(){
    int k;
    int a,b;
    cin >> k;

    for(int i=1;i<k+1;i++){
        cin >> a;
        cin >> b;
        cout << "Case #" << i << ": " << a+b << endl;
    }


}