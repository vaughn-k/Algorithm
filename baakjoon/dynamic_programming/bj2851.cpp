#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main(){
    for(int i=0;i<10;i++){
        cin >> arr[i];
    }

    int check = 1;
    int now = 0;
    int next = 0;
    int k = 0;
    while(check == 1){
        next = now + arr[k];
        if(abs(100-next) <= abs(100-now)){
            now = next;
        }
        else{
            check = 0;
        }
        k++;
    }
    cout << now; 
}