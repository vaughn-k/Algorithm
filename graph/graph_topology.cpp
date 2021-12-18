#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > graph;
stack<int> s;

int visited[10]; // 0 - 미방문 / 1 - 방문

void dfs_togological(int v){
    visited[v] = 1;
    for(int i=0; i<graph[v].size(); i++){
        if(visited[graph[v][i]] == 0){
            dfs_togological(graph[v][i]);
        }
    }
    s.push(v);
}

void dfs_all_topological(){
    for(int i=0;i<graph.size();i++){
        if(visited[i] == 0){
            dfs_togological(i);
        }
    }
}

void print_topological_sort(){
    int tmp;
    while(s.size() > 0){
        tmp = s.top();
        s.pop();
        cout << tmp << " ";
    }
    
}

int main(){
    for(int i=0;i<10;i++){
        graph.push_back(vector<int>());
        visited[i] = 0;
    }

    graph[1].push_back(0);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(6);
    graph[6].push_back(5);
    graph[6].push_back(8);
    graph[6].push_back(9);
    graph[5].push_back(4);
    graph[8].push_back(7);
    graph[7].push_back(4);

    dfs_all_topological();
    print_topological_sort();
}