#include <iostream>
#include <queue>

using namespace std;

int m,n;
queue<int> q1;
queue<int> q2;
queue<int> ans;

int main(){
    cin >> m >> n;
    for(int i=2;i<=n;i++){
        q2.push(i);
    }

    int s;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){
            q2.pop();
        }
        s = q1.front();
        q1.pop();
        ans.push(s);
        while(q1.size() > 0){
            if(q1.front()%s != 0){
                q2.push(q1.front());
            }
            q1.pop();
        }
    }

    while(ans.size() > 0){
        if(ans.front() >= m){
            cout << ans.front() << '\n';
        }
        ans.pop();
    }
}