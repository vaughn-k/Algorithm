/*
30m

백준 3109 - 빵집

알고리즘
    그리디
    경로체크

문제개요
    r by c 배열이 주어지고 첫번째와 마지막 열을 이어야 하는데 왼쪽에서 오른쪽으로 갈때 오른쪽위대각선,오른쪽,오른쪽아래대각선 으로만 갈수있다.
    이때 최대로 만들수있는 경로의 개수 출력

    greedy하게 접근했을때 최대한 겹치지 않게 많은 파이프를 만들기 위해서는 맨위에 부터 봤을때 최대한 위로 붙어서 진행해야 할것이다.
    또한 이렇게만 설계할경우 모든 경우를 다 돌아봐야하기에 시간초과가 발생한다.

    따라서 이미 한번 갔던 경로는 다시 방문해볼 필요가 없다.

    왜냐하면 특정 지점 (x,y)를 지났을때 경로가 완성되었다면 당연히 다시 갈수도 없지만,
    만약 해당 경로를 지나서 경로를 만들지 못함을 알았을 경우에도 나중에 다른 시작점에서 그곳을 방문해도
    동일하게 끝까지 갈수없다.

    왜냐면 어떤 지점 (x,y)로 왔을때 이전에 (x,y-1)에서왔던, (x-1,y-1),(x+1,y-1)에서왔던 그것은 이후 사건에 영향을 주지 않기때문이다.
    따라서 어떤 점을 방문할때마다 방문 표시를 해두고 모든 좌표는 최대 한번씩만 방문하게 설계한다면 시간복잡도는 rc가 될것이다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int r,c;
vector<string> v;

int map[10001][501];
// 0 : 비어있음
// 1 : 벽 or 이미 지나간 경로

int di[] = {-1,0,1};
int dj[] = {1,1,1};

int sub_loop(int row, int col){
    if(col == c-1){ // 마지막 열에 도착
        return 1;
    }
    int ni,nj;
    int ans;
    for(int t=0;t<3;t++){
        ni = row+di[t];
        nj = col+dj[t];
        if(ni >= 0 && ni < r && nj < c){ // 유효한 범위일때만 진입
            if(map[ni][nj] == 0){
                map[ni][nj] = 1;
                ans = sub_loop(ni,nj);
                if(ans == 1){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main_loop(){
    int tot = 0;
    for(int i=0;i<r;i++){
        tot = tot + sub_loop(i,0);
    }
    return tot;
}

int main(){
    cin >> r >> c;
    string tmp;
    for(int i=0;i<r;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j] == '.'){
                map[i][j] = 0;
            }
            else{
                map[i][j] = 1;
            }
        }
    }

    cout << main_loop();
}
/*
5 5
..X..
..X..
.....
.....
.....

*/