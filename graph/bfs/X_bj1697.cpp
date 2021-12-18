/*
30m

bfs

문제개요 : 0 <= n <= 100000 사이에 두사람이 서있고

0초 뒤에 *2 지점으로 갈수있고, 1초뒤에 +-1 지점으로 갈수있을때

가장 빠르게 갈수있는 횟수 출력

*2 지점으로 가는데는 시간이 소요되지 않으므로 처음에 시작점의 *2 지점들을 모두 큐에 넣어두고 동시에 1초뒤 갈수있는 목록에서도 *2 지점들을 넣어준다.

*/

#include <iostream>
#include <queue>

using namespace std;

int n,k;
int visited[100001];
queue<int> q1;
queue<int> q2;

int output(int x, int type){
    if(type == 1){
        return x-1;
    }
    else if(type == 2){
        return x+1;
    }
    else{
        return x*2;
    }
    return -1;
}

int find(){
    int now;
    int next;
    int count = 1;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){ q2.pop(); }
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            for(int t=1;t<=3;t++){
                next = output(now,t);
                if(next >= 0 && next <= 100000){
                    if(next == k){
                        return count;
                    }
                    if(visited[next] == -1){
                        visited[next] = 1;
                        q2.push(next);
                    }
                }
            }
        }
        count++;
    }
    return -1;
}

int main(){
    cin >> n;
    cin >> k;
    for(int i=0;i<100001;i++){
        visited[i] = -1;
    }
    if(n == k){
        cout << 0;
    }
    else{
        q2.push(n);
        cout << find();
    }
}
