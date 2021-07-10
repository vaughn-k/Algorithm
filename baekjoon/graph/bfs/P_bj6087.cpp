/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.25

소요시간 : 2h

문제명 - 백준 6087 - 레이저 통신
   
알고리즘
    - BFS (일반적인 상하좌우 4칸 BFS가 아닌 상하좌우 직선 BFS)

문제개요
    nxm 격자판이 주어지고 특정 두점과 벽들이 주어질때 90도로 거울을 설치한다했을때 특정 한점에서
    다른 한점까지 거울로 레이저통신을 할때 최소로 필요한 거울의 개수

    처음에는 BFS상으로 최소경로일때를 구해서 그때 쓰인 거울의 개수를 답이라고 생각했지만 사실 
    거리상으로는 최단경로가 아니여도 거울을 더 적게쓸수있었다. 따라서 BFS구현시 현재 직전에 이동
    했던 방향과 90도 방향(예를 들어 직전에 위로 올라갔으면 이번에는 좌 또는 우로만 가능) 으로만
    이동해서 벽을 만나거나 범위를 초과하기 전까지의 모든 점을 등록했다.

    + 아래에서 구조체로 count 변수를 넣어놨지만 사실 지금보니까 필요없다. 왜냐면 어차피 BFS 
    한번 돌때마다 거울 한개씩 필요하기 때문에 BFS함수 자체에서 count변수를 두어도 무방하다.

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[101][101];
vector<string> v;
int n,m;

struct Elem{
    int i;
    int j;
    int before;
    int ct;
};

queue<Elem> q1;
queue<Elem> q2;

Elem ss;
Elem ee;

int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};
// U R D L
// 0 1 2 3

bool possibleGo(int s, int e){
    if(abs(s-e) == 1 || abs(s-e) == 3){
        return true;
    }
    else{
        return false;
    }
}

// void print(){
//     cout << "---------" << endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout << visited[i][j];
//         }
//         cout << endl;
//     }
//     cout << "---------" << endl;
// }

int bfs(){
    Elem elem;
    Elem next;
    int movei;
    int movej;
    char direction;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){
            q2.pop();
        }
        while(q1.size() > 0){
            elem = q1.front();

            for(int i=0;i<4;i++){
                // print();
                if(possibleGo(i,elem.before) || elem.ct == 0){ // 전과 90도 방향일때만 간다
                    movei = elem.i + di[i];
                    movej = elem.j + dj[i];
                    while(true){ // 범위를 벗어나거나 벽을 만날때까지 진행
                        if(movei >= 0 && movej >= 0 && movei < n && movej < m){
                            if(v[movei][movej] == 'C'){
                                return elem.ct;
                            }
                            if(v[movei][movej] == '*'){
                                break;
                            }
                            if(visited[movei][movej] == 0){
                                // 아직 방문하지 않은곳이고 갈수있는 길이라면
                                visited[movei][movej] = 1;
                                
                                // 다음 블록 생성
                                next.i = movei;
                                next.j = movej;
                                next.before = i;
                                next.ct = elem.ct + 1;
                                q2.push(next);
                            }
                        }
                        else{
                            break;
                        }
                        movei = movei + di[i];
                        movej = movej + dj[i];
                    }
                }
            }
            q1.pop();
        }   
    }
    return -1;
}

int main(){
    string s;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    Elem elem;
    int first = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
            if(v[i][j] == 'C'){
                if(first == 0){
                    ss.i = i;
                    ss.j = j;
                    ss.ct = 0;
                    ss.before = 4;
                    first = 1;
                }
                else{
                    ee.i = i;
                    ee.j = j;
                    ee.before = 4;
                    ee.ct = 0;
                }
                
            }
        }
    }
    q2.push(ss);
    cout << bfs();
}

