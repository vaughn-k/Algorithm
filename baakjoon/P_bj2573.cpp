/*
45m

그래프 - 컴포넌트개수

문제 개요 : 빙하의 높이가 주어지고 상하좌우에서 바다와 붙어있을수록 1씩 더 녹는다.

계속해서 녹다가 컴포넌트가 2개이상될때 그 시간을 구하는 문제

*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,m;
int ice[301][301];
int visited[301][301];
int total_block;
queue<pair<int,int> > q1;
queue<pair<int,int> > q2;

void reset_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
}

int go_bfs(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m){
        return 0;
    }
    else{
        if(ice[i][j] > 0 && visited[i][j] == 0){
            visited[i][j] = 1;
            q2.push(make_pair(i,j));
            return 1;
        }
        else{
            return 0;
        }
    }
}

int bfs(){
    int sub_total = 0;
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    pair<int,int> tmp;
    while(q1.size() > 0){
        tmp = q1.front();
        q1.pop();
        sub_total = sub_total + 
        go_bfs(tmp.first-1,tmp.second) +
        go_bfs(tmp.first+1,tmp.second) +
        go_bfs(tmp.first,tmp.second-1) +
        go_bfs(tmp.first,tmp.second+1);
    }

    if(q2.size() > 0){
        sub_total = sub_total + bfs();
    }
    return sub_total;
}

int find_component(){
    reset_visited();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ice[i][j] != 0){
                while(q2.size() > 0){q2.pop();}
                q2.push(make_pair(i,j));
                return bfs();
            }
        }
    }
    return 0;
}

int go(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m){
        return 0;
    }
    else{
        if(ice[i][j] == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

void melt(){
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ice[i][j] != 0){
                total = go(i-1,j) + go(i+1,j) + go(i,j-1) + go(i,j+1);
                if(ice[i][j]-total <= 0){
                    ice[i][j] = 1000;
                }
                else{
                    ice[i][j] = ice[i][j] - total;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ice[i][j] == 1000){
                ice[i][j] = 0;
                total_block--;
            }
        }
    }
}

void main_run(){
    int total_count = 0;
    int count = total_block;
    while(count == total_block && total_block != 0){
        melt();
        count = find_component();
        total_count ++;
    }
    if(total_block == 0){
        cout << 0;
    }
    else{
        cout << total_count;
    }
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ice[i][j];
            if(ice[i][j] > 0){
                total_block++;
            }
        }
    }
    main_run();
}