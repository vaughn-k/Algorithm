/*
1h 10m

graph, brute-force

문제자체는 어렵지 않았는데 일반적인 탐색을 (n*m)*(n*m-1)*(n*m-1) 만큼 수행해야했기에 

이렇게 풀어도 시간초과가 나지 않나 고민했었다. 

대신 n x m 행렬의 최대가 각각 3 <= n,m <= 8로 작아서 그리 오래걸리지 않았다.

*/


#include <iostream>
#include <utility>

using namespace std;

int n,m;
int room[9][9];
int save_room[9][9];
int wall;
int save_wall;
int virus;
int save_virus;

void reset_env(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            room[i][j] = save_room[i][j];
        }
    }
    wall = save_wall;
    virus = save_virus;
}

int remake_map(int x1, int x2, int x3, int y1, int y2, int y3){
    if(room[x1][y1] == 0 && room[x2][y2] == 0 && room[x3][y3] == 0){
        room[x1][y1] = 1;
        room[x2][y2] = 1;
        room[x3][y3] = 1;
        return 1;
    }
    else{
        return 0;
    }
}


void sub_loop(int x, int y){
    if(x >= 0 && x <= n-1 && y >= 0 && y <= m-1){
        if(room[x][y] == 0){
            room[x][y] = 2;
            virus++;
            sub_loop(x+1,y);
            sub_loop(x-1,y);
            sub_loop(x,y+1);
            sub_loop(x,y-1);
        }
    }
}

pair<int,int> moduler(int num){
    int i=0;
    while(num >= m){
        i++;
        num = num - m;
    }
    pair<int, int> pa = make_pair(i,num);
    
    return pa;
}

int search(){
    pair<int, int> tmp_pa;
    int x1,y1,x2,y2,x3,y3;
    int maximum = 0;
    for(int i=0;i<n*m-2;i++){
        for(int j=i+1;j<n*m-1;j++){
            for(int k=j+1;k<n*m;k++){
                tmp_pa = moduler(i);
                x1 = tmp_pa.first;
                y1 = tmp_pa.second;
                tmp_pa = moduler(j);
                x2 = tmp_pa.first;
                y2 = tmp_pa.second;
                tmp_pa = moduler(k);
                x3 = tmp_pa.first;
                y3 = tmp_pa.second;

                if(remake_map(x1,x2,x3,y1,y2,y3) == 1){
                    wall = wall + 3;
                    for(int sub_i=0;sub_i<n;sub_i++){
                        for(int sub_j=0;sub_j<m;sub_j++){
                            if(room[sub_i][sub_j] == 2){
                                sub_loop(sub_i+1, sub_j);
                                sub_loop(sub_i-1, sub_j);
                                sub_loop(sub_i, sub_j+1);
                                sub_loop(sub_i, sub_j-1);
                            }
                        }
                    }

                    if(maximum < (n*m - wall - virus)){
                        maximum = n*m - wall - virus;
                    }
                    reset_env();
                }
            }
        }
    }
    return maximum;
}

int main(){
    cin >> n;
    cin >> m;
    int tmp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tmp;
            room[i][j] = tmp;
            save_room[i][j] = tmp;
            if(tmp == 1){
                wall++;
            }
            if(tmp == 2){
                virus++;
            }
        }
    }
    save_wall = wall;
    save_virus = virus;

    cout << search();

}