#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n,m;
int map[51][51];

int visited[51][51];

queue<pair<int, int> > q1;
queue<pair<int, int> > q2;

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

void resetVisited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
}

int makeWater(int height){
    int tot = 0;
    bool posible = true;
    pair<int,int> now;
    int ni,nj;
    // q2에 있는지 지점부터 높이가 height인 수영장 만들때 가능하면 그 너비를, 불가능하면 -1을 출력
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){
            q2.pop();
        }
        while(q1.size() > 0){
            now = q1.front();
            tot += height - map[now.first][now.second] + 1;
            q1.pop();
            for(int k=0;k<4;k++){
                ni = now.first + di[k];
                nj = now.second + dj[k];
                if(ni < 0 || nj < 0 || ni > n-1 || nj > m-1){
                    posible = false;
                }
                else{
                    if(map[ni][nj] <= height && visited[ni][nj] == 0){
                        visited[ni][nj] = 1;
                        q2.push(make_pair(ni,nj));
                    }
                }
            }
        }
    }
    if(posible){
        return tot;
    }
    else{
        return 0;
    }
}

int main(){
    int maxi = 0;
    string tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        for(int j=0;j<m;j++){
            map[i][j] = tmp[j] - 48;
            if(map[i][j] > maxi){
                maxi = map[i][j];
            }
        }
    }   
    int ret;
    int maximumCount = 0;
    int subsum;
    for(int height = maxi-1; height>0; height--){
        resetVisited();
        subsum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] <= height && visited[i][j] == 0){
                    visited[i][j] = 1;
                    q2.push(make_pair(i,j));
                    ret = makeWater(height);
                    subsum += ret;
                }
            }
        }
        if(subsum > maximumCount){
            maximumCount = subsum;
        }
    }
    cout << maximumCount;
}


/*

6 65 5 
55515 
53121 
54445 
51115 
55555 

출처: https://txegg.tistory.com/117 [MuviSsum]
888888
818888
888888
811234
811128
888888

6 6
111111
159421
181119
191219
191119
199999

4 4
5555
5235
5145
5515

4 4
9999
9999
9928
9999

*/