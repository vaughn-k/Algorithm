/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.07.10

소요시간 : 2h+

문제명 - 백준 10159 저울
   
알고리즘
    - 방향그래프
    - brute-force
    - 순서쌍 일반/역방향 동시저장

문제개요

    n개의 물건이 있고 m개의 순서쌍(물건 두개의 무게비교 순서쌍) 이 주어진다.
    이때 각 물건별로 자신과 무게의 대소를 비교할 수 없는 물건의 개수를 출력하는 문제.

    만약 물건무게가 a > b 라면
    a->b 처럼 표현한다고 하자.

    이렇게 되면 a기준에서 dfs로 갈수있는 모든 물건은 a와 비교할 수 있다.
    
    또한 x<-a 의 경로로 무게의 역방향으로만 가도 모든 물건은 a와 비교할 수 있다.

    이 두가지의 합이 a와 비교가능한 물건들의 합일것이다.
    (a>b, b>c, c>a) 와 같이 불가능한 사례는 없다고 명시되어 있기떄문에 무한루프는 발생하지 않는다.

    따라서 정방향과 역방향 벡터 두개를 사용하였다.

    여기서 고려해야할 점은 a->b->c 라는 경로가 있는데 a->c 라는경로도 존재할 때 이다.
    이때는 중복체크가 될수 있기때문에 각 dfs를 돌때 visited 배열을 사용해서 이미 방문한 물건에는
    방문해서는 안된다.
   
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>

using namespace std;

int n,m,t1,t2;
vector<vector<int> > v1;
vector<vector<int> > v2; // reverse of v1
int visited[102];

void resetVisited(){
    for(int i=1;i<=n;i++){
        visited[i] = 0;
    }
}


int dfs1(int now){
    // cout << "now : " << now << endl;
    visited[now] = 1;
    int subtot = 1;
    if(v1[now].size() > 0){
        for(int i=0;i<v1[now].size();i++){
            if(visited[v1[now][i]] == 0){
                subtot += dfs1(v1[now][i]); 
            }
        }
    }
    return subtot;
}
int dfs2(int now){
    // cout << "now : " << now << endl;
    visited[now] = 1;
    int subtot = 1;
    if(v2[now].size() > 0){
        for(int i=0;i<v2[now].size();i++){
            if(visited[v2[now][i]] == 0){
                subtot += dfs2(v2[now][i]); 
            }
        }
    }
    return subtot;
}

int main(){
    cin >> n >> m;
    
    for(int i=0;i<n+1;i++){
        v1.push_back(vector<int>());
        v2.push_back(vector<int>());
    }
    for(int i=0;i<m;i++){
        cin >> t1 >> t2;
        v1[t1].push_back(t2);
        v2[t2].push_back(t1);
    }

    int tot;
    int ans;
    for(int i=1;i<n+1;i++){
        resetVisited();
        t1 = dfs1(i) - 1; 
        resetVisited();
        t2 = dfs2(i) - 1;
        ans = n - t1 - t2 - 1;
        cout << ans << endl;
        // tot = n - dfs1(i) - dfs2(i) + 1;
        // cout << tot << endl;
    }

    
}