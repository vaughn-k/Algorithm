// 47m 시도중

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int sub[101][101];
int countChild[101];
int countParent[101];
queue<int> q;
int n,m;
vector<vector<int> > toP;
vector<vector<int> > toC;

void find_root(){
    for(int i=1;i<=n;i++){
        if(toP[i].size() == 0){
            q.push(i);
        }
    }
}

int dfs(int now){
    if(countChild[now] != -1){
        return countChild[now];
    }
    int total = 0;
    for(int i=0;i<toC[now].size();i++){
        total = total + dfs(toC[now][i]) + 1;
    }
    countChild[now] = total;
    return total;
}

void makeInformation(){
    int now;
    while(q.size() > 0){
        now = q.front();
        q.pop();
        dfs(now);
    }
}

int go_parent(int k){
    if(countParent[k] != -1){
        return countParent[k];
    }
    int total = 0;
    for(int i=0;i<toP[k].size();i++){
        total = total + go_parent(toP[k][i]) + 1;
    }
    countParent[k] = total;
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int tmp1,tmp2;
    cin >> n >> m;
    
    for(int i=0;i<=n;i++){
        toP.push_back(vector<int>());
        toC.push_back(vector<int>());
        countParent[i] = -1;
        countChild[i] = -1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sub[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++){
        cin >> tmp1 >> tmp2;
        sub[tmp1][tmp2] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(sub[i][j] == 1){
                toP[i].push_back(j);
                toC[j].push_back(i);
            }
        }
    }

    find_root();
    makeInformation();
    int answer;
    for(int i=1;i<=n;i++){
        go_parent(i);    
    }
    for(int i=1;i<=n;i++){
        
        answer = n - countChild[i] - countParent[i] - 1;
        // cout << answer << '\n';
        cout << i << "번째 | " << countChild[i] << "개의 자식 보유 | " << countParent[i] << " 개의 부모보유 : " << answer << endl;
    }

    // answer = 전체물건수 - countChild[] - countRoot[] - 1(본인)

}

/*

6
6
1 2
2 3
3 4
5 4
6 5
2 5


8
9
2 1
4 2
5 2
3 1
6 1
6 3
7 3
8 3
8 7

*/