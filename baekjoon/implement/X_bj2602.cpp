#include <iostream>
#include <string>
#include <vector>

using namespace std;

string core;
vector<string> s;
string s1;
string s2;
int n;
int save[2][101][21];

int dfs(int row, int before, int index){
    if(index == core.size()){
        return 1;
    }
    if(row == n){
        return 0;
    }
    if(before >= 0){
        if(save[before][row][index] != -1){
            return save[before][row][index];
        }
    }
    // row, col 번째에서 select 했을때, index번째를 골라야하는 상황에서
    int tot = 0;

    // case1. 위를 선택
    if(s[0][row] == core[index] && before != 0){
        tot = tot + dfs(row+1,0,index+1);
    }

    // case2. 아래를 선택
    if(s[1][row] == core[index] && before != 1){
        tot = tot + dfs(row+1,1,index+1);
    }

    // case3. 둘다 선택 x
    tot = tot + dfs(row+1,before,index);
    if(before >= 0){
        save[before][row][index] = tot;
    }
    return tot;
}

int main(){
    cin >> core >> s1 >> s2;
    s.push_back(s1);
    s.push_back(s2);
    n = s1.size();
    for(int i=0;i<2;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<21;k++){
                save[i][j][k] = -1;
            }
        }
    }

    int ans = dfs(0,-1,0);
    cout << ans;
}