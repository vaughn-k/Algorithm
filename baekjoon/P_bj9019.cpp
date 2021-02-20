/*
52m

bfs + 경로저장

0~9999까지 저장 가능한 계산기에 
D,S,L,R 기능 (2배, -1, 좌로스위치, 우로스위치) 을 이용해서 
input -> output 으로 만드는데 최소 횟수를 만드는 DSLR 을 출력하는 문제인데
출력을 SD로 해야하는데 마지막부터 출력하는 바람에 거꾸로 출력되어 많은 시간 소요.

그래서 stack을 이용하여 뒤부터 stack에 넣어 다시 앞부터 출력하도록하였다.

* 여기서의 포인트는 bfs를 이용하여 최단 횟수를 잡아내는것과
* before[]과 before_c[]를 이용한 경로저장
예시) 예를 들어 1000에서 D 를 이용해 2000을 만들었다면
before[1000] = 2000
before_c[1000] = 'D'

+ 편의상 DSLR은 배열에 넣어 인덱스로 관리하였다.
*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int t;
int input,output;

queue<int> q1;
queue<int> q2;
stack<int> s;

int visited[10001];
int before[10001];
int before_c[10001];
char cc[] = {'D','S','L','R'};

void reset(){
    for(int i=0;i<10000;i++){
        visited[i] = 0;
        before[i] = -1;
        before_c[i] = -1;
    }
}

int regist(char c, int x){
    int sub;
    if(c == 'D'){
        x = (x*2)%10000;
    }
    else if(c == 'S'){
        if(x == 0){
            x = 9999;
        }
        else{
            x = x-1;
        }
    }
    else if(c == 'L'){
        sub = x/1000;
        x = (x-sub*1000)*10 + sub;
    }
    else{
        sub = x%10;
        x = x/10 + sub*1000;
    }
    return x;
}

void bfs(){
    int now;
    int out;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){q2.pop();}
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            for(int i=0;i<4;i++){
                out = regist(cc[i],now);
                if(visited[out] == 0){
                    visited[out] = 1;
                    before[out] = now;
                    before_c[out] = i;
                    if(out == output){
                        return;
                    }
                    q2.push(out);
                }
            }
        }
    }
}

int main(){
    int now;
    cin >> t;
    for(int i=0;i<t;i++){
        reset();
        cin >> input;
        cin >> output;
        while(q2.size() > 0){q2.pop();}
        q2.push(input);
        visited[input] = 1;
        bfs();
        now = -1;

        while(now != input){
            now = before[output];
            s.push(before_c[output]);
            output = now;
        }
        while(s.size() > 0){
            cout << cc[s.top()];
            s.pop();
        }
        cout << '\n';
    }
}