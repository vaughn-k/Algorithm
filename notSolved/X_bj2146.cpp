#include <iostream>

using namespace std;

int n;
int map[101][101];
int visited[101][101];
int vis[10003];

int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};

void print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------" << endl;
}

void reset_visited(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = -1;
        }
    }
}

void go(int i, int j, int num){
    int next_i, next_j;
    map[i][j] = num;
    for(int k=0;k<4;k++){
        next_i = i + di[k];
        next_j = j + dj[k];
        if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n){
            if(map[next_i][next_j] == 1){
                go(next_i,next_j,num);
            }
        }
    }
}

void assignNumber(){
    int num = 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(map[i][j] == 1){
                go(i,j,num);
                num++;
            }
        }
    }
}

int verify(int i, int j, int now){
    int next_i, next_j;
    int tmp;
    cout << "=-=-=-" << endl;
    for(int k=0;k<4;k++){
        next_i = i + di[k];
        next_j = j + dj[k]; 
        if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n){
            tmp = map[next_i][next_j];
            cout << "i,j : " << i << "," << j << "next : " << next_i << " , " << next_j << "  | tmp : " << tmp << "now : " << now << endl;
            if(tmp != 0 && tmp != now && tmp != now*(-1)){
                cout << "okokok" << endl;
                return tmp;
            }
        }
    }
    cout << "=-=-=-" << endl;
    return 0;
}

int expand_go(int i, int j, int num){
    int ans = 0;
    int ver;
    visited[i][j] = 1;
    int next_i, next_j;
    for(int k=0;k<4;k++){
        next_i = i + di[k];
        next_j = j + dj[k]; 
        if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n){
            if(map[next_i][next_j] == num){
                if(visited[next_i][next_j] == -1){
                    ans = expand_go(next_i,next_j,num);
                    if(ans != 0){
                        return ans;
                    }
                }
            }
            else if(map[next_i][next_j] == 0){
                visited[next_i][next_j] = 1;
                map[next_i][next_j] = -1 * num;
                print();
                ver = abs(verify(next_i,next_j,num));
                cout << ver << endl;
                if(ver > 0){
                    return ver;
                }
            }
        }
    }
    return ans;
}


int expand(){
    int ans;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(visited[i][j] == -1 && map[i][j] > 0){
                vis[map[i][j]] = vis[map[i][j]] + 1;
                ans = expand_go(i,j,map[i][j]);
                cout << "ans : " << ans << endl;
                for(int i=0;i<10;i++){
                    cout << vis[i] << " ";
                }
            
                cout << endl << "--------------" << endl;
                if(ans != 0){
                    return vis[map[i][j]] + vis[abs(ans)];
                }
            }
        }
    }
    return 0;
}

void reverse(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(map[i][j] < 0){
                map[i][j] = map[i][j] * -1;
            }
        }
    }
}



int main(){
    cin >> n;   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
            visited[i][j] = -1;
        }
    }

    for(int i=0;i<10003;i++){
        vis[i] = 0;
    }

    int ans = 0;
    assignNumber();
    while(ans == 0){
        ans = expand();
        reverse();
        reset_visited();
        print();
    }
        
    for(int i=0;i<10;i++){
        cout << vis[i] << " ";
    }
    cout << endl;
    cout << ans;
}


/*

10
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0


6
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 1 1
1 0 0 0 0 0

*/