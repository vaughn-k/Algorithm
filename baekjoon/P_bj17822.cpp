/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.29

소요시간 : 1h 10m

문제명 - 백준 17822 - 원판 돌리기
   
알고리즘
    - bfs 원형탐색
    - 원형 자료구조 조작
    - 구현

문제개요
    m개의 숫자를 가지는 원판이 n개 있고 x,d,k(각각 돌릴판 번호, 방향, 돌릴칸수) 가 주어질때
    (단, x의 배수에 해당하는 모든 판을 돌려야함) 다음 조건에 따라 판을 돌렸을때 최종 남는 숫자들
    합 출력

    조건1. 돌린후 판의 위아래옆에 같은 수가 있다면 모두 0으로 변경
    조건2. 조건1에 부합하는 수가 없다면 존재하는 수들의 평균을 내고 그 평균보다 작은수는 +1,
            큰 수는 -1 한다.

    - 소수점이 나오는 계산실수 주의
    - 원형구조에서 몇번째 원인지와, 해당원에서 몇번째 원소인지 주의깊게 살펴보기

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[51][51];
int n,m,t;

int rot[51][3];
int visited[51][51];
int tot = 0;
int totCount = 0;
int findSame = false;

queue<pair<int, int> > q1;
queue<pair<int, int> > q2;

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

// void print(){
//     cout << "--------------" << endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout << map[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "--------------" << endl;
// }

void rotateFunction(int index, int direction, int cot){
    // index번째의 원을 direction 방향으로 cot번 회전
    int tmp[51];
    int now;
    if(direction == 0){
        now = m - cot;
    }
    else{
        now = cot;
    }

    for(int i=0;i<m;i++){
        tmp[i] = map[index][now];
        now++;
        if(now == m){
            now = 0;
        }
    }
    for(int i=0;i<m;i++){
        map[index][i] = tmp[i];
    }
}

void bfs(int id){
    bool sameExist = false;
    pair<int,int> now;
    int goi,goj;
    while(q2.size() > 0){
        q1 = q2;
        while(q2.size() > 0){ q2.pop(); }
        while(q1.size() > 0){
            now = q1.front();
            for(int i=0;i<4;i++){
                goi = now.first + di[i];
                goj = now.second + dj[i];
                if(goi >= 0 && goi <= n-1){
                    if(goj < 0){
                        goj = m-1;
                    }
                    else if(goj > m-1){
                        goj = 0;
                    }

                    if(visited[goi][goj] == 0 && map[goi][goj] == id){
                        if(!sameExist){ // 같은거 처음발견
                            findSame = true;
                            tot = tot - id;
                            map[now.first][now.second] = 0;
                            sameExist = true;
                            totCount--;
                        }
                        q2.push(make_pair(goi,goj));
                        visited[goi][goj] = 1;
                        map[goi][goj] = 0;
                        tot = tot - id;
                        totCount--;
                    }
                }
            }
            q1.pop();
        }
    }
}

void updateRotate(){
    // 붙어있는숫자 제거 및 평균기준 +- 작업수행
    findSame = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == 0 && map[i][j] != 0){
                q2.push(make_pair(i,j));
                visited[i][j] = 1;
                bfs(map[i][j]);
            }
        }
    }
    if(!findSame){
        float medium = (float)tot / (float)totCount;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] != 0){
                    if(map[i][j] > medium){
                        map[i][j]--;
                        tot--;
                    }
                    else if(map[i][j] < medium){
                        map[i][j]++;
                        tot++;
                    }
                }
            }
        }
    }
    // if(findSame){
    //     cout << "같은수발견" << endl;
    // }
    // else{
    //     cout << "평균으로 빼기" << endl;
    // }
}

int sumRotate(){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = ans + map[i][j];
        }
    }
    return ans;
}

int main(){
    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            tot = tot + map[i][j];
        }
    }
    totCount = n*m;
    
    for(int i=0;i<t;i++){
        cin >> rot[i][0] >> rot[i][1] >> rot[i][2];
    }
    
    for(int i=0;i<t;i++){
        for(int j=1;j<=n;j++){
            if(j%rot[i][0] == 0){
                // cout << "rotate : " << j << endl;
                rotateFunction(j-1,rot[i][1],rot[i][2]);
                // print();
            }
        }
        updateRotate();
        // print();
    }
    cout << sumRotate();
}

/*
4 6 1
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
3 1 0
*/