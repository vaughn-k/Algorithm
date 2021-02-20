/*
50m

방향그래프 순회

문제 개요 : n명의 사람들이 팀을 꾸리는데 한사람당 자신을 포함한 한명을 지목한다.

지목한 사람들끼리 한붓그리기가 가능하다면 그 멤버들끼리 한팀이 된다.
또한 자기자신을 지목해도 혼자 팀이된다.

하지만 그 외의 사람들은 팀을 못구한 사람들이 된다.
이때 팀을 구하지못한 사람들의 수를 구해보자.

* 팀이 되는 조건과 반복 횟수를 줄이기 위한 과정에서 고민을 많이했다.

*/

#include <iostream>
#include <stack>

using namespace std;

int t;
int n;
int start;
int total;
int p[100002];
int v[100002];
// v[i] = -1 : 미방문
// v[i] = 1 : 팀완성
// v[i] = 0 : 현재 방문중
// v[i] = -2 : 팀없음 확정
// v[i] = -3 : 솔플하는 사람
stack<int> s;

int go(int now){
    int next;
    int centor = 0;
    while(centor == 0){
        next = p[now];
        if(next == now){
            // 자기자신 솔플 확정
            centor = -11;
        }
        else if(v[next] == -1){ // 아직 방문안한곳 방문
            v[next] = 0;
            s.push(next);
        }
        else if(v[next] == 0){ // 팀완성 
            // 팀이 완성된다면 스택에서 팀을 완성시킨 시람까지는 팀이 확정이고
            // 스택에서 그 이전에 있는 사람들은 팀없는것이 확정이다.
            centor = next;
        }
        else{ // v[next] == -2
            centor = -1;
        }
        now = next;
    }
    int tmp;
    int swch = 1;
    if(centor == -1 || centor == -11){
        if(centor == -11){
            tmp = s.top();
            s.pop();
            v[tmp] = -3;
        }
        while(s.size() > 0){ 
            tmp = s.top();
            s.pop();
            v[tmp] = -2;
        }
    }
    else{
        while(s.size() > 0){ 
            tmp = s.top();
            s.pop();
            if(tmp == centor){
                swch = 0;
                v[tmp] = 1;
            }
            else if(swch == 1){
                v[tmp] = 1;
            }
            else{
                v[tmp] = -2;
            }
        }
    }
    return 0;
}

int dfs_run(){
    int sub = 0;
    for(int i=1;i<=n;i++){
        if(v[i] == -1){
            v[i] = 0;
            start = i;
            s.push(i);
            go(i);
        }
    }
    for(int i= 1;i<=n;i++){
        if(v[i] == -2){
            sub = sub + 1;
        }
    }
    return sub;
}

int main(){
    int tmp;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        for(int j=1;j<=n;j++){
            cin >> tmp;
            p[j] = tmp;
            v[j] = -1;
        }
        cout << dfs_run() << '\n';

    }

}