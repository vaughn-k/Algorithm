#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,k;
string s;
int check[500001];

int ret(int x){
    return s[x] - 48;
}

int findNew(int x, int end){
    for(int i = x+1; i<n; i++){
        if(ret(i) == -1 && i != end){
            return i;
        }
    }
}

int main(){
    cin >> n >> k >> s;
    
    int left = k;
    int start,end;
    int tmp;
    bool sameDelete = false;
    for(int i=0;i<n;i++){
        check[i] = -1; // 미정
    }
    start = 0;
    end = 1;

    for(int i=1;i<n;i++){
        if(left > 0){
            if(n-end == left){
                sameDelete = true;
            }

            if(ret(start) > ret(end)){
                check[end] = 0;
                end++;
                left--;
            }
            else if(ret(start) < ret(end)){
                check[start] = 0;
                start = findNew(start,end);
                if(end > start){
                    tmp = start;
                    start = end;
                    end = tmp;
                }
                left--;
            }
            else{
                if(sameDelete){
                    check[end] = 0;
                    end++;
                    left--;
                }
                else{
                    end++;
                }
            }
        }
        else{
            break;
        }
        // cout << "std : " << standard << " | index : " << standardIndex << endl;
        // cout << "check[" << i << "] : " << check[i] << endl;
    }
    check[start] = 1;
    check[end] = 1;


    for(int i=0;i<n;i++){
        cout << "i : " << i << " : " << check[i] << endl;;
    }
    for(int i=0;i<n;i++){
        if(check[i] != -1){
            cout << s[i];
        }
    }
}


/*

10 4
1111999999

*/