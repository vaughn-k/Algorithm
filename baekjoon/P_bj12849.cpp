/*
17m

백준 12849 - 본대 산책

알고리즘 : 그래프순환, mz

문제 개요 : 

건물들의 이동 할수 있는 간선들이 정해져있고 정확히 d번만에 특정 건물에서 출발해 돌아올때 그 횟수
*/

#include <iostream> 
#include <vector> 

using namespace std;

int d;
vector<vector<int> > v;
int dd[8][100001];

int run(int posi, int left){
    if(left == 1){
        if(posi == 5 || posi == 6){
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dd[posi][left] != -1){
        return dd[posi][left];
    }


    int total = 0;
    for(int i=0;i<v[posi].size();i++){
        total = (total + run(v[posi][i],left-1))%1000000007;
    }
    dd[posi][left] = total;
    return total;
}

int main(){
    cin >> d;
    for(int i=0;i<8;i++){
        v.push_back(vector<int>());
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<100001;j++){
            dd[i][j] = -1;
        }
    }
    v[0].push_back(1);
    v[0].push_back(2);

    v[1].push_back(0);
    v[1].push_back(3);

    v[2].push_back(0);
    v[2].push_back(3);
    v[2].push_back(4);

    v[3].push_back(1);
    v[3].push_back(2);
    v[3].push_back(4);
    v[3].push_back(5);

    v[4].push_back(2);
    v[4].push_back(3);
    v[4].push_back(5);
    v[4].push_back(6);

    v[5].push_back(3);
    v[5].push_back(4);
    v[5].push_back(6);
    v[5].push_back(7);

    v[6].push_back(4);
    v[6].push_back(5);
    v[6].push_back(7);

    v[7].push_back(5);
    v[7].push_back(6);

    cout << run(7,d);
}