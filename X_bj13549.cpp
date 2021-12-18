#include <iostream>
#include <queue>

using namespace std;

int n,k;

int p[100001];
queue<int> q1;
queue<int> q2;

int main(){
    int count_ = 0;
    cin >> n >> k;
    for(int i=0;i<100001;i++){
        p[i] = 0;
    }
    if(n == k){
        cout << 0;
    }
    else{
        bool continue_ = true;
        p[n] = 1;
        q2.push(n);
        int now;
        int go;
        // 초반 2배
        q1 = q2;
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            go = now * 2;
            while(go <= 100000 && go != 0){
                if(p[go] == 0){
                    p[go] = 1;
                    q2.push(go);
                }
                go = go * 2;
            }
        }
        //
        while(q2.size() > 0 && continue_){
            q1 = q2;
            while(q2.size() > 0){ q2.pop(); }

            while(q1.size() > 0){
                now = q1.front();
                q1.pop();
                if(now == k){
                    continue_ = false;
                }

                for(int i=0;i<2;i++){
                    if(i == 0){ go = now - 1;}
                    else{ go = now + 1; }

                    if(go >= 0 && go <= 100000){
                        if(p[go] == 0){
                            p[go] = 1;
                            q2.push(go);
                        }
                    }
                }
                
            }

            q1 = q2;

            while(q1.size() > 0){
                now = q1.front();
                q1.pop();
                go = now * 2;
                while(go <= 100000 && go != 0){
                    if(p[go] == 0){
                        p[go] = 1;
                        q2.push(go);
                    }
                    go = go * 2;
                }
            }
            count_++;
        }
        count_ = count_ -1;
        cout << count_;
    }

}