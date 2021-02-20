#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n,k;
int v[101][101];
stack<int> s;
stack<int> answer;


void euerian_circuit(int start){
    if(k == 0){ // 오일러서킷 발견했을때
        answer = s;
        while(answer.size() > 0){
            cout << answer.top() << " ";
            answer.pop();
        }
        cout << start << endl;
    }
    else{
        for(int now = 0; now < n; now++){
            if(now != start && v[start][now] > 0){ 
                // 현재정점과 이동할 정점이 같지않으면서 해당 목적지 정점으로 남은 간선이 존재할때
                k--;
                v[start][now]--;
                v[now][start]--;
                s.push(now);
                euerian_circuit(now);
                k++;
                v[start][now]++;
                v[now][start]++;
                s.pop();
            }
        }
    }
}

int main(){
    int x,y,start;
    cin >> n; // 정점개수
    cin >> k; // 간선개수
    cin >> start; // 시작정점
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v[i][j] = 0;
        }
    }

    for(int i=0; i<k; i++){
        cin >> x;
        cin >> y;
        v[x][y] = v[x][y] + 1; 
        v[y][x] = v[y][x] + 1; 
    }


    euerian_circuit(start);
}

/*
input 

5
7
1
0 1
0 2
1 2
1 3
2 3
1 4
2 4


*/
