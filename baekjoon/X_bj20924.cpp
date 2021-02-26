#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,r;
vector<vector<pair<int, int> > > v;
int gn,gw,cw;

int vt[200001];

int GigaNode(){
    /*
    기가노드를 출력
        정상적인(자식노드가 2개 이상인) 기가노드
        리프노드면서 기가노드
    */
    int now,next;
    vt[now] = 1;
    now = r;
    gw = 0;
    while(1){
        if(v[now].size() == 0){ // 리프노드면서 기가노드
            return now;
        }
        // else if(v[now].size() == 1){ // 계속 진행
            
        // }
        else if(v[now].size() >= 2){ // 정상적인 리프노드
            return now;
        }
        gw = gw + v[now][0].second;
        now = v[now][0].first;
        vt[now] = 1;
    }
}

int find_node(int s){
    // s 번 정점부터 최대의 길이를 가진 길이
    int mini = -1;
    if(v[s].size() == 0){
        return 0;
    }
    for(int i=0;i<v[s].size();i++){
        mini = max(mini,find_node(v[s][i].first)+v[s][i].second);
    }
    return mini;
}

int main(){
    int x,y,w;
    cin >> n;
    cin >> r;
    for(int i=0;i<=n;i++){
        v.push_back(vector<pair<int,int> >());
        vt[i] = -1;
    }
    for(int i=0;i<n-1;i++){
        cin >> x;
        cin >> y;
        cin >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }
    int gn;
    gn = GigaNode();
    cw = find_node(gn);
    cout << gw << " " << cw;
}

/*
2 1
1 2 100

4 4
4 3 30
3 1 20
3 2 10

3 1
1 2 10
1 3 20

*/