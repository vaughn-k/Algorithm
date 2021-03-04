/*
30m

백준 2623 - 음악프로그램

알고리즘 : 위상정렬 + 순환체크

문제 개요 : 가수n명과 각자 매니저들이 원하는 가수들의 공연순서가 주어지고

모두 종합해서 해당 공연순서에 맞게 모든 공연순서를 짜서 출력

해당 문제에서는 순환이 존재하는 그래프를 줄수도 있기에 dfs를 돌면서 순환이 발생하는 부분을 캐치해 내야했다.

따라서 visited에서 방문/미방문 에서 현재방문중 이라는 state를 추가해서 만약 현재 방문중일때 
해당 지점을 한번 더 방문한다면 그것은 순환이므로 따로 처리를 해주었다.

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n,m;
vector<vector<int> > v;
int visited[1002];
/*
-1 : 미방문
1 : 현재 방문중
2 : 완전 방문함
*/
stack<int> s;

int dfs(int now){
    visited[now] = 1;
    for(int i=0;i<v[now].size();i++){
        if(visited[v[now][i]] == 1){
            return -1;
        }
        if(visited[v[now][i]] == -1){
            if(dfs(v[now][i]) == -1){
                return -1;
            }
        }
    }
    visited[now] = 2;
    s.push(now);
    return 1;
}

int main(){
    int tmp;
    int before, now;
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        visited[i] = -1;
        v.push_back(vector<int>());
    }

    for(int i=0;i<m;i++){
        cin >> tmp;
        for(int j=0;j<tmp;j++){
            if(j == 0){
                cin >> before;
            }
            else{
                cin >> now;
                v[before].push_back(now);
                before = now;
            }
        }
    }
    bool go = true;
    for(int i=1;i<=n;i++){
        if(visited[i] == -1){
            if(dfs(i) == -1){
                cout << 0;
                go = false;
            }
        }
    }
    if(go){
        while(s.size() > 0){
            cout << s.top() << '\n';
            s.pop();
        }
    }
}