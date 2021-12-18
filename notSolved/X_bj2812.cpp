#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int n,k;
string s;
int main(){
    cin >> n >> k >> s;
    int left;
    for(int i=0;i<n;i++){
        if(n-i-1 < k){
            k--;
        }
        else{
            if(k > 0){
                if(i == n-1){
                    cout << s[i];
                }
                else{
                    if(s[i] < s[i+1]){
                        k--;
                    }
                    else{
                        cout << s[i];
                    }
                }
            }
            else{
                cout << s[i];
            }
            
        }
    }
}

/*

10 5
9080706050

10 5
9000008765

10 5
9888881111
*/