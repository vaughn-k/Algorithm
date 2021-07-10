/*/////////////////////////////////////////////////////////////////////////
소요시간 : 1h 20m

문제명 - 백준 1005 - ACM Craft

알고리즘
    - 위상정렬 느낌인데 dp적용

문제개요
    n개의 건물이 주어지고 각 건물들마다 짓는데 걸리는 시간이 주어지고
    k개의 건물 의존 여부가 주어진다

    이때 특정 건물(target) 건물을 짓기위해 필요한 최소시간 출력

    target기준으로 헤드들을 찾고
    그 헤드들이 dfs를 돌면서 가장 오래걸리는 시간을 찾는다(max값 갱신)
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t,n,k,target;
int build[1002];
int visited[1002];
int subVisited[1002];
int must[1002];

vector<vector<int> > v;
vector<vector<int> > vInverse;

queue<int> q;

int go(int id){
    if(id == target){
        return build[id];
    }
    int maxi = -1;
    int next;
    int ret;
    for(int i=0;i<v[id].size();i++){
        next = v[id][i];
        if(must[next] == 1){
            if(visited[next] >= 0){
                ret = visited[next];
            }
            else{
                ret = max(maxi, go(next));
            }
            maxi = max(maxi, ret);
        } 
    }
    visited[id] = maxi + build[id];
    return maxi + build[id];
}

void findHead(int id){
    must[id] = 1;
    if(vInverse[id].size() == 0){
        q.push(id);
        return;
    }
    for(int i=0;i<vInverse[id].size();i++){
        if(subVisited[vInverse[id][i]] == -1){
            subVisited[vInverse[id][i]] = 1;
            findHead(vInverse[id][i]);
        }
    }
}

int main(){
    
    int t1,t2,maxi;
    cin >> t;
    for(int i=0;i<t;i++){
        // v = vector<vector<int> >();
        // vInverse = vector<vector<int> >();
        // vector<vector<int> >().swap(v);
        // vector<vector<int> >().swap(vInverse);
        v.clear();
        vInverse.clear();

        cin >> n >> k;
        v.push_back(vector<int>());
        vInverse.push_back(vector<int>());
        for(int j=1;j<=n;j++){
            visited[j] = -1;
            subVisited[j] = -1;
            must[j] = 0;
            cin >> build[j];
            v.push_back(vector<int>());
            vInverse.push_back(vector<int>());
        }
        for(int j=0;j<k;j++){
            cin >> t1 >> t2;
            v[t1].push_back(t2);
            vInverse[t2].push_back(t1);
        }
        cin >> target;
        maxi = -1;
        findHead(target);
        while(q.size() > 0){
            maxi = max(maxi, go(q.front()));
            q.pop();
        }
        cout << maxi << '\n';
    }
}