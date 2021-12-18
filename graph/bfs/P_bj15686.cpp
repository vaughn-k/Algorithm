/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.28

소요시간 : 1h

문제명 - 백준 15686 - 치킨 배달
   
알고리즘
    - bfs 활용

문제개요
    n by n 배열에 집과 치킨집이 주어지고 치킨집중 m개만 살려야할때, m개의 치킨집으로 집과 치킨
    집 사이거리의 최솟값 출력

    치킨집의 최대개수가 13이고 m = 6 또는 7일때가 13C6으로 최대 경우의 수이다.

    각 치킨집 별로 해당 치킨집을 골랐을때와 그러지않았을때 모두 비교해봐야하므로 dfs로 순환하였다.

    그전에 각 지점별 집과의 거리를 알기위해 bfs를 이용하여 각 치킨집마다 bfs를 돌며 집과의 거리를
    저장했다. (dist 배열)

    이후 dfs에서는 치킨집을 고를때마다 각 집간의 최소거리를 업데이트해주고 left(앞으로 고를수 있는
    치킨집 수) 값이 0이 되면 해당 배열의 원소들의 합을 출력한다.

    이 값들 중 가장 최소값을 출력한다.

*//////////////////////////////////////////////////////////////////////////




#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,m,chi,house = 0;
int map[51][51];
int dist[101][14];

int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};

queue<pair<int, int> > q1;
queue<pair<int, int> > q2;

void bfs(int si, int sj, int chickenN){
    int tmpMap[51][51];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmpMap[i][j] = map[i][j];
        }
    }
    pair<int, int> now;
    int goi,goj;
    int number;
    int cot = 1;
    tmpMap[si][sj] = -10;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){
            q2.pop();
        }
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            for(int i=0;i<4;i++){
                goi = now.first + di[i];
                goj = now.second + dj[i];
                if(goi >= 0 && goj >= 0 && goi < n && goj < n){
                    number = tmpMap[goi][goj];
                    if(number != -10){
                        if(number > 0){
                            dist[number-1][chickenN] = cot;
                        }
                        q2.push(make_pair(goi,goj));
                        tmpMap[goi][goj] = -10;
                    }
                }
            }
        }
        cot++;
    }
}

int go(int index, bool select, int left, int arr[]){
    if(chi - index - 1 < left){
        return 100000;
    }
    int tmp[101];
    if(select){
        for(int i=0;i<house;i++){
            tmp[i] = min(arr[i],dist[i][index]);
        }
    }
    else{
        for(int i=0;i<house;i++){
            tmp[i] = arr[i];
        }
    }
    if(left == 0){
        int tot = 0;
        // cout << "--index : " << index << "-------" << endl;
        for(int i=0;i<house;i++){
            tot = tot + tmp[i];
            // cout << "tot " << tot << endl;
            // cout << "arr " << tmp[i] << endl;
        }
        // cout << "---------" << endl;
        return tot;
    }
    return min(go(index+1,true,left-1,tmp),go(index+1,false,left,tmp));
}

int main(){
    cin >> n >> m;
    int tmp;
    int index = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> tmp;
            if(tmp == 1){
                map[i][j] = index;
                index++;
                house++;
            }
            else if(tmp == 2){
                map[i][j] = -1;
                chi++;
            }
        }
    }
    index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == -1){
                q2.push(make_pair(i,j));
                bfs(i,j,index);
                index++;
            }
        }
    }

    // for(int i=0;i<house;i++){
    //     for(int j=0;j<chi;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans;
    int arr[101];
    for(int i=0;i<house;i++){
        arr[i] = 1000000;
    }
    ans = min(go(0,true,m-1,arr),go(0,false,m,arr));
    cout << ans;
}