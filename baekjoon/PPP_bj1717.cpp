/*

백준 1717번 - 집합의 표현

알고리즘 : 상호 배타적 집합

문제개요 : 각 원소들의 합집합 연산들이 주어지고 두원소를 주었을때 둘이 같은 집합인지 아닌지 판별


+ 시간초과 
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
로 해결하기

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<int> v;
queue<int> q;

int findRoot(int k){
    q.push(k);
    while(v[k] != k){
        k = v[k];
        q.push(k);
    }
    while(q.size() > 0){
        v[q.front()] = k;
        q.pop();
    }
    return k;
}

void Union(int a, int b){
    int rootA,rootB;
    rootA = findRoot(a);
    rootB = findRoot(b);
    if(rootA != rootB){
        v[rootA] = rootB;
    }
}

bool FindUnion(int a, int b){
    if(findRoot(a) == findRoot(b)){
        return true;
    }
    else{
        return false;
    }
}

void print(){
    cout << "------------------------" << endl;
    for(int i=0;i<=n;i++){
        cout << "v[" << i << "]" << v[i] << endl;
    }
    cout << "------------------------" << endl;
}

int main(){ 
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    int func,tmp1,tmp2;
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        v.push_back(i);
    }
    
    for(int i=0;i<m;i++){
        cin >> func >> tmp1 >> tmp2;
        if(func == 0){
            Union(tmp1,tmp2);
        }
        else{
            if(FindUnion(tmp1,tmp2)){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }
}

/*
12 11
0 11 10
0 10 5
0 9 4
0 4 3
0 5 3
0 3 7
1 11 9
1 7 7
1 3 4
1 12 1
1 0 1
*/

