/*
1h 25m
 
dp - 트리구조에서

문제개요 : 트리가 주어지고 이 트리들의 두 정점을 좌우로 늘려서 가중치들을 더한 값의 최대값을 구하는문제

dp를 설계하는 부분이 쉽지않았고 트리가 항상 자식이 최대 2개일때만 고려해서 오래걸렸다.

*/

#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int n;
vector<vector<pair<int, int> > >v;

int pa[10002];
int d[10002][3];

int main(){
    int x,y,w;
    int parent;
    int solo1,solo2,brid,tmp;
    pair<int,int> child1,child2;
    cin >> n;
    for(int i=0;i<=n;i++){
        v.push_back(vector<pair<int,int> >());
    }
    for(int i=0;i<(n-1);i++){
        cin >> x;
        cin >> y;
        cin >> w;
        v[x].push_back(make_pair(y,w));
        pa[y] = w;
    }

    for(int now = n; now > 0; now--){
        if(v[now].size() == 0){ // 자식이 없는 노드
            d[now][0] = pa[now];
            d[now][1] = 0;
        }
        else if(v[now].size() == 1){ // 자식이 1개인 노드
            child1 = v[now][0];
            d[now][0] = d[child1.first][0];
            d[now][1] = d[child1.first][1] + child1.second;
        }
        else{ // 자식이 2개 이상인
            solo1 = 0;
            solo2 = 0;
            brid = 0; // 자식들의 최대치
            for(int k=0;k<v[now].size();k++){
                child1 = v[now][k];
                tmp = d[child1.first][1] + child1.second;
                if(tmp > solo1){
                    solo2 = solo1;
                    solo1 = tmp;
                }
                else if(tmp > solo2){
                    solo2 = tmp;
                }

                if(d[child1.first][0] > brid){
                    brid = d[child1.first][0];
                }
            }
            d[now][0] = max(brid, solo1+solo2);
            d[now][1] = solo1;
        }
        // cout << "now : " << now << " | " << d[now][0] << "," << d[now][1] << "," << d[now][2] << endl;
    }
    cout << max(d[1][0],d[1][1]);
}

