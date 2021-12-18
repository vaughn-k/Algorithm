// LIS (Longest Increasing Subsequence Algorithm) - 백준 12738번
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000001];
vector<int> v;
void print(){
    cout << "--------------" << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "--------------" << endl;
}


void lower_bound(int k){
    int start,end,mid;
    if(v[v.size()-1] < k){
        v.push_back(k);
        return;
    }
    if(v.size() == 1){
        if(v[0] < k){
            v.push_back(k);
        }
        else{
            v[0] = k;
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
            // cout << "same : " << k << endl;
            return;
        }
    }
    if(v[end-1] == k || v[end] == k){
        return ;
    }
    if(v[start] > k){
        v[start] = k;
        return ;
    }
    if(v[end] > k){
        v[end] = k;
        return ;
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        lower_bound(arr[i]);
        print();
    }

    cout << v.size();
}

/*

25
1 4 2 3 9 8 2 3 1 4 8 11 13 9 10 11 12 13 14 15 16 17 18 19 20

*/