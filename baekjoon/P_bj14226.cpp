/*
24m

백준 14226 - 이모티콘

bfs - 2차원배열로 visited 관리

문제 개요 : 

화면(초기 이모티콘 1개)과 클립보드(초기 이모티콘 0개)가 있고 한번에 한가지를 수행할수 있다.

1. 현재 화면 이모티콘 클립보드로 덮어쓰기
2. 현재 클립보드 화면으로 붙여넣기
3. 현재 화면 이모티콘 1개 삭제

최소 횟수를 구하는 문제이므로 bfs로 탐색해야했고 그러기 위해서는 pair를 이용해서 pair<화면 이모티콘 개수,클립보드 이모티콘 개수> 로 하여 관리하였다.

* 만들어야할 최대 이모티콘은 1000개였지만 그 과정에서 몇개까지 화면에 나타날지 모르기 때문에 안전하게 최대 이모티콘의 2배를 배열의 크기로 잡아 놓고 
그보다 커질시에는 2번 작업을 수행하지 않도록 하여 outbound 에러를 피했다.

*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

queue<pair<int,int> > q1;
queue<pair<int,int> > q2;
queue<pair<int,int> > tmp;

int s[2000][2000];
int n;


int run(){
    int count = 1;
    pair<int,int> now;
    pair<int,int> next;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0 ){q2.pop();}
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            if(s[now.first][now.second] == -1){
                s[now.first][now.second] = 1;
                // 1. 클립보드에 저장 
                next.first = now.first;
                next.second = now.first;
                q2.push(next);
                if(next.first == n){
                    return count;
                }

                // 2. 클립보드 이모티콘 화면에 붙여넣기
                if(next.first < 1000){
                    next.first = now.first + now.second;
                    next.second = now.second;
                    q2.push(next);
                    if(next.first == n){
                        return count;
                    }
                }

                // 3. 화면 이모티콘 한개 삭제
                if(now.first > 2){
                    next.first = now.first - 1;
                    next.second = now.second;
                    q2.push(next);
                if(next.first == n){
                    return count;
                }
                }
            }
        }
        count++;
    }
    return -1;
}

int main(){
    cin >> n;
    q2.push(make_pair(1,0));
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            s[i][j] = -1;
        }
    }

    cout << run();
}