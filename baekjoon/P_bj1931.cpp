/*
그리디 알고리즘 기초 - 회의실

*/

#include <iostream>
#include <queue>
#include <utility>


using namespace std;

int n;

struct Sub{
    int start;
    int end;
};

struct cmp{
    bool operator()(Sub a, Sub b){
        if(a.end == b.end){
            return a.start > b.start;
        }
        return a.end > b.end;
    }
};

priority_queue<Sub, vector<Sub>, cmp> pq;


int main(){
    int tmp1,tmp2;
    cin >> n;
    Sub sub;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        sub.start = tmp1;
        sub.end = tmp2;
        pq.push(sub);
    }

    int end = 0;
    int tot = 0;

    while(pq.size() > 0){
        sub = pq.top();
        // cout << "start : " << sub.start << " | end : " << sub.end << endl;
        if(end <= sub.start){
            tot++;
            end = sub.end;
        }
        pq.pop();
        
    }
    cout << tot;
}