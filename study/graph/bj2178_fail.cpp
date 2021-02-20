#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int graph[101][101];
int N,M,V;
int answer;

queue<int> q1;
queue<int> q2;
queue<int> tmp_q;

// void erase_col_bfs(int target){
//     for(int i=0;i<N;i++){
//         graph[i][target] = 0;
//     }
// }


void bfs(int count){
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }
    int tmp;
    int size = q1.size();
    for(int i=0;i<size;i++){
        // cout << q1.front() << " "; 
        for(int j=0;j<N;j++){
            tmp = graph[q1.front()][j];
            if(tmp != 0){
                cout << q1.front() << " " << j << endl;
                if(q1.front() == N-1 && j == M-1){
                    answer = count;
                }
                q2.push(j);
                graph[q1.front()][j] = 0;
            }
        }
        q1.pop();
    }
    if(q2.size() > 0){
        bfs(count+1);
    }
}


int main(){
    cin >> N;
    cin >> M;
    string input;

    for(int i=0;i<N;i++){
        cin >> input;
        for(int j=0;j<M;j++){
            if(input[j] == '1'){
                graph[i][j] = 1;
            }
            else{
                graph[i][j] = 0;
            }
        }
    }

    cout << endl;
    q2.push(V);
    // erase_col_bfs(V);
    bfs(0);
    cout << answer;

    // queue <int> a;
    // queue <int> b;

    // a.push(1);
    // a.push(2);
    // a.push(3);
    // b = a;
    // cout << b.size();


}