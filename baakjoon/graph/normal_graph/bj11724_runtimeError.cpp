// 행렬을 사용하면 런타임 에러가 난다.

#include <iostream>

using namespace std;

int t,m,n,k;
int graph[1001][500001];
int left_spot[1001];
int Count = 0;

void sub_loop(int now){
    left_spot[now] = 0;
    for(int i=0;i<n;i++){
        if((graph[now][i] == 1) && (left_spot[i] == 1)){
            sub_loop(i);
        }
    }
}

void main_loop(){
    for(int i=0;i<n;i++){
        if(left_spot[i] == 1){
            Count++;
            sub_loop(i);
        }
    }
}



int main(){
    int tmp1, tmp2;
    for(int x=0;x<1000;x++){
        left_spot[x] = 1;
        for(int y=0;y<500000;y++){
            graph[x][y] = 0;
        }
    }
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp1;
        cin >> tmp2;
        graph[tmp1-1][tmp2-1] = 1;
        graph[tmp2-1][tmp1-1] = 1;
    }

    main_loop();
    cout << Count;
}