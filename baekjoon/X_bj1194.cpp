#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n,m;
vector<string> v;

int key[] = {0,0,0,0,0,0};

queue<pair<int,int> > q1;
queue<pair<int,int> > q2;
queue<pair<int,int> > q3;

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

int visit[51][51];
// a = 97 , A = 65

bool possible(char c){
    if(c >= 65 && c <= 70){ // 문이므로 열려있는지 확인해야한다.
        if(key[c-65] == 1){ // 문이 열렸다.

        }
    }
    else{
        return true;
    }
}

void unlock(char c){
    int num;
    num = c - 97;
    key[num] = 1;
}

int bfs(){
    int cot = 1;
    pair<int,int> now;
    int ni,nj;
    while(q3.size() > 0){
        q1 = q3;
        while(q3.size() > 0){
            q3.pop();
        }
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();
            for(int k=0;k<4;k++){
                ni = now.first + di[k];
                nj = now.second + dj[k];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m){
                    if(v[ni][nj] != '#' && visit[ni][nj] != cot){ //  벽만 아니라면 입장을 시도해볼수는 있다.
                        visit[ni][nj] = cot;
                        q2.push(make_pair(ni,nj));
                        if(v[ni][nj] >= 97 && v[ni][nj] <= 102){ // 소문자 알파벳이므로 열쇠이다.
                            unlock(v[ni][nj]);
                        }
                    }
                }
            }
        }
        // 갈수있던곳 중에 실제로 갈수있는곳 가기
        while(q2.size() > 0){
            now = q2.front();
            q2.pop();

        }
        cot++;
    }
}

int main(){
    string s;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
        for(int j=0;j<m;j++){
            visit[i][j] = 0;
            if(s[j] == '0'){
                q3.push(make_pair(i,j));
            }
        }
    }

    
    bfs();

}