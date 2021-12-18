/*
1h

백준 1202 - 보석 도둑

알고리즘
    그리디
    priority queue

문제개요

    배낭문제와 비슷하지만 기본적인 배낭문제와 다르게 k개의 가방이 주어지고 각각 담을 수 있는 최대 무게가 정해진다.
    가방 기준으로 봤을때 가방의 무게가 작은것이 더 선택의 폭이 좁기때문에
    가방 무게가
    c1 >= c2 >= c3 ... ck 라고 할때 ck부터 담는것이 greedy한 방법이라고 볼수있다.
    왜냐하면 ck에 담을 수 있는 보석은 무조건 c1 ~ c(k-1)에 담을 수 있지만 c1 에 담을 수 있는 보석을 전부
    c2 ~ ck 에 담을 수 있지는 않기떄문이다.

    또한 ck에 담을 때 무게가 ck이하인 보석들 중 가장 가치가 높은 보석을 담아야한다.
    따라서 기존 input 보석들을 무게순으로 정렬한후 특정 가방(ci)에 넣을때 ci보다 작거나 같은
    보석들을 가치 기준으로 정렬한후 가장 가치가 높은 보석을 담으면 될것이다.

    따라서 priority_queue를 사용하여 구현할수 있었다.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

struct JJ{
    int m;
    int v;
};

struct cmp_v{
    bool operator()(JJ a, JJ b){
        return a.v < b.v;
    }
};

struct cmp_m{
    bool operator()(JJ a, JJ b){
        return a.m > b.m;
    }
};

priority_queue<JJ,vector<JJ>, cmp_m >  origin_pq;
priority_queue<JJ,vector<JJ>, cmp_v >  pq;
priority_queue<int,vector<int>,greater<int> > bag;


int n,k;

int main(){
    int tm,tv,tc;
    JJ jj;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tm >> tv;
        jj.m = tm;
        jj.v = tv;
        origin_pq.push(jj);
    }
    for(int i=0;i<k;i++){
        cin >> tc;
        bag.push(tc);
    }


    // cout << "bag : " << bag.top() << endl;
    // cout << "jj m : " << origin_pq.top().m << endl;
    // cout << "jj v : " << origin_pq.top().v << endl;

    int nowBag;
    long long total = 0;
    while(bag.size() > 0){
        // 현재 가방 사이즈보다 큰값이 나올때까지 origin_pq -> pq 로 보석이동
        nowBag = bag.top();
        bag.pop();
        while(origin_pq.size() > 0){
            jj = origin_pq.top();
            if(jj.m > nowBag){
                break;
            }
            origin_pq.pop();
            pq.push(jj);
        }
        if(pq.size() > 0){
            total = total + pq.top().v;
            pq.pop();
        }
    }
    cout << total;
}