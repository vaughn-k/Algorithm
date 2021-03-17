/* LIS (Longest Increasing Subsequence Algorithm) - 백준 14002번

    LIS 값 + 해당하는 수열까지 출력

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[1000001];
int track[1000001];
stack<int> s;
vector<int> v;
void print(){
    cout << "--------------" << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "--------------" << endl;
}


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
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    v.push_back(arr[0]);
    track[0] = 0;
    for(int i=1;i<n;i++){
        lower_bound(i);
        // print();
    }

    cout << v.size() << endl;
    int now = v.size()-1;
    for(int i=n-1;i>=0;i--){
        // cout << track[i] << " ";
        if(track[i] == now){
            // cout << arr[i] << " ";
            s.push(arr[i]);
            now--;
        }
        if(now == -1){
            break;
        }
    }
    while(s.size() > 0){
        cout << s.top() << " ";
        s.pop();
    }
}

/*
50
1 4 2 3 9 8 2 3 1 4 8 11 13 9 10 11 12 13 14 15 16 17 18 19 20 1 4 2 3 9 8 2 3 1 4 8 11 13 9 10 11 12 13 14 15 16 17 18 19 20

24
100 101 102 103 104 11 12 31 41 51 61 105 106 1 2 3 4 5 6 7 8 9 10 11

*/