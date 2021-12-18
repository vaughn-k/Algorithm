#include <iostream>
#include <queue>

using namespace std;

int n,m;

int d[502];
int check[502];
queue<int> q;

int findRoot(int x){
    q.push(x);
    while(d[x] != x){
        x = d[x];
        q.push(x);
    }
    while(q.size() > 0 ){
        d[q.front()] = x;
        q.pop();
    }
    return x;
}


void unionAB(int a, int b){
    int rootA,rootB;
    rootA = findRoot(a);
    rootB = findRoot(b);
    if(rootA != rootB){
        d[rootA] = rootB;
    }
}

int main(){
    int a,b,total;
    n = 1;
    m = 1;
    while(!(n == 0 && m == 0)){
        cin >> n >> m;
        if(!(n == 0 && m == 0)){
            for(int i=1;i<=n;i++){
                d[i] = i;
                check[i] = 0;
            }
            for(int i=0;i<m;i++){
                cin >> a >> b;
                unionAB(a,b);
            }
            total = 0;
            for(int i=1;i<=n;i++){
                if(check[d[i]] == 0){
                    check[d[i]] = 1;
                    total = total + 1;
                }
            }
            cout << total;
        }
    }
}