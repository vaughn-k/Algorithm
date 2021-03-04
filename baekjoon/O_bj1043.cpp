/*
2h

백준 1043 - 거짓말

사용 알고리즘 : queue, 방문표시

문제 개요 : 

n명의 사람들과 m개의 모임이 있다. 

n명의 사람들중 k명은 주인공의 진실을 알고있어서 진실을 알고있는 사람이 있는 방에서는 반드시 진실만을 말해야한다.

또한 같은 방에서 진실을 듣게된 사람도 모두 진실을 알게될때

최대한 거짓말을 많이하고자할때 그 횟수는?

-> 첫번째로 헷갈렸던 부분은 모임에 방문하는 순서의 중요성 이였다.
사실 그 순서는 중요하지 않았다.

-> 그다음으로 이 파티들을 어떻게 순환할것인가에서 매 순환마다 진실을 확실히 알고있는 사람을 fix해놓고
그 사람이 속한 모든 모임의 사람들을 큐에 올렸다.(이 과정에서 visited 배열을 활용해 중복해서 큐에 들어가지 않도록 한다.)
그리고 그 순환을 큐가 빌때까지 반복하면서 진행한 후 마지막 까지 살아남은 모임의 개수를 통해 거짓말 할 수 있는 모임의 갯수를 알아낼 수 있다.


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,k;
int know[51]; // 진실을 아는 사람
int visited[51]; // 사람 방문 여부
int room[51]; // 반드시 진실을 말해야 하는 방 == 1
vector<vector<int> > v;
queue<int> now;
queue<int> q;


int main(){
    int tmp,count;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        know[i] = 0;
        visited[i] = 0;
    }
    for(int i=0;i<k;i++){
        cin >> tmp;
        know[tmp] = 1;
        q.push(tmp);
    }

    v.push_back(vector<int>());
    for(int i=1;i<=m;i++){
        v.push_back(vector<int>());
        cin >> count;
        room[i] = 0;
        for(int j=0;j<count;j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }



    int check = 1;
    int w;
    while(q.size() > 0){ // 현재 진실을 알고있는 사람을 한명 빼서 모든 파티를 돌면서 추가로 진실을 알게된 사람을 큐에 넣는다
        w = q.front();
        q.pop();
        // cout << w << endl;
        for(int i=1;i<=m;i++){
            if(room[i] == 0){ // 아직 진실을 말할지 거짓을 말할지 못정한 방
                for(int j=0;j<v[i].size();j++){
                    if(w == v[i][j]){ // 진실만을 말해야 하는 방인것이 확실시
                        room[i] = 1; // 해당방은 진실방으로 판정
                        for(int k=0;k<v[i].size();k++){
                            if(know[v[i][k]] == 0){ // 진신을 알게된 새로운 사람
                                know[v[i][k]] = 1;
                                q.push(v[i][k]);
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    int ans = m;
    for(int i=1;i<=m;i++){
        ans = ans - room[i];
        // cout << room[i] << " ";
    }
    cout << ans;
}