#include <iostream>
#include <algorithm>

using namespace std;

int t,k;
int file[501];
int store[501][501];

void clear_store(){
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            store[i][j] = 0;
        }
    }
}

void find_file_matrix(){
    int i;
    int j;
    int minimum = 2000000000;
    for(int now=1;now<k;now++){
        i = 0;
        j = now;
        for(int count=0;count<(k-now);count++){
            // cout << "i,j = " << i << "|" << j << endl;

            // cout << "[" << i << " " << j << "] ";
            if(now == 1){
                store[i][j] = file[i] + file[j];
            }
            else{
                for(int control=j; control>i; control--){
                    // cout << "[" << i << "][" << control-1 << "] - ";
                    // cout << "[" << control << "][" << j << "]" << endl;
                    if(control == j){ // DP[0][3] * 2 + M[4]
                        minimum = min(minimum, store[i][control-1] * 2 + file[control]);
                    }
                    else if(control == i+1){ //  M[0] + DP[1][4] * 2
                        minimum = min(minimum, file[control-1] + store[control][j] * 2 );
                    }
                    else{
                        minimum = min(minimum, store[i][control-1] * 2 + store[control][j] * 2);
                    }
                }
                // cout << endl;
                store[i][j] = minimum;
                minimum = 2000000000;
            }
            i++;
            j++;
        }
        // cout << endl;
    }
    // cout << endl;
}

void print(){
    cout << "-=-=-=-=-=-=-=" << endl;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout << store[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-=-=-=-=-=-=-=" << endl;
}

int main(){
    cin >> t;
    while(t>0){
        cin >> k;
        clear_store();
        for(int i=0;i<k;i++){
            cin >> file[i];
        }
        find_file_matrix();
        print();

        cout << store[0][k-1] << endl;
        t--;
    }
}
