#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int visit[1000002];
vector<vector<int> > v;
queue<int> q1;
queue<int> q2;

int type_swift(int type){
    if(type == 1){
        return 0;
    }
    else{
        return 1;
    }
}

void find_minimum_adaptor(int num, int type){
    if(type == 1){
        q1.push(num);
    }
    else{
        q2.push(num);
    }

    int len = v[num].size();
    for(int i=0;i<len;i++){
        if(visit[v[num][i]] == 0){
            visit[v[num][i]] = 1;
            find_minimum_adaptor(v[num][i], type_swift(type));
        }
    }
}

int calculate_queue(){
    int tmp1 = 0;
    int tmp2 = 0;

    while(q1.size() > 0){
        tmp1 = tmp1 + q1.front();
        q1.pop();
    }
    while(q2.size() > 0){
        tmp2 = tmp2 + q2.front();
        q2.pop();
    }
    return min(tmp1,tmp2);
}

int main(){
    for(int i=0;i<1000002;i++){
        visit[i] = 0;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        v.push_back(vector<int>());
    }
    int x,y;
    for(int i=0;i<n-1;i++){
        cin >> x;
        cin >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    visit[1] = 1;
    find_minimum_adaptor(1,1);
    cout << min(q1.size(),q2.size());
}