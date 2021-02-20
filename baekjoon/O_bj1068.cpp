/*
14m

그래프 - 연결요소개수 구하기 

삭제된 노드의 바로 위 부모의 리프노드 관련해서 고민
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;

int root;
int n;
int node[51]; // node[i] = 
int total = 0;
int d;

void go(int now){
    if(v[now].size() == 0){
        total = total + 1;
    }
    for(int i=0;i<v[now].size();i++){
        if(v[now][i] != d){
            go(v[now][i]);
        }
        else{
            if(v[now].size() == 1){
                total = total + 1;
            }
        }
    }
}

int main(){
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        v.push_back(vector<int>());
    }
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp == -1){
            root = i;
        }
        else{
            v[tmp].push_back(i);
        }
    }
    cin >> d;
    v[d].clear();
    go(root);
    if(n == 1 || d == root){
        cout << 0;
    }
    else{
        cout << total;
    }
}