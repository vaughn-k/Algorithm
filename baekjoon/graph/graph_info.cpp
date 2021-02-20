#include <iostream>
#include <vector>

using namespace std;

int main(){
    int graph[4][4];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][0] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
}

// int main(){
//     vector<vector<int>> v;

//     for(int i=0;i<4;i++){
//         v.push_back(vector<int>());
//     }
//     v[0].push_back(1);
//     v[0].push_back(2);

//     v[1].push_back(0);
//     v[1].push_back(2);
//     v[1].push_back(3);

//     v[2].push_back(0);
//     v[2].push_back(1);
//     v[2].push_back(3);

//     v[3].push_back(1);
//     v[3].push_back(2);
// }
