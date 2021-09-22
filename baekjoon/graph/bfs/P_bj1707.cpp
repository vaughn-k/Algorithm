/*
49m

그래프 bfs 응용

문제개요 : 그래프가 주어졌을때 각 정점을 두 집합으로 나눴을때 같은 집합의 정점끼리는 인접하지 않도록 할때
그 그래프가 가능한지 여부체크

bfs로 순회하면서 각 bfs마다 타입을 주고 다음으로 진행할 정점이 현재 정점과 타입이 같다면 NO를 출력하도록 설계

그러나 모든 정점들이 하나의 컴포넌트에 있다는 보장이 없으므로 모든 정점에 대해 bfs를 다 수행해야한다.

(물론 이미 방문한곳 제외)

그러나 이과정에서 아직 방문하지 않은 곳을 찾을때 시간복잡도가 N^2이여서 계속 시간초과가 발생했다.

그래서 현재까지 방문여부 체크한 인덱스를 brk 라는 변수로 저장해놓고 다음에 search할때 그 brk부터 탐색하도록 설계하여

해당 시간복잡도를 N으로 줄였다.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k;
int n,e;
vector<vector<int> > v;
int visited[20002];
int brk;
// 0 : 방문 x
// 1 : 1번타입 방문
// 2 : 2번타입 방문

queue<int> q1;
queue<int> q2;


int find_not_visited(){
    for(int i=brk;i<=n;i++){
        if(visited[i] == 0){
            brk = i+1;
            return i;
        }
    }
    return -1;
}

int switch_(int type){
    
    if(type == 1){
        return 2;
    }    
    else{
        return 1;
    }
}

int bipartite_graph(int type){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }

    int now;
    while(q1.size() > 0){
        now = q1.front();
        q1.pop();

        for(int i=0;i<v[now].size();i++){
            if(visited[v[now][i]] == 0){ // 방문 안한곳
                visited[v[now][i]] = switch_(type);
                q2.push(v[now][i]);
            }
            if(visited[v[now][i]] == type){ // 같은 타입과 인접하다.
                return -1;
            }
        }
    }
    if(q2.size() > 0){
        return bipartite_graph(switch_(type));
    }
    return 1;
}

void bipartite_graph_run(){
    int go,state;
    brk = 1;
    while(q2.size() > 0){
        q2.pop();
    }
    go = find_not_visited();
    state = 1;
    while(go != -1 && state != -1){
        q2.push(go);
        state = bipartite_graph(1);
        go = find_not_visited();   
    }
    if(state == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    int tmp1,tmp2,ans;
    cin >> k;
    for(int i=0;i<k;i++){
        v.clear();
        cin >> n;
        cin >> e;
        for(int j=0;j<=n;j++){
            visited[j] = 0;
            v.push_back(vector<int>());
        }
        for(int j=0;j<e;j++){
           cin >> tmp1;
           cin >> tmp2;
           v[tmp1].push_back(tmp2);
           v[tmp2].push_back(tmp1);
        } 
        bipartite_graph_run();
    }

}