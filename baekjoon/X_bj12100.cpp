#include <iostream>

using namespace std;

int n;
int borad[21][21];



int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> borad[i][j];
        }
    }
}