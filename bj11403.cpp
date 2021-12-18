#include <iostream>
#include <queue>

using namespace std;

int n;
int graph[102][102]; // 입력그래프
int possible[102][102];
// 0 : 현재 불가능
// 1 : 가능
int check[102];
// -1 : 미방문
// 0 : 현재 방문중
// 1 : 방문

int tmp[101];
int tmp_trash[101];
int countTmp = 0;
int trash = 0;


void sub_loop(int now){ // 한번 끝날때 한 그래프 세트가 끝난다.

    cout << "0-------------0" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << possible[i][j] << " ";
        }
        cout << endl;
    }
    cout << now << endl;
    cout << "0-------------0" << endl;
    // now 정점에서 갈수있는곳 모두 탐색
    check[now] = 0;
    tmp[countTmp] = now;  
    countTmp++;
    for(int i=0;i<n;i++){
        if(graph[now][i] == 1){
            if(check[i] == -1){ // 갔다가 종료 하는 경우
                for(int j=0;j<countTmp;j++){
                    possible[tmp[j]][i] = 1;
                }
                sub_loop(i);
                tmp_trash[trash] = i;
                trash++;
            }
            else if(check[i] == 0){ // 순환이 발생해서 종료하는 경우
                for(int k=0;k<countTmp;k++){
                    for(int q=0;q<countTmp;q++){
                        possible[tmp[k]][tmp[q]] = 1;
                    }
                    for()
                }
            }
        }
    }
}

void reset(){
    for(int i=0;i<n;i++){
        if(tmp[i] == 0){
            tmp[i] = 1;
        }
    }
}

void m_loop(){ // 
    for(int i=0;i<n;i++){
        countTmp = 0;
        trash = 0;
        if(check[i] == -1){
            cout << i << "main " << endl;
            sub_loop(i);
            reset();
        }
    }
}

int main(){
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        check[i] = -1;
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
            possible[i][j] = 0;
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> tmp;
            if(tmp == 1){
                graph[i][j] = 1;
                possible[i][j] = 1;
            }

        }
    }

    m_loop();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << possible[i][j] << " ";
        }
        cout << endl;
    }
}