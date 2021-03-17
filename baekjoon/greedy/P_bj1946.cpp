/*
30m

백준 1946 - 신입 사원

알고리즘 
    - 그리디
    - pair 사용, first 기준으로 정렬 후, second 값보다 큰지 작은지 판단. (작다면 기준값 갱신)

문제개요
    n명의 신입사원이 있고 각각 2개의 점수를 가지고있다.
    자신의 두 점수가 어떤 한 사원의 두 점수보다 모두 낮다면 뽑히지 않을때 채용가능한 사람 수
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

vector<pair<int,int> > v;

int t,n;

bool compair(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int tmp1,tmp2;
    int line;
    int tot;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        v.clear();
        tot = 1;
        for(int j=0;j<n;j++){
            cin >> tmp1 >> tmp2;
            v.push_back(make_pair(tmp1,tmp2));
        }
        sort(v.begin(), v.end(), compair);
        line = v[0].second;
        for(int j=1;j<n;j++){
            if(v[j].second < line){
                line = v[j].second;
                tot++;
            }
        }
        cout << tot << '\n';
    }
}