/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.07.10

소요시간 : 2h+ / 37m

문제명 - 백준 16946 벽 부수고 이동하기 4
   
알고리즘
    - bfs
    - 컴포넌트 분리

문제개요
    1000    
    0001    
    0101  
    1110  

    과같이 주어지며, 0은 빈공간이고 1은 벽이다.
    어떤 벽을 뚫었을때 상하좌우로 빈공간이라면 이동가능한 구역이다.
    각 벽별로 뚫었을때 이동가능한 구역이 몇개인지 10으로 나눈 나머지를 출력하는문제.


    초기 input에서 이전의 섬과 바다 문제처럼 0끼리 붙어있는 구역을 나누어서 unique한 번호를 
    붙여주고, 해당 공간에 총 몇개의 공간이 있는지를 저장해두면 된다.

    예를들어 위와같은 경우 [0][1]부터 0이 나오므로 이곳과 연결된 0들은 모두 type = 0이 되고
    counts[0] = 8이 된다.

    이런식으로 모든 0 에 대한 공간에 대해 type을 저장해두고, 1차원 배열에서 counts배열을 통해
    type마다 total 개수를 적어두면된다.

    마지막으로 최종적으로 벽을 뚫을때 주의해야 할 점은, 상하좌우의 모든 count를 더하면 안된다는
    것이다.
    왜냐하면, 
    
    000
    010
    000

    과같은 경우 1의 상하좌우의 각 counts는 모두 8이다. 하지만 이 4공간은 모두 같은 컴포넌트,
    즉 같은 타입이므로 한번만 더해줘야한다. 이러한 중복 type을 체크해서 더해주어야한다. 

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <utility>
#include <string>

// 1 = 49
// 0 = 48


using namespace std;

queue<pair<int,int> > q1;
queue<pair<int,int> > q2;

int n,m;
int box[1001][1001];
int type[1001][1001];
// -2 : 현재 탐색중
// -1 : 탐색한적 x
// 0이상 : 본인의 타입
int counts[1000001];

int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};

void bfs(int ni, int nj, int nowType){
    q2.push(make_pair(ni,nj));
    type[ni][nj] = nowType;
    int nowi, nowj;
    int goi,goj;
    int tot = 1;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){ q2.pop(); }
        while(q1.size() > 0){
            nowi = q1.front().first;
            nowj = q1.front().second;
            q1.pop();
            for(int k=0;k<4;k++){
                goi = nowi + di[k];
                goj = nowj + dj[k];
                if(goi >= 0 && goj >= 0 && goi < n && goj < m){
                    if(type[goi][goj] == -1 && box[goi][goj] == 48){
                        type[goi][goj] = nowType;
                        q2.push(make_pair(goi,goj));
                        tot++;
                    }
                }
            }
        }
    }
    counts[nowType] = tot;
}

int main(){
    cin >> n >> m;
    string st;
    for(int i=0;i<n;i++){
        cin >> st;
        for(int j=0;j<m;j++){
            box[i][j] = st[j];
            type[i][j] = -1; // 타입이 정해지지 않은 상태

        }
    }
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(type[i][j] == -1 && box[i][j] == 48){
                bfs(i,j,index);
                index++;
            }
        }
    }

    int goi,goj;
    int subTotal;
    int used[4];
    bool same;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j] == 49){
                subTotal = 1;
                for(int k=0;k<4;k++){
                    used[k] = -1;
                }
                for(int k=0;k<4;k++){
                    goi = i + di[k];
                    goj = j + dj[k];
                    same = false;
                    if(goi >= 0 && goj >= 0 && goi < n && goj < m){
                        if(box[goi][goj] == 48){
                            used[k] = type[goi][goj];
                            for(int a=0;a<k;a++){
                                if(used[a] == type[goi][goj]){
                                    same = true;
                                }
                            }
                            if(!same){
                                subTotal += counts[type[goi][goj]];
                            }

                        }
                    }
                }
                cout << subTotal%10;
            }
            else{
                cout << 0;
            }
        }
        cout << endl;
    }
}