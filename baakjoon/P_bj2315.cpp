/*
3h++

dp

작년에 시도하다가 포기한 문제였다.

2일에 걸쳐 해결하였고 

출발지 기준으로 
왼쪽에 있는 가로등들(stack s)과 
오른쪽에 있는 가로등들(stack q)을 
각각의 스택에 넣고 재귀를 돌때 pop한후 다시 돌아오면 push하는 방식으로 설계
d[i][j][h][n] = 
i = s.size()
j = q.size() 일때 
이전에 h(왼쪽 or 오른쪽) 을 방문했었고 이번에는 n(왼쪽 or 오른쪽)을 방문할때 최소값

메모이제이션을 할때 모든 가로등의 상태는 저장할 필요가 없었다. 왜냐하면 중간의 가로등을 무시하고 이후의 가로등을 먼저끌수는 없기때문에

항상 출발지 기준 양옆 가로등부터 처리해야한다. (모든 요소를 다 고려하지 않고 의미있는 요소만 고려하는것은 2618 경찰차 문제와 흡사하다.)

따라서 출발지 기준 좌우측 가로등의 개수로 메모이제이션을 할수있을것이라고 생각했지만, 같은 갯수로 남아있더라도 마지막으로 방문한 곳이

좌측인지, 우측인지에 따라서도 이후 최소값이 바뀌므로 그 값도 필요했다. 

*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n,m;
int w[1002];
int store[1002][1002][2][2];
int total = 0;

stack<int> s;
stack<int> q;
stack<int> sub;

int dp(int position, char history, char direction, int count){

    if(s.size() == 0 && q.size() == 0){
        return 0;
    }
    if(direction == 'l' && s.size() == 0){
        return 2000000000;
    }
    if(direction == 'r' && q.size() == 0){
        return 2000000000;
    }

    int now;
    int dist;
    int cost;
    int left,right,ans,d_type,h_type;
    if(direction == 'l'){
        d_type = 1;
    }
    else{
        d_type = 2;
    }
    if(history == 'l'){
        h_type = 1;
    }
    else{
        h_type = 2;
    }
    if(history != 'x'){
        if(store[s.size()][q.size()][h_type][d_type] != -1){
            return store[s.size()][q.size()][h_type][d_type];
        }
    }

    if(direction == 'l'){
        now = s.top();
        s.pop();
    }
    else{
        now = q.top(); 
        q.pop();
    }

    dist = abs(position - now);

    cost = total * dist;
    total = total - w[now];
    left = dp(now, direction,'l', count+1);
    right = dp(now, direction,'r', count+1);


    total = total + w[now];
    ans = cost + min(left,right);
    if(direction == 'l'){
        s.push(now);
    }
    else{
        q.push(now);
    }
    if(history != 'x'){
        store[s.size()][q.size()][h_type][d_type] = ans;
    }
    return ans;

}

int main(){
    int tmp1,tmp2,start;
    cin >> n;
    cin >> m;
    for(int i=0;i<1002;i++){
        w[i] = 0;
        for(int j=0;j<1002;j++){
            for(int k=0;k<2;k++){
                for(int p=0;p<2;p++){
                    store[i][j][k][p] = -1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cin >> tmp1;
        cin >> tmp2;
        w[tmp1] = tmp2;
        if(i < m){
            s.push(tmp1);
            total = total + tmp2;
        }
        else if(m == i){
            start = tmp1;
        }
        else{
            sub.push(tmp1);
            total = total + tmp2;
        }
    }
    while(sub.size() > 0){
        q.push(sub.top());
        sub.pop();
    }

    int start_l,start_r;
    start_r = dp(start,'x','r',0);
    start_l = dp(start,'x','l',0);
    cout << min(start_l, start_r);

}