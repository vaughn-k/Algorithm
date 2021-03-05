#include <iostream>
#include <queue>

using namespace std;

int m,n,h;
int8_t box[101][101][101];

int day = 0;
int remain = 0;

struct Location{
    int loc_h;
    int loc_n;
    int loc_m;
};

queue<Location> q1;
queue<Location> q2;

int tomato_bfs(){
    day++;
    q1 = q2;
    while(q2.size() > 0){
        q2.pop();
    }

    int c;
    Location tmp;
    Location newtmp;
    c = q1.size();
    for(int i=0; i<c; i++){
        tmp = q1.front();
        q1.pop();
        if(tmp.loc_h > 0){
            if(box[tmp.loc_h-1][tmp.loc_n][tmp.loc_m] == 0){
                box[tmp.loc_h-1][tmp.loc_n][tmp.loc_m] = 1;
                Location newtmp;
                newtmp.loc_h = tmp.loc_h-1;
                newtmp.loc_n = tmp.loc_n;
                newtmp.loc_m = tmp.loc_m;
                q2.push(newtmp);
                remain--;
            }
        }
        if(tmp.loc_h < (h-1)){
            if(box[tmp.loc_h+1][tmp.loc_n][tmp.loc_m] == 0){
                box[tmp.loc_h+1][tmp.loc_n][tmp.loc_m] = 1;
                newtmp.loc_h = tmp.loc_h+1;
                newtmp.loc_n = tmp.loc_n;
                newtmp.loc_m = tmp.loc_m;
                q2.push(newtmp);
                remain--;
            }
        }
        if(tmp.loc_n > 0){
            if(box[tmp.loc_h][tmp.loc_n-1][tmp.loc_m] == 0){
                box[tmp.loc_h][tmp.loc_n-1][tmp.loc_m] = 1;
                newtmp.loc_h = tmp.loc_h;
                newtmp.loc_n = tmp.loc_n-1;
                newtmp.loc_m = tmp.loc_m;
                q2.push(newtmp);
                remain--;
            }
        }
        if(tmp.loc_n < (n-1)){
            if(box[tmp.loc_h][tmp.loc_n+1][tmp.loc_m] == 0){
                box[tmp.loc_h][tmp.loc_n+1][tmp.loc_m] = 1;
                newtmp.loc_h = tmp.loc_h;
                newtmp.loc_n = tmp.loc_n+1;
                newtmp.loc_m = tmp.loc_m;
                q2.push(newtmp);
                remain--;
            }
        }
        if(tmp.loc_m > 0){
            if(box[tmp.loc_h][tmp.loc_n][tmp.loc_m-1] == 0){
                box[tmp.loc_h][tmp.loc_n][tmp.loc_m-1] = 1;
                newtmp.loc_h = tmp.loc_h;
                newtmp.loc_n = tmp.loc_n;
                newtmp.loc_m = tmp.loc_m-1;
                q2.push(newtmp);
                remain--;
            }
        }
        if(tmp.loc_m < (m-1)){
            if(box[tmp.loc_h][tmp.loc_n][tmp.loc_m+1] == 0){
                box[tmp.loc_h][tmp.loc_n][tmp.loc_m+1] = 1;
                newtmp.loc_h = tmp.loc_h;
                newtmp.loc_n = tmp.loc_n;
                newtmp.loc_m = tmp.loc_m+1;
                q2.push(newtmp);
                remain--;
            }
        }
    }
    if(q2.size() > 0){
        tomato_bfs();
    }
}

int main(){
    cin >> m;
    cin >> n;
    cin >> h;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    Location tmp;
                    tmp.loc_h = i; 
                    tmp.loc_n = j;
                    tmp.loc_m = k;
                    q2.push(tmp);
                }
                else if(box[i][j][k] == 0){
                    remain++;
                }
            }
        }
    }
    tomato_bfs();


    if(remain > 0){
        cout << -1;
    }
    else{
        cout << (day-1);
    }
}