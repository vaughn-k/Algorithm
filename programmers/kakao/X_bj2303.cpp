#include <iostream>
#include <vector>

using namespace std;

int n,m;
int ban[42];
int save[41][2];

int dfs(int left, bool beforeChange){
    int tot = 0;
    if(left == 1){
        return 1;
    }

    // 자리 안바꿀때
    if(save[left][beforeChange] != -1){
        return save[left][beforeChange];
    }
    tot = tot + dfs(left-1,false);

    // 자리 바꿀때 - 이전에 안바꿨어야만 가능하다.
    if(!beforeChange){
        tot = tot + dfs(left-1,true);
    }
    save[left][beforeChange] = tot; 
    return tot;
}

int main(){
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=1;j++){
            save[i][j] = -1;
        }
    }
    for(int i=0;i<42;i++){
        ban[i] = 0;
    }
    int tmp;
    for(int i=0;i<m;i++){
        cin >> tmp;
        ban[tmp] = 1; 
    }

    int answer = 1;
    int subTot = 0;
    for(int i=1;i<=n;i++){
        if(ban[i] == 1){
            if(subTot != 0){
                answer = answer * dfs(subTot,0);
            }
            subTot = 0; 
        }
        else{
            subTot++;
        }
    }
    if(subTot != 0){
        answer = answer * dfs(subTot,0);
    }

    cout << answer;

}