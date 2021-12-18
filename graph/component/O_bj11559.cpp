/*
30m

백준 11559 - Puyo Puyo

알고리즘 : 동일컴포넌트 찾기 + 구현

문제개요 : 

......  좌측과 같이 뿌요뿌요 판이 주어지고 총 몇 연쇄가 벌어지는지 출력
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.

*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<string> v;

int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};

int visited[12][6];

queue<pair<int, int> > q;
queue<char> qc;

// void print(){
//     for(int i=0;i<12;i++){
//         for(int j=0;j<6;j++){
//             cout << v[i][j];
//         }
//         cout << endl;
//     }
//     cout << "-------------------" << endl;
// }

void reset_visited(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            visited[i][j] = -1;
        }
    }
}

int findGroup(int i, int j, char type){
    // cout << "i,j : " << i << "," << j << " | type : " << type << endl;
    q.push(make_pair(i,j));
    int next_i, next_j;
    int total = 1;
    for(int k=0;k<4;k++){
        next_i = i + di[k];
        next_j = j + dj[k];
        if(next_i >= 0 && next_j >= 0 && next_i < 12 && next_j < 6){
            if(visited[next_i][next_j] == -1 && v[next_i][next_j] == type){
                visited[next_i][next_j] = 1;
                total = total + findGroup(next_i,next_j,type);
            }
        }
    }
    return total;
}

void reSort(){ // 문자사이에 비어있는 칸들을 위 문자들로 메꾸기
    char tmp;
    for(int j=0;j<6;j++){
        for(int i=11;i>=0;i--){
            if(v[i][j] != '.'){
                qc.push(v[i][j]);
            }
        }
        for(int i=11;i>=0;i--){
            if(qc.size() > 0){
                tmp = qc.front();
                qc.pop();
                v[i][j] = tmp;
            }
            else{
                v[i][j] = '.';
            }
        }
    }
}

int mainRun(){
    int count_ = -1;
    int continue_ = true;
    int nowTotal;
    pair<int, int> tmp;
    while(continue_){
        count_++;
        continue_ = false;
        reset_visited();
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(v[i][j] != '.' && visited[i][j] == -1){
                    visited[i][j] = 1;
                    nowTotal = findGroup(i,j,v[i][j]);
                    // cout << "nowtotal : " << nowTotal << endl;
                    if(nowTotal >= 4){
                        continue_ = true;
                        while(q.size() > 0){
                            tmp = q.front();
                            q.pop();
                            v[tmp.first][tmp.second] = '.';
                        }
                    }
                    while(q.size() > 0){
                        q.pop();
                    }
                }
            }
        }
        reSort();
        // print();
    }
    return count_;
}

int main(){
    string s;
    for(int i=0;i<12;i++){
        cin >> s;
        v.push_back(s);
    }

    cout << mainRun();
}

/*
......
......
......
......
......
......
......
......
......
......
......
RRYGG.
*/
