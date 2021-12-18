#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>


using namespace std;

int t,m,n,k;
int Count = 0;
vector<pair<int, int> >v;
queue<int> q1;
queue<int> q2;


bool compare(pair<int,int>a, pair<int, int>b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}


int main(){
    int tmp1, tmp2;

    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp1;
        cin >> tmp2;
        v.push_back(make_pair(tmp1,tmp2));
    }

    sort(v.begin(), v.end(), compare);
}
