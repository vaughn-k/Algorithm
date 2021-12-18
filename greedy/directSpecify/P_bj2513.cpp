/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.31

소요시간 : 50m

문제명 - 백준 2513 통학버스
   
알고리즘
    - 그리디
    - 선형구조 우선순위큐 최신화

문제개요
    직선상에 학교의 위치가 주어지고 n개의 아파트 위치와 해당 아파트의 학생수가 주어진다.
    버스의 최대 탑승인원이 정해져있을때

    학교에서 모든 학생들을 태우고 학교로 올때 최소의 거리는?

    먼저 학교 기준으로 좌측아파트와 우측아파트를 나눈다.
        (좌측아파트에 방문한후 우측아파트로 바로 방문하는 일은 없다.
        왜냐하면 당연히 좌측에서 우측으로 넘어가려면 학교를 지나야하는데 그럼 결국 좌측아파트에서
        다 옮긴후 우측아파트를 순회하는것이기 때문이다)
        좌측에서 싣고 학교에서 안내린후 우측으로 가는것도 말도안되는 일이다)

    a) 각 방향에서 가장 멀리떨어져 있는 아파트에서 태울수 있는 만큼 태운다.
        b) 아직 더 탈수 있다.
            yes)    그 다음 아파트에서 태울수 있는만큼 태운다
                    b로 돌아간다
            no)     초기 아파트의 거리*2 만큼 전체 거리에 합산한다.
                    a로 돌아간다
         
    이같은 접근이 가능한 이유는 먼저 가장 멀리 떨어진 아파트는 언젠가는 방문해야한다.
    그렇다면 그곳을 방문했을때 아직 더 탈수있다면 가는길에 최대한 학교와 멀리떨어진 곳에 사는 학생
    들을 태울수 있는만큼 태우는것이 이득이다.

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,busMax,school;

struct Apart{
    int position;
    int people;
};

struct cmpLeft{
    bool operator()(Apart a, Apart b){
        return a.position > b.position;
    }
};

struct cmpRight{
    bool operator()(Apart a, Apart b){
        return a.position < b.position;
    }
};

priority_queue<Apart, vector<Apart>, cmpLeft> ql;
priority_queue<Apart, vector<Apart>, cmpRight> qr;

int main(){
    Apart apart;
    cin >> n >> busMax >> school;
    int tmp1, tmp2;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        apart.position = tmp1;
        apart.people = tmp2;
        if(tmp1 < school){
            ql.push(apart);
        }
        else if(tmp1 > school){
            qr.push(apart);
        }
    }

    int end; // 현재 종착지
    int left; // 앞으로 더 탈수있는 사람수
    int now; // 현재 탄사람
    int distance = 0;

    while(ql.size() > 0){ // 버스한번 순환
        left = busMax;
        // 남은 아파트중 가장 멀리있는 아파트부터 시작
        apart = ql.top();
        ql.pop();
        // cout << "bus start : apart : " << apart.position << endl;
        end = apart.position;
        if(apart.people > left){ // 여기로 한번이상 더와야한다
            // cout << "도착지에서 모두 탐 : " << endl;
            apart.people = apart.people - busMax;
            ql.push(apart);
        }
        else{ // 여기 아파트는 모두 끝났고 다음아파트로 이동
            left = left - apart.people;
            // cout << "도착지모두 싣고 다음실으러감 left : " << left << endl;
            while(ql.size() > 0 && left > 0){ // 학교까지 아직 남은 아파트가 있으면서, 버스에 아직 탈 자리가 있을때
                apart = ql.top();
                ql.pop();
                if(apart.people > left){ // 여기아파트에 못탄사람이 있다.
                    apart.people = apart.people - left;
                    ql.push(apart);
                    left = 0;
                    // cout << apart.position << "에서 태웠는데 아파트에 아직 " << apart.people << "만큼 남음" << endl;
                }
                else{ // 모두 탐
                    left = left - apart.people;
                    // cout << apart.position << "에서 모두 탐. 현재 left : " << left << endl;
                }
            }
        }
        distance += abs(school - end) * 2;
    }

    // cout << "left : " << distance << endl;

    while(qr.size() > 0){ // 버스한번 순환
        left = busMax;
        // 남은 아파트중 가장 멀리있는 아파트부터 시작
        apart = qr.top();
        qr.pop();
        end = apart.position;
        if(apart.people > left){ // 여기로 한번이상 더와야한다
            apart.people = apart.people - busMax;
            qr.push(apart);
        }
        else{ // 여기 아파트는 모두 끝났고 다음아파트로 이동
            left = left - apart.people;
            while(qr.size() > 0 && left > 0){ // 학교까지 아직 남은 아파트가 있으면서, 버스에 아직 탈 자리가 있을때
                apart = qr.top();
                qr.pop();
                if(apart.people > left){ // 여기아파트에 못탄사람이 있다.
                    apart.people = apart.people - left;
                    qr.push(apart);
                    left = 0;
                }
                else{ // 모두 탐
                    left = left - apart.people;
                }
            }
        }
        distance += abs(school - end) * 2;
    }
    cout << distance;
}


/*
5 5 10
1 10
5 5
9 3
12 4
13 6

5 1 10
3 2
5 1
7 1
12 2
18 2
*/