/*
45m

백준 1080 - 행렬

알고리즘
    그리디?

문제개요
    1과 0으로 이루어진 n x m 행렬 2개가 주어지고 3x3 씩 1,0을 전체 뒤집을 수 있다.

    이때 최소 몇번 뒤집어야하는지 출력.

    

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,m;

vector<string> s1;
vector<string> s2;

int v1[55][55];
int v2[55][55];

int change(int x){
    if(x == 1){
        return 0;
    }
    else{
        return 1;
    }
}

void inv(int si, int sj){
    for(int i=si;i<si+3;i++){
        for(int j=sj;j<sj+3;j++){
            v1[i][j] = change(v1[i][j]);
        }
    }
}

int main(){
    string tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        s1.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        cin >> tmp;
        s2.push_back(tmp);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s1[i][j] == '1'){
                v1[i][j] = 1;
            }
            else{
                v1[i][j] = 0;
            }
            if(s2[i][j] == '1'){
                v2[i][j] = 1;
            }
            else{
                v2[i][j] = 0;
            }
        }
    }

    int count_ = 0;
    // 맨아래 2줄, 맨오르쪽 2줄을 제외한 모든값 맞추기
    int to,tx;
    if(n < 3 || m < 3){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v1[i][j] != v2[i][j]){
                    cout << -1;
                    return 0;
                }
            }
        }
        cout << 0;
        return 0;
    }
    
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(v1[i][j] != v2[i][j]){
                inv(i,j);
                count_++;
            }
        }
    }

    // 맨아래 2줄 맞는지 확인
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v1[i][j] != v2[i][j]){
                cout << -1;
                return 0;
            }
        }
    }

    // 맨오른쪽 2줄 맞는지 확인
    for(int i=0;i<n;i++){
        for(int j=m-2;j<m;j++){
            if(v1[i][j] != v2[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << count_;
}