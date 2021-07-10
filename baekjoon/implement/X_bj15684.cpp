#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m,h;
int arr[10];
vector<int> ar1;
vector<int> ar2;

struct cmp{
    bool operator()(pair<int,int> A, pair<int,int> B){
        return A.first > B.first;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;

void swapAB(int c){
    int t = arr[c];
    arr[c] = arr[c+1];
    arr[c+1] = t;
}

int main(){
    int tmp1,tmp2;
    cin >> n >> m >> h;
    if(m == 0){
        cout << 0;
        return 0;
    }
    for(int i=0;i<m;i++){
        cin >> tmp1 >> tmp2;
        pq.push(make_pair(tmp1,tmp2));
    }
    for(int i=0;i<n;i++){
        arr[i] = i;
    }
    pair<int,int> tmp;
    while(pq.size() > 0){
        tmp = pq.top();
        pq.pop();
        swapAB(tmp.second-1);
        // for(int j=0;j<n;j++){
        //     cout << arr[j] << ",";
        // }
        // cout << endl;
    }

    int falseCount = 0;
    for(int i=0;i<n;i++){

        if(arr[i] != i){
            ar1.push_back(i); 
            ar2.push_back(arr[i]); 
            falseCount++;
        }
    }

    if(falseCount > 4){
        cout << -1;
    }
    else if(falseCount == 0){
        cout << 0;
    }
    else{
        if(falseCount == 4){
            for(int i=1;i<4;i++){
                if((arr[ar1[0]] == arr[ar2[i]]) && (arr[ar1[i]] == arr[ar2[0]])){
                    cout << 2;
                    return 0;
                }
            }
            cout << 3;
        }
        else{
            falseCount--;
            cout << falseCount;
        }
    }
    return 0;
}
