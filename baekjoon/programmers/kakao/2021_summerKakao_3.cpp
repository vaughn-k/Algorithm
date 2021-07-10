3

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int p[1000002];
int b[1000002];
int live[1000002];

struct Dump{
    int origin;
    int pIndex;
    int pValue;
    int bIndex;
    int bValue;
};

stack<Dump> history;

void undo(){
    Dump dump;
    dump = history.top();
    history.pop();
    live[dump.origin] = 1;
    p[dump.pIndex] = dump.pValue;
    b[dump.bIndex] = dump.bValue;
}

void del(int index){
    // 저장
    Dump dump;
    dump.origin = index;
    dump.pIndex = b[index];
    dump.pValue = p[b[index]];
    dump.bIndex = p[index];
    dump.bValue = b[p[index]];
    history.push(dump);
    
    // 삭제
    p[b[index]] = p[index];
    b[p[index]] = b[index];
    live[index] = 0;
}

string solution(int n, int k, vector<string> cmd) {

    string answer = "";
    string tmp;
    int move;
    // int to = 0,bo = n-1; -> 사용하려다안함
    int tt; // 임시점
    int select = k;
    for(int i=0;i<n;i++){
        live[i] = 1;
        p[i] = i+1;
        b[i] = i-1;
    }
    p[n-1] = -1;
    b[0] = -1;
    int si = cmd.size();
    for(int i=0;i<si;i++){
        // cout << "now select : " << select << endl;
        if(cmd[i][0] == 'U' || cmd[i][0] == 'D'){
            tmp = "";
            for(int k=2;k<cmd[i].size();k++){
               tmp = tmp + cmd[i][k]; 
            }
            move = stoi(tmp);
            cout << move << endl;
            if(cmd[i][0] == 'U'){
                for(int j=0;j<move;j++){ // U
                    select = b[select];
                }
            }
            else{
                for(int j=0;j<move;j++){ // D
                    select = p[select];
                }
            }
        }
        else if(cmd[i][0] == 'C'){ // 삭제시 뒷칸으로 현재 선택점이 움직이므로 마지막 점일때를 유의한다.
            if(p[select] == -1){ // 선택점이 마지막 점이라면 그 이전점을 선택해야한다.
                tt = b[select];
            }
            else{
                tt = p[select];                
            }
            // if(select == to){
            //     to = tt;
            // }
            // else if(select == bo){
            //     bo = tt;
            // }
            del(select);
            select = tt;

        }
        else{ // Z
            undo();
        }
    }
    
    for(int i=0;i<n;i++){
        if(live[i] == 1){
            answer.append(1,'O');
        }
        else{
            answer.append(1,'X');
            // answer = answer + 'X';
        }
    }

    // char 에서 덧셈연산을 수행하면 char를 int로 변환후에 연산 한 뒤 다시 char로 변환한다?
    
    return answer;
}