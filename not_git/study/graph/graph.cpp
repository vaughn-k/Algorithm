#include <iostream>
#include <vector>
// #include<cassert>
// #include<cstdio>
// #include<iostream>
// #include<string>
// #include<vector>

using namespace std;
int N = 10;

// 깊이 우선 탐색
void print_graph(vector<vector<int> > graph, int head){
    cout << head << " | ";
    int i;
    for(i=0;i<graph[head].size();i++){
        print_graph(graph, graph[head][i]);
    }
}

int main(){
    vector<vector<int> > graph;
    for(int i=0;i<N;i++){
        graph.push_back(vector<int>());
    }
    int head = 3;
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[2].push_back(7);
    graph[2].push_back(1);
    graph[4].push_back(6);
    graph[4].push_back(9);
    graph[9].push_back(8);
    print_graph(graph, head);
    
    // vector<int> a;
    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);
    // cout << a[0];
    // cout << a[1];
    // cout << a[2];
    return 0;
}