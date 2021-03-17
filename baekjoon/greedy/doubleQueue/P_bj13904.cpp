/*
20m

백준 13904 - 과제

알고리즘
    - 그리디
    - 우선순위큐 2개 (조건에 부합하는 구조체들 전달식)

문제개요
    n개의 과제가 있고 각각 마감기한과 점수가 있다. 하루에는 한가지 과제만 수행할수 있을때 최대로 얻을 수 있는 점수는?

    조건1. 하루에 최대 과제 1개씩 수행
    조건2. 점수 최대화

    먼저 조건1을 만족하는 상태에서 그중 최댓값을 구하는 쪽으로 설계한다고 했을때
    날짜기준으로 가장 기한이 긴 과제부터 내림차순으로 정렬 한 큐를 만들고

    해당 날짜마다 해당하는 과제들을 점수기준으로 내림차순 하는 큐에 넣는다.
    이후 그 큐의 top 점수를 계속 더해주면 최대점수를 구할수있다.

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Assignment{
    int date;
    int score;
};

int n;

struct cmpScore{
    bool operator()(Assignment a, Assignment b){
        return a.score < b.score;
    }
};

struct cmpDate{
    bool operator()(Assignment a, Assignment b){
        return a.date < b.date;
    }
};

priority_queue<Assignment, vector<Assignment>, cmpScore> ableList;
priority_queue<Assignment, vector<Assignment>, cmpDate> sortBydate;

int main(){
    Assignment asg;
    cin >> n;
    int tmp1,tmp2;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        asg.date = tmp1;
        asg.score = tmp2;
        sortBydate.push(asg);
    }
    int tot = 0;
    int maxDay = sortBydate.top().date;
    for(int day = maxDay; day > 0; day--){
        if(sortBydate.size() > 0){ // 과제를 수행할수 있는 과제들을 모두 리스트에 저장
            while(sortBydate.top().date == day){
                asg = sortBydate.top();
                sortBydate.pop();
                ableList.push(asg);
                if(sortBydate.size() == 0){
                    break;
                }
            }
        }
        if(ableList.size() > 0){
            tot = tot + ableList.top().score;
            ableList.pop();
        }
    }
    cout << tot;
}