/*
37m

백준 12851 - 숨바꼭질 2

알고리즘 : bfs - visited 심화

문제개요 : a,b의 위치(0 <= a,b <= 100000) 가 주어지고 +1,-1,*2 만을 이용하여

가장 최소 횟수로 a에서 b를 갈때 그 최소횟수와 그때의 경우의수

만약 pCount[i] 가 i번에 최소의 거리로 갈때 그 경우의 수 라고 할때

x1,x2 에서 y로 갈수있다고 하면 pCount[y] = pCount[x1] + pCount[x2] 이런식으로 된다.

*/

#include <iostream>
#include <queue>

using namespace std;

int n,m;

int p[100001];
int pCount[100001];

queue<int> q1;
queue<int> q2;

int main(){
    for(int i=0;i<100001;i++){
        p[i] = 0;
        pCount[i] = 0;
    }
    cin >> n >> m;
    if(n == m){
        cout << 0 << endl;
        cout << 1 << endl;
    }
    else{
        int cycle = 0;
        int seq = 1;
        int go;
        int now;
        q2.push(n);
        pCount[n] = 1;
        bool continue_ = true;
        while(q2.size() > 0 && continue_){
            q1 = q2;
            while(q2.size() > 0){ q2.pop(); }
            while(q1.size() > 0){
                now = q1.front();
                q1.pop();
                for(int i=0;i<3;i++){
                    if(i == 0){ go = now-1;}
                    else if(i == 1){ go = now+1;}
                    else{ go = now * 2;}
                    
                    if(go >= 0 && go <= 100000){
                        if(go == m){
                            continue_ = false;
                        }
                        if(p[go] == 0){
                            p[go] = seq;
                            pCount[go] = pCount[now];
                            q2.push(go);
                        }
                        else if(p[go] == seq){
                            pCount[go] = pCount[go] + pCount[now];
                        }
                    }
                }

            }
            cycle++;
            seq++;
        }
        cout << cycle << endl;
        cout << pCount[m];
    }
}