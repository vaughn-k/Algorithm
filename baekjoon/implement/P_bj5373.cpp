/*/////////////////////////////////////////////////////////////////////////

소요시간 : 1h 40m

문제명 - 백준 5373 - 큐빙

알고리즘
    - queue?

문제개요
    3x3x3 루비큐브(모두 맞춰진 상태)가 있고 6면중 돌릴방향이 순서대로 주어질때 해당 방향대로
    돌렸을때 최종으로 윗면의 색 9개 출력

    + 큐브 돌리는 방향이 총 6개이지만 결국 예를들어 윗면을 시계방향으로 한번 돌린다면
    그것은 결국 윗면을 시계반시계로 3번 돌리는것으로 풀수도 있다.
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <string>

using namespace std;

char cube[6][3][3];

char color[] = {'w','y','r','o','g','b'};

queue<char> q;

int circlei[] = {0,0,0,1,2,2,2,1};
int circlej[] = {0,1,2,2,2,1,0,0};

int sp[][12]={{3,3,3,5,5,5,2,2,2,4,4,4},
                {2,2,2,5,5,5,3,3,3,4,4,4},
                {4,4,4,0,0,0,5,5,5,1,1,1},
                {1,1,1,5,5,5,0,0,0,4,4,4},
                {3,3,3,0,0,0,2,2,2,1,1,1},
                {1,1,1,2,2,2,0,0,0,3,3,3}};

int edgei[][12] = {{2,2,2,0,1,2,0,0,0,2,1,0},
{2,2,2,2,1,0,0,0,0,0,1,2}, 
{2,2,2,2,2,2,2,2,2,0,0,0},
{2,2,2,0,0,0,0,0,0,0,0,0},
{0,1,2,0,1,2,0,1,2,0,1,2},
{2,1,0,2,1,0,2,1,0,2,1,0}};

int edgej[][12] = {{0,1,2,0,0,0,2,1,0,2,2,2},
{0,1,2,2,2,2,2,1,0,0,0,0},
{0,1,2,0,1,2,0,1,2,2,1,0},
{0,1,2,2,1,0,2,1,0,2,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{2,2,2,2,2,2,2,2,2,2,2,2}};

void print(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << cube[0][i][j];
        }
        cout << '\n';
    }
}

void rotateSpace(int space, int rotate){ // 평면 회전
    // cout << "space : " << space << " | rotate : " << rotate << endl;
    int select_space;
    int select_i;
    int select_j;
    char nowColor;
    int mid;
    
    // 평면 회전
    for(int i=0;i<8;i++){
        select_i = circlei[i];
        select_j = circlej[i];
        q.push(cube[space][select_i][select_j]);
    }

    if(rotate == 1){ // 시계방향
        mid = 2;
    }
    else{
        mid = 6;
    }
    for(int i=mid;i<8;i++){ // 시계
        select_i = circlei[i];
        select_j = circlej[i];
        cube[space][select_i][select_j] = q.front();
        q.pop();
    }
    for(int i=0;i<mid;i++){ // 시계
        select_i = circlei[i];
        select_j = circlej[i];
        cube[space][select_i][select_j] = q.front();
        q.pop();
    }

    

    // 모서리 회전
    for(int i=0;i<12;i++){
        select_space = sp[space][i];
        select_i = edgei[space][i];
        select_j = edgej[space][i];
        nowColor = cube[select_space][select_i][select_j];
        // cout << nowColor << " ";
        q.push(nowColor);
    }
    // cout << endl;

    if(rotate == 1){ // 시계방향
        mid = 3;
    }
    else{
        mid = 9;
    }

    for(int i=mid;i<12;i++){
        select_space = sp[space][i];
        select_i = edgei[space][i];
        select_j = edgej[space][i];
        // cout << "s i j " << select_space << " " << select_i << " " << select_j << " = " << q.front() << endl;
        cube[select_space][select_i][select_j] = q.front();
        q.pop();
    }
    for(int i=0;i<mid;i++){
        select_space = sp[space][i];
        select_i = edgei[space][i];
        select_j = edgej[space][i];
        // cout << "s i j " << select_space << " " << select_i << " " << select_j << " = " << q.front() << endl;
        cube[select_space][select_i][select_j] = q.front();
        q.pop();
    }
    
}


void reset(){
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cube[i][j][k] = color[i];
            }
        }
    }
}


int main(){

    int t,n;
    string s;
    cin >> t;
    int spaceNumber,rotation;
    for(int i=0;i<t;i++){
        reset();
        cin >> n;
        // cout << "-------------" << endl;
        for(int j=0;j<n;j++){
            cin >> s;
            if(s[0] == 'U'){ spaceNumber = 0;}
            else if(s[0] == 'D'){ spaceNumber = 1;}
            else if(s[0] == 'F'){ spaceNumber = 2;}
            else if(s[0] == 'B'){ spaceNumber = 3;}
            else if(s[0] == 'L'){ spaceNumber = 4;}
            else{spaceNumber = 5;}

            if(s[1] == '+'){
                rotation = 1;
            }
            else{
                rotation = 0;
            }
            rotateSpace(spaceNumber,rotation);
        }
        print();
    }
}