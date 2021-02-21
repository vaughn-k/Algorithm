/*

그래프 - bfs

문제 개요 : 숨바꼭질 4

최소횟수뿐만 아니라 해당하는 경로까지 출력하는 문제(스페셜 저지)

*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n,k;
int visited[100001];
int h[100001];
queue<int> q1;
queue<int> q2;
stack<int> s;

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
                        h[next] = now;
                        return count;
                    }
                    if(visited[next] == -1){
                        visited[next] = visited[next] + 1;
                        h[next] = now;
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
        cout << 0 << endl;
        cout << k << endl;
    }
    else{
        q2.push(n);
        cout << find() << endl;
        int tmp = k;
        while(tmp != n){
            s.push(h[tmp]);
            tmp = h[tmp];
        }

        while(s.size() > 0){
            cout << s.top() << " ";
            s.pop();
        }
        cout << k;
    }
}
