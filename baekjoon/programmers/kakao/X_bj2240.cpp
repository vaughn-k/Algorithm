#include <iostream>
#include <vector>

using namespace std;

int t,w;
vector<int> jadu;
int save[1001][31][2];


int getJaDo(int index, int position){
    if(jadu[index] == position){
        return 1;
    }
    else{
        return 0;
    }
}

int positionChange(int position){
    if(position == 1){
        return 2;
    }
    else{
        return 1;
    }
}

int dfs(int now, int position, int left){
// now번째 자리에서, position 위치에 있을때, left번 더 움직여서 받을 수 있는 최대 자두개수
    if(now == t){
        return 0;
    }
    if(save[now][left][position] != -1){
        return save[now][left][position];
    }
    int case1,case2;
    // 위치 안바꿀때
    case1 = dfs(now+1,position,left) + getJaDo(now,position);

    // 위치 바꿀때
    int nextPosition;
    if(left > 0){
        nextPosition = positionChange(position);
        case2 = dfs(now+1,nextPosition,left-1) + getJaDo(now, nextPosition);
    }
    else{
        case2 = 0;
    }
    int result = max(case1,case2);
    save[now][left][position] = result;
    return result;
}

int main(){
    int tmp;
    cin >> t >> w;
    for(int i=0;i<t;i++){
        cin >> tmp;
        jadu.push_back(tmp);
    }

    for(int i=0;i<1001;i++){
        for(int j=0;j<31;j++){
            for(int k=0;k<2;k++){
                save[i][j][k] = -1;
            }
        }
    }
    int ans;
    ans = dfs(0,1,w);
    cout << ans;
}