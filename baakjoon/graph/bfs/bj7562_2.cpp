/*
2h+
- 체스 나이트 말 이동. 
그냥 bfs인데 처음에 좀더 효율적으로 접근하려다가 말판의 크기 제한으로 특수한 경우에 답이 달라져
일반적인 bfs로 다시 시도했음.

그러나 진입조건 부등호 실수와 큐의 초기화 실수로 인해 많은 시간이 소요됨.

*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int t;
int n;
int target_x;
int target_y;
int state = 0; // 0 : 도착못한 상태

queue<pair<int, int> > q1;
queue<pair<int, int> > q2;

int visited[301][301];

int push_queue(int x, int y){
    if(x == target_x && y == target_y){
        return 1;
    }
    else{
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            q2.push(make_pair(x,y));
        }
        return 0;
    }
}

int reduce_distance(){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }

    int len = q1.size();
    int go_x, go_y;
    int end = 0;
    for(int i=0;i<len;i++){
        go_x = q1.front().first;
        go_y = q1.front().second;
        q1.pop();
        if(go_x < (n-1) && go_y > 1){ // 1
            if(push_queue(go_x+1,go_y-2) == 1){
                return 1;
            }
        }
        if(go_x < (n-2) && go_y > 0){ // 2
            if(push_queue(go_x+2,go_y-1) == 1){
                return 1;
            }
        }
        if(go_x < (n-2) && go_y < (n-1)){ // 3
            if(push_queue(go_x+2,go_y+1) == 1){
                return 1;
            }
        }
        if(go_x < (n-1) && go_y < (n-2)){ // 4
            if(push_queue(go_x+1,go_y+2) == 1){
                return 1;
            }
        }
        if(go_x > 0 && go_y < (n-2)){ // 5
            if(push_queue(go_x-1,go_y+2) == 1){
                return 1;
            }
        }
        if(go_x > 1 && go_y < (n-1)){ // 6
            if(push_queue(go_x-2,go_y+1) == 1){
                return 1;
            }
        }
        if(go_x > 1 && go_y > 0){ // 7
            if(push_queue(go_x-2,go_y-1) == 1){
                return 1;
            }
        }
        if(go_x > 0 && go_y > 1){ // 8
            if(push_queue(go_x-1,go_y-2) == 1){
                return 1;
            }
        }
    }
    return reduce_distance() + 1;
}

void reset_visited(){
    for(int i=0;i<301;i++){
        for(int j=0;j<301;j++){
            visited[i][j] = 0;
        }
    }
}
 
int main(){
    cin >> t;
    int now_x, now_y;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> now_x;
        cin >> now_y;
        cin >> target_x;
        cin >> target_y;
        reset_visited();
        if(now_x == target_x && now_y == target_y){
            cout << 0 << endl;
        }
        else{
            while(q2.size() > 0){
                q2.pop();
            }
            q2.push(make_pair(now_x,now_y));
            visited[now_x][now_y] = 1;
            cout << reduce_distance() << endl;
        }
    }
}

