/*
H++

백준 2568 - 전깃줄 2 

알고리즘 : LIS(+tracking) + 우선순위큐

문제개요 : 두 전봇대 사이에 a - b 구조로 n개의 연결이 있고 그 연결이 겹치지 않게 선을 자를때

최소로 짤랐을때 자른 개수와 자른 전봇대번호 출력


기본적으로 LIS알고리즘 (lower bound)와 tracking을 사용하여 LIS 를 구하고

기존 수열에서 LIS를 제외한 전깃줄들 번호를 출력하는데 오름차순으로 출력해야하기에 우선순위큐를 사용하여 출력
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
int p[500002];

int track[500002];
stack<int> s;
vector<int> v;
vector<int> arr;

void lower_bound(int input){
    int k = arr[input];
    int start,end,mid;
    if(v[v.size()-1] < k){
        v.push_back(k);
        track[input] = v.size()-1;
        return;
    }
    if(v.size() == 1){
        if(v[0] < k){
            v.push_back(k);
            track[input] = 1;
        }
        else{
            v[0] = k;
            track[input] = 0;
        }
        return;
    }
    start = 0;
    end = v.size() - 1;
    while(end-start > 1){
        mid = (start+end)/2;
        if(v[mid] < k){
            start = mid;
        }
        else if(v[mid] > k){
            end = mid;
        }
        else{
            track[input] = mid;
            return;
        }
    }
    if(v[end-1] == k){
        track[input] = end-1;
        return;
    } 
    if(v[end] == k){
        track[input] = end;
        return ;
    }
    if(v[start] > k){
        v[start] = k;
        track[input] = start;
        return ;
    }
    if(v[end] > k){
        v[end] = k;
        track[input] = end;
        return ;
    }
}

int main(){
    cin >> n;
    int tmp1,tmp2;
    for(int i=0;i<500002;i++){
        p[i] = -1;
    }

    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        p[tmp2] = tmp1;
    }

    for(int i=0;i<500002;i++){
        if(p[i] != -1){
            arr.push_back(p[i]);
        }
    }

    // cout << "arr---------" << endl;
    // for(int i=0;i<arr.size();i++){
    //     cout << arr[i] << " ";
    // }
    // cout << "arr---------" << endl;


    v.push_back(arr[0]);
    track[0] = 0;
    for(int i=1;i<n;i++){
        lower_bound(i);
        // print();
    }
    cout << n-v.size() << endl;
    int now = v.size()-1;
    for(int i=n-1;i>=0;i--){
        if(track[i] == now){
            // cout << arr[i] << " ";
            s.push(arr[i]);
            now--;
        }
        if(now == -1){
            break;
        }
    }
    // cout << endl;

    int now_s;

    priority_queue<int, vector<int>, greater<int> > pq;

    int i = 0;
    while(i < n && s.size() > 0){
        now = arr[i];
        now_s = s.top();
        if(now != now_s){
            pq.push(now);
        }
        else{
            if(s.size() > 0){
                s.pop();
            }
        }
        i++;
    }
    while(i < n){
        now = arr[i];
        pq.push(now);
        i++;
    }
    while(pq.size() > 0){
        cout << pq.top() << '\n';
        pq.pop();
    }
}





/*
5
1 10
2 3 
3 4
4 2
10 1

4
1 10
2 3 
3 4
4 2


8
1 8
3 9
2 2
4 1
6 4
500000 500000
9 7
7 6
*/