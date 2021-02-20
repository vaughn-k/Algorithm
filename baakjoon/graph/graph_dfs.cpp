#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;

int visited[10]; // 0 - 미방문 / 1 - 방문

void dfs(int v){
    cout << "visit " << v << endl;
    visited[v] = 1;
    for(int i=0; i<graph[v].size(); i++){
        if(visited[graph[v][i]] == 0){
            dfs(graph[v][i]);
        }
    }
}

void dfs_all(){
    for(int i=0;i<graph.size();i++){
        if(visited[i] == 0){
            dfs(i);
        }
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

    dfs_all();
}