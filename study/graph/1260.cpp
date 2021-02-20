#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
int N,M,V;

void dfs(int start){
    cout << start << " ";
    for(int i=0;i<graph[start].size();i++){
        dfs(graph[start][i]);
    }
}


int main(){
    cin >> N;
    cin >> M;
    cin >> V;
    for(int i=0;i<N;i++){
        graph.push_back(vector<int>());
    }
    int x,y;
    for(int i=0;i<M;i++){
        cin >> x;
        cin >> y;
        graph[x].push_back(y);
    }

    dfs(V);
}