/*
50m

백준 2437 - 저울

알고리즘
    그리디
    오름차순 정렬 후, sum(i)와 a[i+1] 값 비교를 통한 답 도출

문제개요

    n개의 추들이 주어지고 이 추들을 이용해 만들수 없는 가장 최소의 수를 구하는 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main(){
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    if(v[0] >= 2){
        cout << 1;
        return 0;
    }

    int sum;
    sum = v[0];
    for(int i=1;i<n;i++){
        if(v[i] > sum+1){
            sum = sum + 1;
            cout << sum;
            return 0;
        }
        sum = sum + v[i];
    }
    sum = sum + 1;
    cout << sum;
    return 0;

}