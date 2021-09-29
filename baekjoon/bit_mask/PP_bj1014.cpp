/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.09.25

소요시간 : 1h 50m

문제명 - 백준 1014 컨닝
   
알고리즘
    - dp
    - bitmask(부분 bitmask)

문제개요

    - 문제 및 아이디어

    문제에서 중요한 부분은 "컨닝의 범위" 이다. 
    p . p
    p o p
    위와같이 o라는 사람이 있을 때,  좌,우,위좌,위우(p좌표들) 에는 못앉게 된다.
    만약 맨 아래줄 왼쪽부터 앉게 한다고 했을 때 각 경우의 수는 2가지 이다.
    해당 칸에 앉히거나, 앉히지 않거나.

    이때 해당 칸에 앉히기 위해서는 몇가지 조건이 필요하다.
    1. 해당 칸이 앉을 수 있는 "." 칸이여야한다.
    2. 자신 주변에 컨닝범위에 들어오는 사람이 없어야한다.
        이부분이 중요한데 먼저 가정에 따르면 가장 아래, 가장 왼쪽부터 채운다고 했으므로 자신의 왼쪽과
        아래 왼쪽,오른쪽에 사람이 있는지만 고려하면 된다.
        (자신의 오른쪽은 어차피 다음사람을 앉힐 때 체크할 것이므로 지금은 체크할 수 없다.)

    여기까지 하면 정답 자체는 나올것이다.
    그러나 체크해야할 경우의 수가 2^(n+m) 이므로 시간복잡도를 줄여야한다.

    dp를 사용하기 위해서는 현재 선택의 연관성이 어디까지 있느냐를 파악해야한다.

    만약 p번째 열에 q번째 행에 사람을 채워넣고 있다면 여기서 필요한 정보는 p+1열의 앉아있는 정보와
    p번째 열에서 q번째행 이전까지 앉아있는 정보가 필요할 것이다.

    여기서 각 앉아있는 상태를 bitmask로 처리하면 
    (총 열개수) * (p+1열 정보) * (p열 정보)
    = n * 2^m * 2^m = dp[10][1024][1024] 로 저장해야할 공간이 너무 커지게 된다.

    그래서 dp를 활용하는 것을 매 재귀함수마다 하지 않고 하나의 열이 전부 채워 졌을 때만 하였다.

    즉 p번째 열을 다 채웠을 때 그때 p번째열의 상태를 state라고 할 때,
    p-1번째열에 state 상태로 진입했던 적이 있다면 그 값을 불러오는 것이다.

    즉 dp[p][state] 라고 하면 "p-1행을 채우기 시작할건데, 그 전에 p행을 state 상태로 채웠
    던 적이 있다면 그 값" 을 의미한다.
    




   
*//////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int c,n,m;
string s;
string v[11];

int dp[11][1025];

// dp[x][y] = x번째열에서 y라는 state를 가졌을 때 0번째 열부터 x번째 열까지 가능한 최대값

int setSeat(int state, int putSeat){
    // state 상태에서 putSeat 자리에 해당하는 자리에 앉음 체크
    int tmp = 1;
    tmp = tmp << (m-putSeat-1);
    state = state + tmp;
    return state;
}

bool isExistLeftPerson(int state, int checkSeat){
    // state : 현재 앉은 상태, checkSeat : 내가 앉고자 하는 자리
    if(checkSeat == 0){
        return true;
    }
    int tmp = 1 << (m-checkSeat);
    if(state & tmp){
        return false;
    }
    else{
        return true;
    }
}

bool verifyZone(int before_state, int checkSeat){
    int tmp,value;
    // 좌측아래 사람 있는지 확인
    if(checkSeat != 0){
        tmp = 1 << (m-checkSeat);
        if(before_state & tmp){
            return false;
        }
    }

    // 우측아래 사람 있는지 확인
    if(checkSeat != (m-1)){
        tmp = 1 << (m-checkSeat-2);
        if(before_state & tmp){
            return false;
        }
    }
    return true;
}

int dfs(int ni, int nj, int before_state, int now_state, int counts){
    int maxi = 0;

    // 모든 열과 행을 다 채웠을 경우
    if(ni == -1){
        return 0;
    }
    // 하나의 열을 모두 채웠을 경우
    if(nj == m){
        if(dp[ni][now_state] != -1){
            return dp[ni][now_state];
        }   
        maxi = dfs(ni-1,0,now_state,0,counts);
        dp[ni][now_state] = maxi;
        
        return maxi;
    }

    // 맨 아랫줄일 때 - 본인 라인과 앉을 수 없는자리만 고려하면 된다.
    if(ni == (n-1)){
        // 자신 왼쪽에 사람이 없다 && 앉을 수 있는 자리이다. -> 현재자리 착석할 때
        if(isExistLeftPerson(now_state,nj) && v[ni][nj] == '.'){
            maxi = max(maxi,1+dfs(ni,nj+1,before_state,setSeat(now_state,nj),counts+1));
        }
        // 현재 자리 착석 안할 때
        maxi = max(maxi,dfs(ni,nj+1,before_state,now_state,counts));
        

    }
    // 맨 아랫줄이 아닐 때 - 본인 라인과 앉을 수 있는지와 아랫줄의 컨닝라인까지 고려해야한다.
    else{
        // 자신 옆자리에 사람이 없다 && 앉을 수 있는 자리이다 && 자신아랫줄과 커닝라인이 겹치지 않는다.
        if(isExistLeftPerson(now_state,nj) && v[ni][nj] == '.' && verifyZone(before_state,nj)){
            maxi = max(maxi,1+dfs(ni,nj+1,before_state,setSeat(now_state,nj),counts+1));
        }
        // 현재 자리 착석 안할 때
        maxi = max(maxi,dfs(ni,nj+1,before_state,now_state,counts));
    }

    return maxi;
}


int main(){
    int ans;
    cin >> c;
    for(int i=0;i<c;i++){
        cin >> n >> m;
        
        for(int j=0;j<n;j++){
            cin >> v[j];
            for(int k=0;k<1024;k++){
                dp[j][k] = -1;
            }
        }
        cout << dfs(n-1,0,0,0,0) << '\n';
    }
}

