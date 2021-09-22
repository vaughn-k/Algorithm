/*
30m

백준 2342 - Dancd Dance Revolution

알고리즘 : dp (외부)

문제개요 : ddr게임을 하는데 밟아야할 화살표(4방향)가 주어지고 두발의 움직임(방향전환)에 따라 가중치가 다르다.

최소의 가중치로 게임을 완수하는 가중치 구하기

해당 문제는 power값을 최소로 해야하고 dp를 적용하기위해

go(i) = go(i+1) + 현재power 

식으로 나누어 만약 go(i+1)에 방문을 했었다면 해당 값은 바로 불러와서 현재 power를 더하는 것이 가능하게 하였다.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int d[100002][5][5];

int n;

int calculatePower(int start, int end){
    if(start == 0){
        return 2;
    }
    else if(abs(start - end) == 2){ // 반대편 이동
        return 4;
    }
    else{
        return 3;
    }
}

int go(int now, int p1, int p2){
    int ans;
    int tmp1,tmp2;
    if(now == n){
        return 0;
    }
    if(d[now][p1][p2] != -1){
        return d[now][p1][p2];
    }
    // now : 밟아야 할 스텝
    // p1 : 현재 발의위치중 낮은번호, p2 : 현재 발의위치중 높은 번호
    if(v[now] == p1 || v[now] == p2){ // 이미 밟은곳 한번더 밟기
        ans = go(now+1,p1,p2) + 1;
    } 
    else{ // 새로운 곳 밟기
        tmp1 = go(now+1,min(v[now],p2),max(v[now],p2))
        + calculatePower(p1,v[now]);
        tmp2 = go(now+1,min(v[now],p1),max(v[now],p1))
        + calculatePower(p2,v[now]);
        ans = min(tmp1,tmp2);
    }
    d[now][p1][p2] = ans;
    return ans;
}

int main(){
    int tmp;
    tmp = 1;
    while(tmp != 0){
        cin >> tmp;
        if(tmp != 0){
            v.push_back(tmp);
        }
    }
    n = v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                d[i][j][k] = -1;
            }
        }
    }

    cout << go(0,0,0);
}