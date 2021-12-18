#include <iostream>
#include <cstdlib>

using namespace std;

int t; // 추
int t_arr[30]; // 추 무게 배열
int c; // 구슬개수
int c_arr[7]; // 구슬 배열
int input;
int store[30][15001];
int answer[15001];

int dp(int index, int total);

int main(void){
    
    cin >> input; // 입력받기
    t = input;
    for(int i=0; i<t; i++){
        cin >> input; // 입력받기
        t_arr[i] = input;
    }
    cin >> input; // 입력받기
    c = input;
    for(int i=0; i<c; i++){
        cin >> input; // 입력받기
        c_arr[i] = input;
    }
    // 배열 초기화
    for(int i=0; i<30; i++){
        for(int j=0; j<15001; j++){
            store[i][j] = -1;
        }
    }

    for(int j=0; j<15001; j++){
        answer[j] = -1;
    }


    dp(0,0);
    dp(0,t_arr[0]);

    for(int i=0; i<c; i++){
        if(c_arr[i] > 15000){
            cout << "N ";
        }
        else if(answer[c_arr[i]] == 1){
            cout << "Y ";
        }
        else{
            cout << "N ";
        }
    }

    cout << endl;
    for(int j=1; j<50; j++){
        if(answer[j] == 1){
            cout << 0;
        }
        else{
            cout << 1;
        }
        if(j%10 == 0){
            cout << endl; 
        }

    }

    return 0;
}

int dp(int index, int total){
    store[index][total] = 1;
    answer[total] = 1;

    if(index > t){
        return 0;
    }
    if(store[index+1][total+t_arr[index+1]] == -1){
        dp(index+1,total+t_arr[index+1]);
    }
    if(store[index+1][abs(total-t_arr[index+1])] == -1){
        dp(index+1,abs(total-t_arr[index+1]));
    }
    if(store[index+1][total] == -1){
        dp(index+1,total);
    }
    return 0;
}
