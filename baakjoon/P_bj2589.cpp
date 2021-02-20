/*
1h

그래프 - 컴포넌트개수 + bfs

문제개요 : 바다와 육지가 존재하고 육지내에서만 이동이가능하며 각 육지의 점별로 최소의 거리를 구했을때 그 값의

최대값을 구하는 문제

+ 상하좌우 이동시 배열이용하는 스킬
+ bfs 수행시 재귀가 아닌 while사용

*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int n,m;
vector<string> v;
queue<pair<int,int> > q1;
queue<pair<int,int> > q2;
queue<pair<int,int> > sub;
int visited[51][51];

int mi[] = {-1,0,1,0};
int mj[] = {0,-1,0,1};

int minimum = 0;

void reset_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = -1;
        }
    }
}

void run_dist(){
    int count = -1;
    pair<int, int> now;
    int coni,conj;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){ q2.pop(); }
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();

            for(int t=0;t<4;t++){
                coni = now.first + mi[t];
                conj = now.second + mj[t];
                if(coni >= 0 && conj >= 0 && coni <= (n-1) && conj <= (m-1)){
                    if(visited[coni][conj] == -1 && v[coni][conj] == 'L'){
                        visited[coni][conj] = 1;
                        q2.push(make_pair(coni,conj));
                    }
                }
            }
        }
        count = count + 1;
    }
    if(minimum < count){
        minimum = count;
    }
}

void run(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 'L'){
                reset_visited();
                while(q2.size() > 0){ q2.pop();}
                q2.push(make_pair(i,j));
                visited[i][j] = 1;
                run_dist();
            }
        }
    }
}

int main(){
    string tmp;
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    run();
    cout << minimum;

}


/*

5 5
LLLLL
LLLLL
LLLLL
LLLLL
LLLLL

*/