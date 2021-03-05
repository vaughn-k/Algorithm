// 8m
// 그리디 - atm 문제
// 오름차순정렬수 합산하면서 총합구하기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main(){
    int n;
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());

    int now = v[0];
    int total = v[0];
    for(int i=1;i<n;i++){
        now = now + v[i];
        total = total + now;
    }
    cout << total;
}