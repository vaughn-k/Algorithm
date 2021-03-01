#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,k;
int know[51];
int lie[51];
vector<vector<int> > v;
queue<int> now;
queue<int> wait;


int main(){
    int tmp,count;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        know[tmp] = 1;
    }
    for(int i=1;i<=m;i++){
        lie[i] = 0;
        wait.push(i);
    }
    v.push_back(vector<int>());
    for(int i=1;i<=m;i++){
        v.push_back(vector<int>());
        cin >> count;
        for(int j=0;j<count;j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    int check = 1;
    while(check == 1){
        int w;
        now = wait;
        while(wait.size() > 0){wait.pop();}
        while(now.size() >0 ){
            w = now.front();
            now.pop();
            
            
        }
    }

}