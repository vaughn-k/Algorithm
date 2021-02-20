/*
33m

그래프 - 다익스트라 3번반복

문제 개요 : 비방향 그래프가 주어지고 가중치가 주어진다.

1번정점부터 n번 정점까지 가는데 특정 정점 a,b를 반드시 경유하여 최종 도착하는 가장 적은 가중치(경로)를 구하는 문제

1,a,b 정점에서 다익스트라를 3번 수행한후 
1 -> a -> b -> n
1 -> b -> a -> n 
두 경우의 값을 비교해서 최소값을 출력
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,e;
vector<vector<pair<int,int> > > v;

int d[802];
int visited[802];

void reset(){
    for(int i=0;i<=n;i++){
        d[i] = 10000000;
        visited[i] = 0;
    }
}


void dijkstra(int start){
    int next;
    int next_w;
    while(start != -1){
        visited[start] = 1;
        for(int i=0;i<v[start].size();i++){
            next = v[start][i].first;
            next_w = v[start][i].second;
            if(d[next] > d[start] + next_w){
                d[next] = d[start] + next_w;
            }
        }

        int min_index = -1;
        int min_value = 10000000;
        for(int i=1;i<=n;i++){
            if(min_value > d[i] && visited[i] == 0){
                min_index = i;
                min_value = d[i];
            }
        }
        start = min_index;
    }
}
void dijkstra_run(int start){
    reset();
    d[start] = 0;
    dijkstra(start);
}

int main(){
    int sa,sb,ab,ba,bn,an,a,b,case1,case2;
    int x,y,w;
    cin >> n;
    cin >> e;
    for(int i=0;i<=n;i++){
        v.push_back(vector<pair<int,int> >());
    }
    for(int i=0;i<e;i++){
        cin >> x;
        cin >> y;
        cin >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }
    cin >> a;
    cin >> b;

    dijkstra_run(1);
    sa = d[a];
    sb = d[b];
    
    dijkstra_run(a);
    ab = d[b];
    an = d[n];
    dijkstra_run(b);
    ba = d[a];
    bn = d[n];

    case1 = sa + ab + bn;
    case2 = sb + ba + an;
    int ans;
    ans = min(case1,case2);
    if(ans >= 10000000){
        cout << -1;
    }
    else{
        cout << ans;
    }


}

/*
4 4
1 2 3
2 3 3
3 2 1
1 3 5
2 3
*/