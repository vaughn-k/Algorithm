/*/////////////////////////////////////////////////////////////////////////
소요시간 : 15m

문제명 - 백준 13702 - 이상한 술집

알고리즘
    - 이분 탐색

문제개요
    막걸리 n잔(들어있는 용량이 모두 다르다) 을 k명에게 같은 양씩 따라줄때 최대 몇ml씩 따라줄수
    있는지 출력

    막걸리의 양은 0~2^31 이기에 모든 경우의수를 조사할수 없다. 또한 막걸리를 
    p만큼 주었을 때 만약 k명이상에게 분배가 가능하면 p이상의 값에 도전해볼수 있지만 
    p만큼 주었을 때 k명이상에게 줄수 없었다면 p미만으로 변경해야한다.

    즉 이분탐색으로 실행시간을 log수준으로 낮출수 있다. 
    
*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;

int n,k;

int divi(int start, int end){
    if(start == end){
        return start;
    }

    int mid;
    if(end - start == 1){
        mid = end;
    }
    else{
        mid = (start+end) / 2;
    }

    int tot = 0;
    for(int i=0;i<n;i++){
        if(v[i]/mid > 0){
            tot += v[i]/mid;
        }
        else{
            break;
        }
        if(tot >= k){
            break;
        }
    }
    
    if(tot >= k){
        return divi(mid, end);
    }
    else{
        return divi(start,mid-1);
    }
}

int main(){
    int tmp;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),greater<int>());
    cout << divi(0,v[0]);
}

