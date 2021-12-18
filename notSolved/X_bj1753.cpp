#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int v,e,k;
vector<vector<pair<int,int> > > graph;
int d[20003];
int visited[20003];

void shortest(int now){
    visited[now] = 1;
    for(int target=0; target<graph[now].size(); target++){
        if(d[graph[now][target].first] > graph[now][target].second + d[now]){
            d[graph[now][target].first] = graph[now][target].second + d[now];
        }
    }
    int minimum_index;
    int minimum_value = 99999999;

    for(int i=0;i<v;i++){
        if(minimum_value > d[i] && visited[i] == -1){ // 현재가장 최소값이면서 방문안한 곳 탐색
            minimum_index = i;
            minimum_value = d[i];
        }
    }
    if(minimum_value < 99999999){
        shortest(minimum_index);
    }
}

int main(){
    cin >> v;
    cin >> e;
    cin >> k;
    k = k-1;
    int x,y,w;
    for(int i=0;i<v;i++){
        graph.push_back(vector<pair<int,int> >());
        d[i] = 99999999;
        visited[i] = -1;
    }
    for(int i=0;i<e;i++){
        cin >> x;
        cin >> y;
        cin >> w;
        graph[x-1].push_back(make_pair(y-1,w));
    }

    d[k] = 0;
    shortest(k);
    for(int i=0;i<v;i++){
        if(d[i] >= 99999999){
            cout << "INF" << endl;
        }
        else{
            cout << d[i] << endl;
        }
    }
}