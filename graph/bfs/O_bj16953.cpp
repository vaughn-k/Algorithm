/*
15m

백준 16953 - A -> B

BFS

정수 a를 b로 바꿀건데 2를 곱하거나, 10을곱하고 1을 더할수 있을때

최소횟수로 바꾸는 횟수출력

*/

#include <iostream>
#include <queue>

using namespace std;

int a,b;
queue<int> q1;
queue<int> q2;

int run(){
    int now;
    int count = 1;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){q2.pop();}
        while(q1.size() > 0){
            now = q1.front();
            if(now == b){
                return count;
            }
            if(now < b){
                if(now <= 500000000){
                    q2.push(now*2);
                }
                if(now <= 100000000){
                    q2.push(now*10+1);
                }
            }
            q1.pop();
        }
        count++;
    }
    return -1;
}

int main(){
    cin >> a >> b;
    q2.push(a);
    cout << run();
}

