/*
35m

원래는 그래프나 위상정렬? 이런거 이용하는거같은데
그냥 brute-force 로도 해결

*/

#include <iostream>

using namespace std;

int k;
char c[10];
int v[10];
int d[10];

bool check(int a, int b, char t){
    if(t == '<'){
        return a<b;
    }
    else{
        return a>b;
    }
}

int go_max(int count, int index){
    if(count == k){
        return 1;
    }
    for(int i=9;i>=0;i--){
        if(v[i] == -1 && check(index,i,c[count])){
            v[i] = 1;
            d[count+1] = i; 
            if(go_max(count+1,i) == 1){
                return 1;
            }
            v[i] = -1;
        }
    }
    return 0;
}

int go_min(int count, int index){
    if(count == k){
        return 1;
    }
    for(int i=0;i<=9;i++){
        if(v[i] == -1 && check(index,i,c[count])){
            v[i] = 1;
            d[count+1] = i; 
            if(go_min(count+1,i) == 1){
                return 1;
            }
            v[i] = -1;
        }
    }
    return 0;
}

int main(){
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> c[i];
    }
    for(int i=0;i<=9;i++){
        v[i] = -1;
    }

    for(int i=9;i>=0;i--){
        d[0] = i; 
        v[i] = 1;
        if(go_max(0,i) == 1){
            break;
        }
        v[i] = -1;
    }

    for(int i=0;i<k+1;i++){
        cout << d[i];
    }
    cout << endl;


    for(int i=0;i<=9;i++){
        v[i] = -1;
    }
    for(int i=0;i<=9;i++){
        d[0] = i; 
        v[i] = 1;
        if(go_min(0,i) == 1){
            break;
        }
        v[i] = -1;
    }

    for(int i=0;i<k+1;i++){
        cout << d[i];
    }
}