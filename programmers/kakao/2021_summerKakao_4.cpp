4

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Dump{
    int end;
    int price;
    int able;
};

vector<vector<Dump> > v;
int tp[1001];
int state[1001];
int state2;
int st,ed;
int visited[1001][1001][1024];
int maxN;
int tmpTrapNum[11];

void addTrap(int index){
    int move = 1;
    move = move << index;
    state2 = state2 + move;
}

void deleteTrap(int index){
    int move = 1;
    move = move << index;
    state2 = state2 - move;
}

bool check(int index){
    int input = state2;
    int move = 1;
    move = move << index;
    int ans = input & move;
    if(ans <= 0){
        addTrap(index);
        return true;
    }
    else{
        deleteTrap(index);
        return false;
    }
}

int convertTrap(int n){
    for(int i=0;i<10;i++){
        if(tmpTrapNum[i] == n){
            cout << "real  : " << i << endl;
            return i;
        }
    }
}

void print(){
    cout << " state : ";
    for(int i=1;i<=maxN;i++){
        cout << state[i] << ' ';
    }
    cout << endl;
}

void switchState(int index){
    int with;
    int cv = convertTrap(index);
    check(cv);
    
    if(tp[index] == 1){

        if(state[index] == 0){
            state[index] = 1;
        }
        else{
            state[index] = 0;
        }
        for(int i=0;i<v[index].size();i++){
            with = v[index][i].end;
            if(state[with] == 1){
                state[with] = 0;
            }
            else{
                state[with] = 1;
            }
        }
    }
}

int dfs(int now, int price){
    cout << "state2 : " << state2 << endl;
    print();
    
    if(now == ed){
        return 0;
    }
    int minimum = 2000000000;
    int next;
    for(int i=0;i<v[now].size();i++){
        cout << "now -> end : " << now << " " << v[now][i].end << " // " << v[now][i].able << " " << state[now] << endl;
        if(v[now][i].able == state[now]){
            next = v[now][i].end;
            if(visited[now][next][state2] == 0){
                cout << "go go " << endl;
                visited[now][next][state2] = 1;
                if(tp[next] == 1){
                    switchState(next);
                    minimum = min(minimum, v[now][i].price + dfs(next,price + v[now][i].price));
                    switchState(next);    
                }
                else{
                    minimum = min(minimum, v[now][i].price + dfs(next,price + v[now][i].price));
                }
            }
        }
    }
    return minimum;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    state2 = 0;
    maxN = n;
    st = start;
    ed = end;
    Dump dump;
    int tmp_start,tmp_end,tmp_price;
    for(int i=0;i<=n;i++){
        v.push_back(vector<Dump>());
    }
    for(int i=0;i<roads.size();i++){
        tmp_start = roads[i][0];
        tmp_end = roads[i][1];
        tmp_price = roads[i][2];
        
        dump.end = tmp_end;
        dump.price = tmp_price;
        dump.able = 1;
        v[tmp_start].push_back(dump);
        
        dump.end = tmp_start;
        dump.able = 0;
        v[tmp_end].push_back(dump);
    }
    
    for(int i=1;i<=n;i++){
        tp[i] = 0;
        state[i] = 1;
    }
    
    for(int i=0;i<traps.size();i++){
        tp[traps[i]] = 1;

    }
    
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int j=1;j<=1025;j++){
                visited[i][k][j] = 0;
            }    
        }
    }
    
    for(int i=0;i<traps.size();i++){
        tmpTrapNum[i] = traps[i];
    }
    
    answer = dfs(start,0);
    
    return answer;
}