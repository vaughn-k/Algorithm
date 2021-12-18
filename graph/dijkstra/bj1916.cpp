/*
56m

그래프 - 다익스트라

일반적인 다익스트라 문제였는데 OutOfBounds 문제로 많은 시간이 걸렸다.

이문제의 경우 도시의 번호가 1번 부터 N개가 주어지는데 벡터를 생성할때 1부터 N개까지 N개를 생성해서

결국 v[N] 을 참조할때 bounds 에러가 났다.

N에서 1부터 인덱스가 시작할때 항상 주의 요망

*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m;
int visited[1002];
int d[1002];

vector<vector<pair<int, int> > > v;

void dijkstra(int start){
    int min_v;
    int min_index;
    int target;
    int old_dist, new_dist;
    min_v = 0;
    while(min_v < 2000000001){
        visited[start] = 1;
        for(int now=0;now<v[start].size();now++){
            // 출발 정점 : start
            // 도착 정점 : target
            target = v[start][now].first; // 다음으로 이동할 정점
            if(visited[target] == 0){
                old_dist = d[target];
                new_dist = d[start] + v[start][now].second;
                if(old_dist > new_dist){
                    d[target] = new_dist;
                }
            }
        }
        min_v = 2000000001;
        for(int i=1;i<=n;i++){
            if(d[i] < min_v && visited[i] == 0){
                min_v = d[i];
                min_index = i;
            }
        }
        start = min_index;
    }
}

void dijkstra_run(int start){
    d[start] = 0;
    dijkstra(start);
}

int main(){
    int a,b,w;
    int start, end;

    cin >> n;
    cin >> m;
    for(int i=0;i<=n;i++){
        v.push_back(vector<pair<int,int> >());
        visited[i] = 0;
        d[i] = 2000000000;
    }
    for(int i=0;i<m;i++){
        cin >> a;
        cin >> b;
        cin >> w;
        v[a].push_back(make_pair(b,w));
    }
    cin >> start;
    cin >> end; 

    dijkstra_run(start);
    cout << d[end];
}