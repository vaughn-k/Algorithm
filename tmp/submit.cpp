// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> A;
int n;
long long minimum[100001];
long long Count[100001];
// i부터 최소점

pair<int, int> dp(int now, vector<int> &A){
    if(now == n-2){
        minimum[now] = A[now] + A[now+1];
        Count[now] = 2;
        return make_pair(A[now] + A[now+1],2);
    }
    pair<int,int> tmp;
    tmp = dp(now + 1, A);
    // 가장작은 시작점
    
    if((A[now] + A[now+1]) * (tmp.second+1) < (tmp.first+A[now] * 2)){ // 그냥 2개만 고를경우
        minimum[now] = A[now] + A[now+1];
        Count[now] = 2;
        return make_pair(A[now] + A[now+1],2);
    }
    else{
        minimum[now] = tmp.first + A[now];
        Count[now] = tmp.second+1;
        return make_pair(tmp.first + A[now],tmp.second+1);
    }
}

int solution(vector<int> &A) {
    n = A.size();

    dp(0, A);
    long long mini_total = minimum[0];
    int mini_count = Count[0];

    int ans = 0;
    for(int i=1;i<n-1;i++){
        if(minimum[i] * mini_count < mini_total * Count[i]){
            mini_total = minimum[i];
            mini_count = Count[i];
            ans = i;
        }
    }
    return ans;
}