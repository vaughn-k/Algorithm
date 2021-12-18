/*
33m

- DFS
- int[] 파라미터로 달고다니기

격자판 이동에서 현재까지 이동상태를 int 배열에 저장하면 되는 문제.

알파벳은 26개인데 21개라고 실수하는 바람에 시간지연
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int r,c;
string input;
vector<string> v;

int go(int x, int y, int arr[]){
    if(x >= 0 && x < r && y >= 0 && y < c){ // 유효한 범위
        if(arr[v[x][y]-65] == 0){ // 해당 문자 방문이력 없음
            return 1;
        }
    }
    return 0;
}

int search(int x, int y, int arr[]){
    // cout << x << " " << y << endl;
    int maximum = 1;
    if(go(x+1,y,arr) == 1){
        arr[v[x+1][y]-65] = 1;
        maximum = max(search(x+1,y,arr)+1,maximum);
        arr[v[x+1][y]-65] = 0;
    }
    if(go(x-1,y,arr) == 1){
        arr[v[x-1][y]-65] = 1;
        maximum = max(search(x-1,y,arr)+1,maximum);
        arr[v[x-1][y]-65] = 0;
    }
    if(go(x,y+1,arr) == 1){
        arr[v[x][y+1]-65] = 1;
        maximum = max(search(x,y+1,arr)+1,maximum);
        arr[v[x][y+1]-65] = 0;
    }
    if(go(x,y-1,arr) == 1){
        arr[v[x][y-1]-65] = 1;
        maximum = max(search(x,y-1,arr)+1,maximum);
        arr[v[x][y-1]-65] = 0;
    }
    return maximum;
}

int main(){

    int alph[26];
    cin >> r;
    cin >> c;

    for(int i=0;i<r;i++){
        cin >> input;
        v.push_back(input);
    }
    for(int i=0;i<26;i++){
        alph[i] = 0;
    }

    alph[v[0][0]-65] = 1;
    cout << search(0,0,alph);
}