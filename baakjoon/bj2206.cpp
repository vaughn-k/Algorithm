/*
1h 40m

그래프 - bfs + dp?

0,0에서 n,m까지 가장 짧은 경로를 찾는 문제인데

격자상에서 벽이 있어서 벽이 없는곳으로만 움직일수 있는데 최대 1개까지 벽을 부수고 이동할수 있다.

따라서 0,0에서, n,m 에서 각각 bfs를 실행하여 특정지점 x,y까지의 최소거리를 구해놓은 다음 k개의 벽마다

해당 벽을 부술때 그 상하좌우 각각 s,e값을 활용하여 12번 탐색하면 그 벽을 부수었을때 최소거리가 갱신되는지 아닌지

알수있다.


 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>


using namespace std;

int n,m;
vector<string> v;
queue<pair<int, int> > q1;
queue<pair<int, int> > q2;
int s[1001][1001];
int e[1001][1001];

void bfs_s(int now){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    int len = q1.size();
    int i,j;
    for(int k = 0; k < len ; k++){
        i = q1.front().first;
        j = q1.front().second;
        q1.pop();

        if(i > 0){ // go up
            if(s[i-1][j] == 99999999 && v[i-1][j] == '0'){
                s[i-1][j] = now;
                q2.push(make_pair(i-1,j));
            }
        }
        if(i < (n-1)){ // go down
            if(s[i+1][j] == 99999999 && v[i+1][j] == '0'){
                s[i+1][j] = now;
                q2.push(make_pair(i+1,j));
            }
        }
        if(j > 0){ // go left
            if(s[i][j-1] == 99999999 && v[i][j-1] == '0'){
                s[i][j-1] = now;
                q2.push(make_pair(i,j-1));
            }
        }
        if(j < (m-1)){ // go right
            if(s[i][j+1] == 99999999 && v[i][j+1] == '0'){
                s[i][j+1] = now;
                q2.push(make_pair(i,j+1));
            }
        }
    }
    if(q2.size() > 0){
        bfs_s(now+1);
    }
}

void bfs_e(int now){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    int len = q1.size();
    int i,j;
    for(int k = 0; k < len ; k++){
        i = q1.front().first;
        j = q1.front().second;
        q1.pop();

        if(i > 0){ // go up
            if(e[i-1][j] == 99999999 && v[i-1][j] == '0'){
                e[i-1][j] = now;
                q2.push(make_pair(i-1,j));
            }
        }
        if(i < (n-1)){ // go down
            if(e[i+1][j] == 99999999 && v[i+1][j] == '0'){
                e[i+1][j] = now;
                q2.push(make_pair(i+1,j));
            }
        }
        if(j > 0){ // go left
            if(e[i][j-1] == 99999999 && v[i][j-1] == '0'){
                e[i][j-1] = now;
                q2.push(make_pair(i,j-1));
            }
        }
        if(j < (m-1)){ // go right
            if(e[i][j+1] == 99999999 && v[i][j+1] == '0'){
                e[i][j+1] = now;
                q2.push(make_pair(i,j+1));
            }
        }
    }
    if(q2.size() > 0){
        bfs_e(now+1);
    }
}

int return_way(char type, int i, int j){
    if(i < 0 || i > n-1 || j < 0 || j > m-1){
        return 99999999;
    }
    if(type == 's'){
        return s[i][j];
    }
    else{
        return e[i][j];
    }
}

int break_block(){
    int minimum = s[n-1][m-1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '1'){
                minimum = min(minimum,(return_way('s',i-1,j) + return_way('e',i+1,j) + 1));
                minimum = min(minimum,(return_way('s',i-1,j) + return_way('e',i,j-1) + 1));
                minimum = min(minimum,(return_way('s',i-1,j) + return_way('e',i,j+1) + 1));
                minimum = min(minimum,(return_way('s',i+1,j) + return_way('e',i-1,j) + 1));
                minimum = min(minimum,(return_way('s',i+1,j) + return_way('e',i,j-1) + 1));
                minimum = min(minimum,(return_way('s',i+1,j) + return_way('e',i,j+1) + 1));
                minimum = min(minimum,(return_way('s',i,j-1) + return_way('e',i+1,j) + 1));
                minimum = min(minimum,(return_way('s',i,j-1) + return_way('e',i-1,j) + 1));
                minimum = min(minimum,(return_way('s',i,j-1) + return_way('e',i,j+1) + 1));
                minimum = min(minimum,(return_way('s',i,j+1) + return_way('e',i,j-1) + 1));
                minimum = min(minimum,(return_way('s',i,j+1) + return_way('e',i-1,j) + 1));
                minimum = min(minimum,(return_way('s',i,j+1) + return_way('e',i+1,j) + 1));
            }
        }
    }
    return minimum;
}

int main(){
    string tmp;
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
        for(int j=0;j<m;j++){
            s[i][j] = 99999999;
            e[i][j] = 99999999;
        }
    }

    q2.push(make_pair(0,0));
    s[0][0] = 1;
    bfs_s(2);

    while(q2.size() > 0){
        q2.pop();
    }

    q2.push(make_pair(n-1,m-1));
    e[n-1][m-1] = 1;
    bfs_e(2);

    int answer = break_block();
    if(answer >= 99999999){
        cout << -1;
    }
    else{
        cout << answer;
    }
}
