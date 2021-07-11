/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.07.11

소요시간 : 재도전 23m

문제명 - 백준 1915 - 가장 큰 정사각형
   
알고리즘
    - bottomUp DP

문제개요
    1 또는 0으로 채워진 nxm 격자판이 주어지고, 1로 만들어진 가장 큰 정사각형의 크기를 출력
    (단 내부까지 1로 채워져야 인정)

    특정지점 (i,j)에서 가장 큰 정사각형을 구할때 나에게 필요한 정보는
    1. (i+1,j) 에서 만들 수 있는 가장 큰 정사각형크기 = p
    2. (i,j+1) 에서 만들 수 있는 가장 큰 정사각형크기 = q
    3. (i+min(p,q)) (j+min(p,q)) 가 1인지
    4. (i,j) 지점이 1인지
    이 4가지 이다.

    최대 (i+1,j), (i,j+1)에서 만들수 있는 정사각형중 작은 것보다 2이상 초과할 수 없다.

    점화식으로 정리하면
    - d[i][j] = (i,j)를 정사각형의 맨위맨왼쪽 점 이라고 했을때, 만들 수 있는 가장큰 정사각형의 
    한변의 길이
    - k = min(d[i+1][j],d[i][j+1]) 
    라고 할때

    d[i][j] = k + v[i+k][j+k]

    ** v[i+k][j+k]가 1이면 1, 0이면 0
    

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,m;
vector<string> v;
int d[1001][1001];

int main(){
    string s;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    
    int maxi = 0;
    int ableMax;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '1'){
                d[i][j] = 1;
                maxi = 1;
            }
            else{
                d[i][j] = 0;
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(v[i][j] != '0' && d[i][j+1] != 0 && d[i+1][j] != 0){
                ableMax = min(d[i][j+1],d[i+1][j]);
                if(v[i+ableMax][j+ableMax] == '1'){
                    d[i][j] = ableMax+1;
                }
                else{
                    d[i][j] = ableMax;
                }
                if(maxi < d[i][j]){
                    maxi = d[i][j];
                }
            }
        }
    }
    maxi = maxi * maxi;
    cout << maxi;
}
