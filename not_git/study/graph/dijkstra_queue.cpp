#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
int k;
int v[101][101];
int d[101];

void dijkstra_queue(int start){ // start vertex 부터 최소거리 모두 구하기
    for(int now=0; now<n; now++){
        if(d[now] > (v[start][now] + d[start])){
            d[now] = v[start][now] + d[start];
        }
    }
    int minimum = 99999999;
    int mini_i = -1;
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            if(d[i] < minimum){
                minimum = d[i];
                mini_i = i;
            }
        }
    }
    if(mini_i != -1){
        dijkstra_queue(mini_i);
    }
}

void dijkstra_queue_run(int start){
    d[start] = 0;
    dijkstra_queue(start);
}

int main(){

    cin >> n;
    cin >> k;

    int x,y,r;
    for(int i=0;i<n;i++){
        d[i] = 99999999;
        for(int j=0;j<n;j++){
            v[i][j] = 99999999;
        }
    }

    for(int i=0;i<k;i++){
        cin >> x;
        cin >> y;
        cin >> r;
        v[x][y] = r;
        v[y][x] = r;
    }

    dijkstra_run(0);
    for(int i=0;i<n;i++){
        cout << d[i] << " ";
    }
}

// input
/*

7
12
0 1 7
0 4 3
0 5 10
4 1 2
1 5 6
4 6 5
4 3 11
1 2 4
1 3 10
3 6 4
2 3 2
5 3 9

*/