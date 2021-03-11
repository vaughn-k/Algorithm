/*
10m

백준 2217 - 로프

알고리즘 - 그리디

문제개요 - 로프의 길이들이 주어지고 버틸수 있는 최대 중량 구하기

정렬후 n번시행하면서 최댓값 찾기

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> lope;

int main(){
    int tmp;
    int tot;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        lope.push_back(tmp);
    }
    sort(lope.begin(),lope.end());
    // sort(lope.begin(),lope.end(),greater<int>());
    int maxi = -1;
    for(int i=0;i<n;i++){
        tot = lope[i] * (n-i);
        if(maxi < tot){
            maxi = tot;
        }
    }
    cout << maxi;
}