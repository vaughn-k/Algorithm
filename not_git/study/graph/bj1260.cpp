/*for문에서 조건이 내부 루프내에서 바뀌지 않는지 주의하기
ex) 
for(i=0;i<q.size();i++){
    q.pop();
}
의 경우 for문을 돌때마다 q.pop()에 의해 q 사이즈가 줄어들어 본래의 for문의 의도로 돌아가지않게된다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph_for_dfs[1001][1001];
int graph_for_bfs[1001][1001];
int N,M,V;

queue<int> q1;
queue<int> q2;
queue<int> tmp_q;

// void print(){
//     cout << "=============" << endl;
//     for(int i=1;i<N+1;i++){
//         for(int j=1;j<N+1;j++){
//             cout << graph_for_dfs[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "=============" << endl;
// }

void erase_col_dfs(int target){
    for(int i=1;i<N+1;i++){
        graph_for_dfs[i][target] = 0;
    }
}

void erase_col_bfs(int target){
    for(int i=1;i<N+1;i++){
        graph_for_bfs[i][target] = 0;
    }
}

void dfs(int start){
    cout << start << " ";
    for(int i=1;i<N+1;i++){
        if(graph_for_dfs[start][i] == 1){
            erase_col_dfs(i);
            dfs(i);
        }
    }
}

void bfs(){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    int tmp;
    int size = q1.size();
    for(int i=0;i<size;i++){
        cout << q1.front() << " "; 
        for(int j=1;j<N+1;j++){
            tmp = graph_for_bfs[q1.front()][j];
            if(tmp != 0){
                q2.push(j);
                erase_col_bfs(j);
            }
        }
        q1.pop();
    }
    if(q2.size() > 0){
        bfs();
    }
}



int main(){
    cin >> N;
    cin >> M;
    cin >> V;
    int x,y;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            graph_for_dfs[i][j] = 0;
            graph_for_bfs[i][j] = 0;
        }
    }

    for(int i=0;i<M;i++){
        cin >> x;
        cin >> y;
        graph_for_dfs[x][y] = 1;
        graph_for_bfs[x][y] = 1;
        graph_for_dfs[y][x] = 1;
        graph_for_bfs[y][x] = 1;
    }

    erase_col_dfs(V);
    dfs(V);
    cout << endl;
    q2.push(V);
    erase_col_bfs(V);
    bfs();

    // queue <int> a;
    // queue <int> b;

    // a.push(1);
    // a.push(2);
    // a.push(3);
    // b = a;
    // cout << b.size();


}