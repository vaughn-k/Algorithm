/* 33m

3진트리 bfs
- 1차원배열
- queue

실제 풀이시간은 절반이였지만 실수로 많은 시간을 날림.

조건부분에서 사람이 0~100000 사이의 구간을 이동할수있는데 0을 미포함하여 계속 실패했다.

- if 조건 문제와 맞는지 잘 살피기!

*/
#include <iostream>
#include <queue>

using namespace std;
int n,k;

queue<int> q1;
queue<int> q2;

int position[100010];
int minimum = 0;

int move(int num){
    if(num >= 0 && num < 100001){
        if(num == k){
            return 1;
        }
        if(position[num] == 1){
            position[num] = 0;
            q2.push(num);
        }
        return 0;
    }
    return 0;
}

void find_min(){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    int len = q1.size();
    int check;
    int now;
    if(len > 0){
        minimum++;
        for(int i=0;i<len;i++){
            now = q1.front();
            check = move(now - 1) + move(now + 1) + move(now * 2);
            if(check > 0){
                return;
            }
            q1.pop();
        }
        if(q2.size() > 0){
            find_min();
        }
    }


}

int main(){
    cin >> n;
    cin >> k;

    for(int i=0;i<100001;i++){
        position[i] = 1;
    }

    position[n] = 0;
    position[k] = 0;

    if(n == k){
        cout << 0;
    }
    else{
        q2.push(n);
        find_min();
        cout << minimum;
    }
}