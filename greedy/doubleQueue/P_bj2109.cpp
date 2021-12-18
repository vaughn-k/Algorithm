/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.18

소요시간 : 10m

문제명 - 백준 2109 - 순회강연
   
알고리즘
    - 그리디
    - 우선순위큐 2개 전달형(조건큐, 최대큐) 

문제개요
    n개의 학교에서 강연을 요청하는데 각각 기한과 페이가 주어진다.
    이때 하루에 한 학교씩만 강연을 할 수 있을 때, 받을 수 있는 최대 페이 출력

    전형적인 double priorityQueue 문제

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

struct Class{
    int date;
    int reward;
};

struct cmpDate{
    bool operator()(Class a, Class b){
        return a.date < b.date;
    }
};

struct cmpReward{
    bool operator()(Class a, Class b){
        return a.reward < b.reward;
    }
};

priority_queue<Class,vector<Class>,cmpDate> pqDate;
priority_queue<Class,vector<Class>,cmpReward> pqReward;

int main(){
    cin >> n;
    Class c;
    int tmp1,tmp2;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        c.reward = tmp1;
        c.date = tmp2;
        pqDate.push(c);
    }
    if(n == 0){
        cout << 0;
        return 0;
    }
    int tot = 0;
    int maxDate = pqDate.top().date;
    for(int day=maxDate; day > 0; day--){
        while(pqDate.size() > 0){ // 현재 가능한 강연들 추가하기
            if(pqDate.top().date == day){
                pqReward.push(pqDate.top());
                pqDate.pop();
            }
            else{
                break;
            }
        }
        // 가능한 강연들 중에 가장 높은 페이를 주는 학교 선택
        if(pqReward.size() > 0){
            tot = tot + pqReward.top().reward;
            pqReward.pop();
        }
    }
    cout << tot;
}
