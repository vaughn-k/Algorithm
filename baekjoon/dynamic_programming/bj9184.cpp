#include <iostream>

using namespace std;

int store[21][21][21];


int w(int a, int b, int c){
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    if(a <= 0 or b <= 0 or c <= 0){
        return 1;
    }
    if(a > 20 or b > 20 or c > 20){
        return w(20, 20, 20);
    } 
    if(a < b && b < c){
        if(store[a][b][c-1] != 0){
            tmp1 = store[a][b][c-1];
        }
        else{
            tmp1 = w(a, b, c-1);
        }
        if(store[a][b-1][c-1] != 0){
            tmp2 = store[a][b-1][c-1];
        }
        else{
            tmp2 = w(a, b-1, c-1);
        }
        if(store[a][b-1][c] != 0){
            tmp3 = store[a][b-1][c];
        }
        else{
            tmp3 = w(a, b-1, c);
        }
        store[a][b][c] = tmp1+tmp2-tmp3;
        return  tmp1 + tmp2 - tmp3;
    }

    if(store[a-1][b][c] != 0){
        tmp1 = store[a-1][b][c];
    }
    else{
        tmp1 = w(a-1, b, c);
    }

    if(store[a-1][b-1][c] != 0){
        tmp2 = store[a-1][b-1][c];
    }
    else{
        tmp2 =w(a-1, b-1, c);
    }

    if(store[a-1][b][c-1] != 0){
        tmp3 = store[a-1][b][c-1];
    }
    else{
        tmp3 = w(a-1, b, c-1);
    }

    if(store[a-1][b-1][c-1] != 0){
        tmp4 = store[a-1][b-1][c-1];
    }
    else{
        tmp4 = w(a-1, b-1, c-1);
    }
    store[a][b][c] = tmp1 + tmp2 + tmp3 - tmp4;
    return tmp1 + tmp2 + tmp3 - tmp4;
}

int main(){
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            for(int k=0;k<21;k++){
                store[i][j][k] = 0;
            }
        }
    }
    int input1,input2,input3;
    cin >> input1;
    cin >> input2;
    cin >> input3;
    while(!(input1 == -1 && input2 == -1 && input3 == -1)){
        cout << "w(" << input1 << ", " << input2 << ", " << input3 << ") = " <<  w(input1,input2,input3) << endl;
        cin >> input1;
        cin >> input2;
        cin >> input3;
    }
}
