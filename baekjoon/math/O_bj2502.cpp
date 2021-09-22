// 12m

// 피보나치 원리로 호랑이에게 떡을 줘야 무사히 넘어갈때, 몇일째인지 d, 그날 준개수 k개를 통해 1,2일째에 몇개줬었는지 구하는 문제
// 피보나치 활용.. 이라기보단 기본 수학적 지식

#include <iostream>

using namespace std;

int d,k;

int find_ab(){
    int x,y;
    int tmp;
    x = 1, y = 1;

    for(int day = 3; day<d; day++){
        tmp = x;
        x = y;
        y = tmp+y;
    }

    // cout << x << endl;
    // cout << y << endl;
    int ct = 1;
    int check = 0;
    while(check == 0){
        if((k - (x * ct)) % y == 0){
            cout << ct << endl;
            cout << (k - (x * ct)) / y;
            return 0;
        }
        ct++;
    }
    return 0;
}

int main(){
    cin >> d;
    cin >> k;

    find_ab();
}