/*
18m

dfs로 모든 점을 탐색하면서 상태를 체크하며 최종 결과에 도달했을때 리턴값을 통해 다시

돌아가면서 가능여부를 체크해준다.

*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int n,m;
vector<string> v;
string tmp;

int visited[501][501];
/*
-1 > 미방문
0 > 불가능
1 -> 가능
2 -> 현재 방문중
*/

pair<int, int> move(int i, int j, char c){
    if(c == 'U'){
        return make_pair(i-1,j);
    }
    else if(c == 'R'){
        return make_pair(i,j+1);
    }
    else if(c == 'D'){
        return make_pair(i+1,j);
    }
    else{
        return make_pair(i,j-1);
    }
}

int maze(int x, int y){
    if(x == -1 || x == n || y == -1 || y == m){
        return 1;
    }
    if(visited[x][y] == 1){
        return 1;
    }
    if(visited[x][y] == 2){
        return 0;
    }
    visited[x][y] = 2;
    pair<int, int> t;
    t = move(x,y,v[x][y]);
    int result = maze(t.first,t.second);
    if(result == 1){
        visited[x][y] = 1;
        return 1;
    }
    else{
        visited[x][y] = 0;
        return 0;
    }
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
        for(int j=0;j<m;j++){
            visited[i][j] = -1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maze(i,j);
        }
    }
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == 1){
                total++;
            }
        }
    }
    cout << total;
}