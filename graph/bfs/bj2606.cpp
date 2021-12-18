/*
15m

매우 기본적인 graph-bfs
erase_col 을 사용했다.
*/

#include <iostream>
#include <queue>

using namespace std;

int N,M;
int graph[102][102];
int total = 0;

queue<int> q1;
queue<int> q2;

void erase_col(int num){
    for(int i=1;i<N+1;i++){
        graph[i][num] = 0;
    }
}

void virus(){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }

    int len = q1.size();
    int tmp;

    if(len > 0){
        for(int i=0;i<len;i++){
            tmp = q1.front();
            for(int j=1;j<N+1;j++){
                if(graph[tmp][j] == 1){
                    total++;
                    erase_col(j);
                    q2.push(j);
                }
            }
            q1.pop();
        }
        if(q2.size() > 0){
            virus();
        }
    }
}


int main(){
    cin >> N;
    cin >> M;
    int x,y;
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<M;i++){
        cin >> x;
        cin >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    q2.push(1);
    erase_col(1);
    virus();
    cout << total;
}