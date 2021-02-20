/*
18m

그래프 - bfs

엘레베이터가 있고 시작위치, 목적지위치, 위아래 버튼 클릭시 움직이는 층수가 주어지고 가장 적은 버튼클릭으로

목적지를 갈수있는 횟수를 구하는 문제였다.

시작지점부터 now + u , now - d 두가지 경우를 bfs로 탐색하면서 최초에 목적지를 도달했을때의 count를 출력한다.

또한 방문여부를 체크하기위해 배열을 사용해서 방문한곳은 방문하지 못하게 함으로써 중복을 없애고, 갈수없는 층을 골라낸다.
*/

#include <iostream>
#include <queue>

using namespace std;

queue<int> q1;
queue<int> q2;

int f,s,g,u,d;
int visited[1000002];

int bfs(){
    int now;
    int count = -1;
    while(q2.size() > 0){
        count = count + 1;
        q1 = q2;
        while(q2.size() > 0){ q2.pop(); }
        while(q1.size() > 0){ 
            now = q1.front();
            if(now == g){
                return count;
            }
            q1.pop(); 
            if(now + u <= f){
                if(visited[now+u] == -1){
                    visited[now+u] = 1;
                    q2.push(now+u);
                }
            }
            if(now - d >= 1){
                if(visited[now-d] == -1){
                    visited[now-d] = 1;
                    q2.push(now-d);
                }
            }
        }
    }
    return -1;
}

int main(){
    cin >> f;
    cin >> s;
    cin >> g;
    cin >> u;
    cin >> d;
    for(int i=0;i<=f;i++){
        visited[i] = -1;
    }    
    
    if(s == g){
        cout << 0;
    }
    else{
        visited[s] = 1;
        q2.push(s);
        int ans = bfs();
        if(ans >= 0){
            cout << ans;
        }
        else{
            cout << "use the stairs";
        }
    }
}