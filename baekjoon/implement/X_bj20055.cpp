#include <iostream>
#include <queue>

using namespace std;

int n,k;
int belt[201];
int zero;

queue<int> robot;
queue<int> robot_tmp;

void belt_move(){
    int tmp = belt[2*n-1];
    for(int i=(n*2-1);i>=0;i--){
        belt[i+1] = belt[i];
    }
    belt[0] = tmp;
    while(robot.size() > 0){
        tmp = robot.front() + 1;
        robot.pop();
        if(tmp != (n-1)){
            robot_tmp.push(tmp);
        }
    }
    while(robot_tmp.size() > 0){
        robot.push(robot_tmp.front());
        robot_tmp.pop();
    }
}

bool stage(){
    int now;
    int before = 100000;
    belt_move();
    while(robot.size() > 0){
        now = robot.front();
        robot.pop();
        if((now+1) < before && belt[now+1] > 0){ // 현재로봇 이동가능
            belt[now+1]--;
            if(belt[now+1] == 0){
                zero++;
                if(zero >= k){
                    return false;
                }
            }
            if((now+1) != (n-1)){ // 로봇움직인후 안내림
                robot_tmp.push(now+1);
            }
            before = now+1;
        }
        else{
            robot_tmp.push(now);
            before = now;
        }
    }
    while(robot_tmp.size() > 0){
        robot.push(robot_tmp.front());
        robot_tmp.pop();
    }
    if(belt[0] > 0){
        robot.push(0);
        belt[0]--;
        if(belt[0] == 0){
            zero++;
            if(zero >= k){
                return false;
            }
        }
    }

    return true;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<(n*2);i++){
        cin >> belt[i];
    }

    int cot = 1;
    while(stage()){
        cot++;
    }
    cout << cot;
    return 0;
}