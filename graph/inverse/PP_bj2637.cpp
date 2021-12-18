/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.09.21

소요시간 : 1h

문제명 - 백준 2637 장난감 조립
   
알고리즘
    - dp + 그래프(역그래프)

문제개요

    - 문제 및 아이디어

    하나의 완성품은 몇개의 중간부품과 몇개의 기본부품으로 이루어져있고, 
    중간부품은 몇개의 중간부품과 몇개의 기본부품으로 이루어져 있다.

    완성품을 만들기위해 필요한 기본부품별 개수를 구하라.
    
    이문제는 brute-force로 풀면 시간초과가 발생한다. 그 이유부터 살펴봐야한다. 
    brute-force를 이용했을 때 시간복잡도가 기하급수적으로 증가하는 경우는

        ㅇ
       /ㅣ\
      ㅇ ㅇ ㅇ
       \ㅣ /
        ㅇ
       /ㅣ\
      ㅇ ㅇ ㅇ
       \ㅣ /
        ㅇ

    위와같은 경우이다. 맨 위 노드가 완성품이고, 맨 아래 노드가 기본부품일 때 위의 그래프를 dfs로
    모두 순회하려면 3*3 = 9의 시간복잡도가 발생한다. 즉 이런형태로 구성되는 구성이 5개만 반복되어도
    3^5이 되어 243번으로 횟수가 늘어나고 N값이 최대 100이므로 3^30만 잡아도 시간복잡도는 기하급수적으로
    늘어나는것을 확인할 수 있다.

    따라서 이부분에서 이미 방문한 노드는 방문하지 말아야 한다는 것을 알수 있고 그것을 고민해야한다.

    문제를 역으로 접근해보자. 완성품부터 내려가지 말고 기본 부품별로 올라가보자.

    기본부품(leaf노드)에서 위로 올라가면서 가장 루트(완성품)노드까지 올라가고 완성품에 도착하거나 
    이미 방문한 노드에 도착한다면 현재 가중치(몇개가 필요한지)를 곱해서 합산해준다.

    이런식으로 구현한다면, 간선(edge) 개수는 M개(최대 100개) 이므로 100번의 순회만 한다면
    모든 값을 알아낼 수 있다.


    - 구현

    먼저 기본 관계와 역관계를 두 벡터에 담는다.
    전자의 벡터는 leaf노드(=기본부품)을 찾기 위한 용도이므로 int값만 저장하면 된다.
    후자의 벡터는 leaf노드(=기본부품)부터 완성품까지 올라가야하고, 각 부품이 몇개 필요한지(가중치)
    두가지 정보가 필요하므로 pair를 이용하여 역으로 구성한다.

    먼저 전자 벡터를 이용하여 leaf노드들을 알아내고 새로운 벡터에 저장한다.
    
    그리고 그 벡터를 오름차순으로 정렬한다(문제에서 기본부품 번호가 작은것부터 출력하라고 했으므로)

    이후 그 벡터에서 하나씩 빼서 위의 구현에 따라 구현된 dfs 함수에 넣어 필요한 개수를 받아 출력한다.

    + 이전에 그래프 문제에서도 역으로 탐색해서 해결하는 문제가 있었던것 같다..

   
*//////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<int> > v;
vector<vector<pair<int,int> > > v2;
vector<int> leaf;

int save[101];
int visited[101];

void find_leaf_node(int now){
    if(visited[now] != -1){
        return;
    }
    visited[now] = 1;
    // 자식이 없음 = 리프노드 일때
    if(v[now].size() == 0){
        leaf.push_back(now);
    }
    else{
        for(int i=0;i<v[now].size();i++){
            find_leaf_node(v[now][i]);
        }
        return;
    }
}

// now 라는 node를 총 몇번 방문하는가?
int dfs(int now){
    if(save[now] != -1){
        return save[now];
    }
    if(v2[now].size() == 0){
        return 1;
    }
    int tot = 0;
    for(int i=0;i<v2[now].size();i++){
        tot += dfs(v2[now][i].first) * v2[now][i].second;
    }
    save[now] = tot;
    return tot;
}

int main(){
    int t1,t2,t3;
    cin >> n >> m;
    for(int i=0;i<=n;i++){ 
        v.push_back(vector<int>());
        v2.push_back(vector<pair<int,int> >());
        save[i] = -1;
        visited[i] = -1;
    }
    for(int i=0;i<m;i++){
        cin >> t1 >> t2 >> t3;
        v[t1].push_back(t2);
        v2[t2].push_back(make_pair(t1,t3));
    }

    for(int i=1;i<=n;i++){
        find_leaf_node(i);
    }
    sort(leaf.begin(),leaf.end());

    for(int i=0;i<leaf.size();i++){
        cout << leaf[i] << " " << dfs(leaf[i]) << '\n';
    }
}