/*
27m

그래프 - 컴포넌트 구하기 반복

문제개요 : N x N 에 각각 사람들이 살고있고 칸마다 하나의 나라이다.

두나라 사이의 인구차가 주어진 l,r값 사이에 있다면 연합국이고 연합국들사이에서는 인구를 동일하게 맞춘다.

이같은 과정을 몇번 할수 있는지 찾기

*/

#include <iostream>
#include <queue>

using namespace std;

int n,l,r;
int country[51][51];
int visited[51][51];
int total = 0;

queue<pair<int,int> > q1;
queue<pair<int,int> > q2;
queue<pair<int,int> > fq;

void reset_visited(){
    for(int i=0;i<n;i++){        
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }
}

void make_team(){
    q1 = q2;
    while(q2.size()>0){ q2.pop(); }
    int dist;
    int x,y;
    pair<int, int> tmp;
    while(q1.size()>0){
        tmp = q1.front();
        q1.pop();
        x = tmp.first;
        y = tmp.second;
        if(x > 0){
            dist = abs(country[x][y] - country[x-1][y]);
            if(visited[x-1][y] == 0 && dist >= l && dist <= r){
                total = total + country[x-1][y];
                visited[x-1][y] = 1;
                q2.push(make_pair(x-1,y));
                fq.push(make_pair(x-1,y));
            }
        }   
        if(x < (n-1)){
            dist = abs(country[x][y] - country[x+1][y]);
            if(visited[x+1][y] == 0 && dist >= l && dist <= r){
                total = total + country[x+1][y];
                visited[x+1][y] = 1;
                q2.push(make_pair(x+1,y));
                fq.push(make_pair(x+1,y));
            }
        }   
        if(y > 0){
            dist = abs(country[x][y] - country[x][y-1]);
            if(visited[x][y-1] == 0 && dist >= l && dist <= r){
                total = total + country[x][y-1];
                visited[x][y-1] = 1;
                q2.push(make_pair(x,y-1));
                fq.push(make_pair(x,y-1));
            }
        }   
        if(y < (n-1)){
            dist = abs(country[x][y] - country[x][y+1]);
            if(visited[x][y+1] == 0 && dist >= l && dist <= r){
                total = total + country[x][y+1];
                visited[x][y+1] = 1;
                q2.push(make_pair(x,y+1));
                fq.push(make_pair(x,y+1));
            }
        }   
    }
    if(q2.size() > 0){
        make_team();
    }
}

void balance_people(){
    int bp = total / fq.size();
    pair<int, int> now;
    while(fq.size() > 0){
        now = fq.front();
        fq.pop();
        country[now.first][now.second] = bp;
    }
}

int move(){
    int check = 0;
    for(int i=0;i<n;i++){        
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0){
                while(q2.size() > 0){ q2.pop();}
                while(fq.size() > 0){ fq.pop();}
                total = country[i][j];
                visited[i][j] = 1;
                q2.push(make_pair(i,j));
                fq.push(make_pair(i,j));
                make_team();    
                if(fq.size() > 1){
                    balance_people();
                    check = 1;
                }            
            }
        }
    }
    return check;
}

int move_run(){
    int state = 1;
    int count = 0;
    while(state == 1){
        reset_visited();
        state = move();
        count ++;
    }
    return count-1;
}

int main(){
    cin >> n;
    cin >> l;
    cin >> r;

    for(int i=0;i<n;i++){        
        for(int j=0;j<n;j++){
            cin >> country[i][j];
        }
    }

    cout << move_run();
}