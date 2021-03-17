/*/////////////////////////////////////////////////////////////////////////
소요시간 : 15m

문제명 - 백준 1781 - 컵라면
    + 13904번과 그냥 똑같다.
알고리즘
    - 그리디
    - 우선순위큐(2개 전달형)
    - 기한제한 + 최대스코어달성

문제개요
    n개의 문제가 있고 각 문제마다 데드라인이 있고 수행시 점수를 준다.
    이때 최대로 점수를 얻을 때 그 점수는?

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Ramen{
    int deadline;
    int score;
};

struct cmpDeadline{
    bool operator()(Ramen a, Ramen b){
        return a.deadline < b.deadline;
    }
};

struct cmpScore{
    bool operator()(Ramen a, Ramen b){
        return a.score < b.score;
    }
};

priority_queue<Ramen, vector<Ramen>, cmpDeadline> pqDead;
priority_queue<Ramen, vector<Ramen>, cmpScore> pqScore;
int n;

int main(){
    cin >> n;
    int tmp1, tmp2;
    Ramen ramen;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        ramen.deadline = tmp1;
        ramen.score = tmp2;
        pqDead.push(ramen);
    }
    int tot = 0;
    int maxDay = pqDead.top().deadline;
    for(int day = maxDay; day > 0; day--){
        while(pqDead.size() > 0){
            ramen = pqDead.top();
            if(ramen.deadline != day){
                break;
            }
            else{
                pqDead.pop();
                pqScore.push(ramen);
            }
        }
        if(pqScore.size() > 0){
            tot = tot + pqScore.top().score;
            pqScore.pop();
        }
    }
    cout << tot;
}