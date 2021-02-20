#include <iostream>
#include <queue>

using namespace std;

queue<int> q1;
queue<int> q2;
int n;
int Count = 0;

void bfs(){
    int now;
    q1 = q2;
    while(q2.size() > 0){ q2.pop(); }

    while(q1.size() > 0){
        now = q1.front();
        if(now == 0){
            return;
        }
        if(now >= 2){
            q2.push(now-2);
        }
        if(now >= 5){
            q2.push(now-5);
        }
        q1.pop();
    }
    Count++;
    bfs();
}

int main(){
    cin >> n;
    q2.push(n);
    bfs();
    cout << Count;
}