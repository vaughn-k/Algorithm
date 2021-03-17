/*
2h+ 미해결

분명 로직은 맞는거같은데 자꾸 메모리초과가 뜬다..;;


*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n,m;
char v[1001][1001];
int cpn[1000001]; // component
int cpnId[1001][1001]; // component
// -1 : 미방문
// -2 : 현재 방문중
// 양수 : 인접칸 개수
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

queue<pair<int,int> > qp1;

queue<int> q1;
queue<int> q2;

// void print(){
//     cout << "----------------" << endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout << cpn[i][j] << '\t';
//         }
//         cout << endl;
//     }
//     cout << "----------------" << endl;
// }
// void print2(){
//     cout << "----------------" << endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout << cpnId[i][j] << '\t';
//         }
//         cout << endl;
//     }
//     cout << "----------------" << endl;
// }

int subLoop(int si, int sj, int id){
    // cout << "loop "<< endl;
    pair<int,int> tmp;
    int gi,gj;
    int tot = 1;
    cpnId[si][sj] = id;
    qp1.push(make_pair(si,sj));     
    while(qp1.size() > 0){
        tmp = qp1.front();
        qp1.pop();
        for(int k=0;k<4;k++){
            gi = tmp.first + di[k];
            gj = tmp.second + dj[k];
            if(gi >= 0 && gi < n && gj >= 0 && gj < m){
                if(v[gi][gj] == '0' && cpnId[gi][gj] == -1){
                    tot++;
                    cpnId[gi][gj] = id;
                    // cout << " ||| " << gi << "|" << gj << endl;
                    qp1.push(make_pair(gi,gj));
                }
            }
        }
    }
    // cout << "end loop " << endl;
    return tot;
}

void mainLoop(){
    int cnt;
    int id = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cpnId[i][j] == -1 && v[i][j] == '0'){ // 아직 미방문시
                // cout << i << "|" << j << endl;
                cnt = subLoop(i,j,id);
                cpn[id] = cnt;
                id++;
            }
        }
    }
}

int ansLoop(int si, int sj){
    int gi,gj;
    int tot = 1;
    int tt;
    bool same = false;
    for(int k=0;k<4;k++){
        gi = si + di[k];
        gj = sj + dj[k];
        if(gi >= 0 && gi < n && gj >= 0 && gj < m){
            if(cpnId[gi][gj] != -1){
                if(q2.size() == 0){
                    tot = tot + cpn[cpnId[gi][gj]];
                    q2.push(cpnId[gi][gj]);
                }
                else{
                    same = false;
                    while(q2.size() > 0){
                        tt = q2.front();
                        q2.pop();
                        q1.push(tt);
                        if(tt == cpnId[gi][gj]){
                            same = true;
                        }
                    }
                    q2 = q1;
                    if(!same){
                        while(q1.size() > 0){
                            q1.pop();
                        }
                        q2.push(cpnId[gi][gj]);
                        tot = tot + cpn[cpnId[gi][gj]];
                    }
                }
            }
        }
    }
    while(q2.size() > 0){
        q2.pop();
    }
    return tot;
}

void mainAnsLoop(){
    int as;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '1'){ // 아직 미방문시
                as = ansLoop(i,j)%10;
                cout << as;
            }
            else{
                cout << 0;
            }
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string s;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cpnId[i][j] = -1;
        }
    }

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            v[i][j] = s[j];
        }
    }

    mainLoop();
    // print();
    // print2();
    mainAnsLoop();
}

/*

5 5
00000
00000
00000
00000
00000


10 10
1100100000
0011100000
0101000000
1010100000
1010100000
0000101010
0000100010
0000100010
0001010100
0001010100

*/