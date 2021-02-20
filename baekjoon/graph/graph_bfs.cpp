#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;
queue<int> q1;
queue<int> q2;

int visited[10]; // 0 - 미방문 / 1 - 방문

void bfs(){
    int now;
    int len;
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    len = q1.size();
    if(len > 0){
        for(int i=0;i<len;i++){
            now = q1.front();
            q1.pop();
            cout << "visit " << now << endl;
            for(int j=0; j<graph[now].size(); j++){
                if(visited[graph[now][j]] == 0){
                    q2.push(graph[now][j]);
                    visited[graph[now][j]] = 1;
                }
            }

        }
        bfs();
    }
}

int main(){
    for(int i=0;i<10;i++){
        graph.push_back(vector<int>());
        visited[i] = 0;
    }
    graph[0].push_back(1);
    graph[0].push_back(9);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(5);
    graph[1].push_back(7);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(2);
    graph[4].push_back(2);
    graph[5].push_back(2);
    graph[5].push_back(6);
    graph[5].push_back(1);
    graph[7].push_back(1);
    graph[7].push_back(8);
    graph[7].push_back(9);
    graph[8].push_back(7);
    graph[9].push_back(0);
    graph[9].push_back(7);

    q2.push(0);
    visited[0] = 1;

    bfs();
}