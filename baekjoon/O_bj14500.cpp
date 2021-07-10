/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.24

소요시간 : 30m

문제명 - 백준 14500 - 테트로미노
   
알고리즘
    - 구현

문제개요
    nxm 격자판이 주어지고 각 지점마다 양수가 주어질때 테트리미노7개를(방향전환 가능) 한개 놓았을때 
    그 4블록의 합이 최대가 되는 값 구하기

    블록이 5개만 주어져서 5개로만 했었는데 좌우반전도 가능했다 -> 문제 잘 읽기

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m;
int map[501][501];

vector<vector<pair<int, int> > > v;

void test(){   

    int sub[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            sub[i][j] = 0;
        }
    }

    int nowi,nowj;
    for(int i=0;i<18;i++){
        for(int p=0;p<4;p++){
            nowi = 5 + v[i][p].first;
            nowj = 5 + v[i][p].second;
            sub[nowi][nowj] = 1;
        }
        cout << "draw -------- " << i << " ---- " << endl;
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                cout << sub[j][k];
            }
            cout << endl;
        }
        cout << "draw ------------ " << endl;
        for(int p=0;p<4;p++){
            nowi = 5 + v[i][p].first;
            nowj = 5 + v[i][p].second;
            sub[nowi][nowj] = 0;
        }
    }
    
}

int findMax(int ct){
    int nowi,nowj;
    int subtot = 0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            subtot = 0;
            for(int k=0;k<4;k++){
                nowi = i + v[ct][k].first;
                nowj = j + v[ct][k].second;
                if(nowi >= 0 && nowj >= 0 && nowi < n && nowj < m){
                    subtot = subtot + map[nowi][nowj];
                    if(k == 3){
                        if(maxi < subtot){
                            maxi = subtot;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    return maxi;
}

int mainLoop(){
    int maxi = 0;
    for(int i=0;i<19;i++){
        maxi = max(maxi, findMax(i));
    }
    return maxi;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    v.push_back(vector<pair<int, int> >());
    v[0].push_back(make_pair(0,0));
    v[0].push_back(make_pair(1,0));
    v[0].push_back(make_pair(2,0));
    v[0].push_back(make_pair(3,0));
    
    v.push_back(vector<pair<int, int> >());
    v[1].push_back(make_pair(0,0));
    v[1].push_back(make_pair(0,1));
    v[1].push_back(make_pair(0,2));
    v[1].push_back(make_pair(0,3));
    
    v.push_back(vector<pair<int, int> >());
    v[2].push_back(make_pair(0,0));
    v[2].push_back(make_pair(1,0));
    v[2].push_back(make_pair(1,1));
    v[2].push_back(make_pair(2,1));
    
    v.push_back(vector<pair<int, int> >());
    v[3].push_back(make_pair(0,0));
    v[3].push_back(make_pair(0,1));
    v[3].push_back(make_pair(-1,1));
    v[3].push_back(make_pair(-1,2));
    
    v.push_back(vector<pair<int, int> >());
    v[4].push_back(make_pair(0,0));
    v[4].push_back(make_pair(0,1));
    v[4].push_back(make_pair(0,2));
    v[4].push_back(make_pair(-1,1));
    
    v.push_back(vector<pair<int, int> >());
    v[5].push_back(make_pair(0,0));
    v[5].push_back(make_pair(0,1));
    v[5].push_back(make_pair(0,2));
    v[5].push_back(make_pair(1,1));
    
    v.push_back(vector<pair<int, int> >());
    v[6].push_back(make_pair(0,0));
    v[6].push_back(make_pair(1,0));
    v[6].push_back(make_pair(2,0));
    v[6].push_back(make_pair(1,1));
    
    v.push_back(vector<pair<int, int> >());
    v[7].push_back(make_pair(0,0));
    v[7].push_back(make_pair(-1,1));
    v[7].push_back(make_pair(0,1));
    v[7].push_back(make_pair(1,1));
    
    v.push_back(vector<pair<int, int> >());
    v[8].push_back(make_pair(0,0));
    v[8].push_back(make_pair(1,0));
    v[8].push_back(make_pair(0,1));
    v[8].push_back(make_pair(1,1));
    
    v.push_back(vector<pair<int, int> >());
    v[9].push_back(make_pair(0,0));
    v[9].push_back(make_pair(1,0));
    v[9].push_back(make_pair(2,0));
    v[9].push_back(make_pair(2,1));

    v.push_back(vector<pair<int, int> >());
    v[10].push_back(make_pair(0,0));
    v[10].push_back(make_pair(0,1));
    v[10].push_back(make_pair(0,2));
    v[10].push_back(make_pair(-1,2));

    v.push_back(vector<pair<int, int> >());
    v[11].push_back(make_pair(0,0));
    v[11].push_back(make_pair(0,1));
    v[11].push_back(make_pair(1,1));
    v[11].push_back(make_pair(2,1));

    v.push_back(vector<pair<int, int> >());
    v[12].push_back(make_pair(0,0));
    v[12].push_back(make_pair(0,1));
    v[12].push_back(make_pair(0,2));
    v[12].push_back(make_pair(1,0));

    v.push_back(vector<pair<int, int> >());
    v[13].push_back(make_pair(0,0));
    v[13].push_back(make_pair(0,1));
    v[13].push_back(make_pair(1,1));
    v[13].push_back(make_pair(1,2));

    v.push_back(vector<pair<int, int> >());
    v[14].push_back(make_pair(0,0));
    v[14].push_back(make_pair(1,0));
    v[14].push_back(make_pair(1,-1));
    v[14].push_back(make_pair(2,-1));

    v.push_back(vector<pair<int, int> >());
    v[15].push_back(make_pair(0,0));
    v[15].push_back(make_pair(0,1));
    v[15].push_back(make_pair(-1,1));
    v[15].push_back(make_pair(-2,1));

    v.push_back(vector<pair<int, int> >());
    v[16].push_back(make_pair(0,0));
    v[16].push_back(make_pair(0,1));
    v[16].push_back(make_pair(0,2));
    v[16].push_back(make_pair(1,2));

    v.push_back(vector<pair<int, int> >());
    v[17].push_back(make_pair(0,0));
    v[17].push_back(make_pair(0,1));
    v[17].push_back(make_pair(1,0));
    v[17].push_back(make_pair(2,0));

    v.push_back(vector<pair<int, int> >());
    v[18].push_back(make_pair(0,0));
    v[18].push_back(make_pair(1,0));
    v[18].push_back(make_pair(1,1));
    v[18].push_back(make_pair(1,2));
    // test();
    cout << mainLoop();
}