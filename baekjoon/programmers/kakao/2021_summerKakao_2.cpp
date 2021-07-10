// 2 - 3칸이상 떨어져야함(2칸까지 감염)

/*
좀더 효율적인 방안 - n사이즈가 커지고, 거리가 늘어났을 때

예를 들어 nxn 사이즈에 k만큼의 거리를 두어야 한다면

P가 있는 임의의 점 p1(x,y)라고 할 때, 해당 점에서  -> 이건 안될듯

*/

// 27m

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

queue<pair<int,int> > q1;
queue<pair<int,int> > q2;

char room[5][5];

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

bool bfs(int ni, int nj){ // true : 거리두기 잘함
    while(q1.size() > 0 ){
        q1.pop();
    }
    while(q2.size() > 0){
        q2.pop();
    }
    
    // cout << "start -- bfs" << endl;
    int si,sj;
    si = ni;
    sj = nj;
    q2.push(make_pair(ni,nj));
    int nexti,nextj;
    for(int i=0;i<2;i++){
        if(q2.size() > 0){
            q1 = q2;
            while(q2.size() > 0){ q2.pop(); }
            while(q1.size() > 0){
                for(int k=0;k<4;k++){
                    nexti = q1.front().first + di[k];
                    nextj = q1.front().second + dj[k];
                    // cout << "next : " << nexti << "," << nextj << endl;
                    if(nexti >= 0 && nextj >= 0 && nexti < 5 && nextj < 5 && !(nexti == si && nextj == sj)){
                        // cout << "now state : " << room[nexti][nextj] << endl;
                        if(room[nexti][nextj] == 'P'){ // 다음점이 사람
                            return false;
                        }
                        else if(room[nexti][nextj] == 'O'){ // 다음점이 책상
                            q2.push(make_pair(nexti,nextj));
                        }
                        // else 벽일때는 거리를 고려할 필요가 없다.
                    }
                }
                q1.pop();
            }
        }
    }
    
    
    return true;
}

bool check(int index, vector<vector<string> > places){ // true : 거리두기 잘함
    // cout << "room : " << index << endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            room[i][j] = places[index][i][j];
        }
    }
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(room[i][j] == 'P'){
                if(!bfs(i,j)){
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    
    for(int i=0;i<places.size();i++){
        if(check(i,places)){
            cout << "1";
            answer.push_back(1);
        }
        else{
            cout << "0";
            answer.push_back(0);
        }
    }
    
    
    
    return answer;
}

int main(){
    vector<vector<string> > sub;
    for(int i=0;i<3;i++){
        sub.push_back(vector<string>());
    }
    sub[0].push_back("POOOP");
    sub[0].push_back("OOOOO");
    sub[0].push_back("OOOOO");
    sub[0].push_back("POOOP");
    sub[0].push_back("OOOOO");

    sub[1].push_back("POOPO");
    sub[1].push_back("OOOOO");
    sub[1].push_back("OOOOO");
    sub[1].push_back("POOOP");
    sub[1].push_back("OOOOO");

    sub[2].push_back("PXPOO");
    sub[2].push_back("OOOOO");
    sub[2].push_back("OOOOO");
    sub[2].push_back("POOOP");
    sub[2].push_back("OOOOO");

    solution(sub);
}

/*
POOOP
OOOOO
OOOOO
POOOP
OOOOO

*/