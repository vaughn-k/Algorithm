/*

23m

백준 2448번 - 별 찍기 - 11

사용 알고리즘 : 재귀

문제 개요 
6
     *     
    * *    
   *****   
  *     *  
 * *   * * 
***** *****

주어진 숫자에 따라 위와같은 규칙을 가지는 도형을 출력하는 문제
처음에는 주어진 숫자에 따라 한줄씩 출력하려 했지만 숫자가 커질수록 그 규칙성을 찾기 힘들어져서
삼각형이 늘어나는 규칙성을 찾아 배열을 이용하여 배열에 채워넣고 마지막에 한번에 출력하는 형식으로 변경

*/

#include <iostream>
#include <string>

using namespace std;

int n;
int level;
int paint[3080][6160];
int di[] = {0,1,1,2,2,2,2,2};
int dj[] = {0,-1,1,-2,-1,0,1,2};

void slice(int i, int j, int level){
    if(level == 3){
        for(int k=0;k<8;k++){
            paint[i+di[k]][j+dj[k]] = 1;
        }
        return;
    }
    else{
        slice(i,j,level/2);
        slice(i+level/2,j-level/2,level/2);
        slice(i+level/2,j+level/2,level/2);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<3080;i++){
        for(int j=0;j<6160;j++){
            paint[i][j] = 0;
        }
    }
    level = n;
    slice(0,n-1,level);

    for(int i=0;i<n;i++){
        for(int j=0;j<=n*2-2;j++){
            if(paint[i][j] == 1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}