#include <iostream>

using namespace std;

int t;
int n;
int target_x;
int target_y;

int reduce_distance(int now_x, int now_y){
    int dis_x = abs(now_x-target_x);
    int dis_y = abs(now_y-target_y);
    if(dis_x <= 2 && dis_y <= 2){
        if(dis_x + dis_y == 0){
            return 0;
        }
        else if(dis_x +dis_y == 1){
            return 3;
        }
        else if(dis_x +dis_y == 2){
            return 2;
        }
        else if(dis_x +dis_y == 3){
            return 1;
        }
        else{
            return 4;
        }

    }

    if(now_x <= target_x){ // go right
        if(now_y <= target_y){ // go up
            if(abs(now_x-target_x) < abs(now_y-target_y)){
                return reduce_distance(now_x+1,now_y+2) + 1;
            }
            else{
                return reduce_distance(now_x+2,now_y+1) + 1;
            }
        }
        else{ // go down
            if(abs(now_x-target_x) < abs(now_y-target_y)){
                return reduce_distance(now_x+1,now_y-2) + 1;
            }
            else{
                return reduce_distance(now_x+2,now_y-1) + 1;
            }
        }
    }
    else{ // go left
        if(now_y <= target_y){ // go up
            if(abs(now_x-target_x) < abs(now_y-target_y)){
                return reduce_distance(now_x-1,now_y+2) + 1;
            }
            else{
                return reduce_distance(now_x-2,now_y+1) + 1;
            }
        }
        else{ // go down
            if(abs(now_x-target_x) < abs(now_y-target_y)){
                return reduce_distance(now_x-1,now_y-2) + 1;
            }
            else{
                return reduce_distance(now_x-2,now_y-1) + 1;
            }
        }
    }
}

int main(){
    cin >> t;
    int now_x, now_y;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> now_x;
        cin >> now_y;
        cin >> target_x;
        cin >> target_y;
        cout << reduce_distance(now_x, now_y) << endl;
    }
}