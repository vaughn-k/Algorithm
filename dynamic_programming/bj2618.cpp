#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n,w;
vector<pair<int,int> > p;
int store[1010][1010];
vector<vector<string> > string_store;
// 0 방문전

// 단 police1,2는 각각 -1, -2이며 한번이상 이동시 정상적인 0이상의 정수로 작용

int calculate_distance(int police, int target){
    int police_x,police_y,target_x,target_y;
    if(police == -1){
        police_x = 1;
        police_y = 1;
    }
    else if(police == -2){
        police_x = n;
        police_y = n;

    }
    else{
        police_x = p[police].first;
        police_y = p[police].second;
    }
    target_x = p[target].first;
    target_y = p[target].second;
    return abs(police_x-target_x) + abs(police_y-target_y);
}

pair<int, string> find_distance(int police1, int police2){
    if(police1 == w-1 || police2 == w-1){
        return make_pair(0,"");
    }
    pair<int, string> tmp1, tmp2;
    string s;
    int total1, total2, move;
    if(police1 < 0 && police2 < 0){
        move = 0;
    }
    else{
        move = max(police1, police2) + 1;
    }
    if(store[police1+2][police2+2] != -1){
        return make_pair(store[police1+2][police2+2],string_store[police1+2][police2+2]);
    }
    tmp1 = find_distance(move,police2);
    total1 = tmp1.first + calculate_distance(police1, move);
    tmp2 = find_distance(police1,move);
    total2 = tmp2.first + calculate_distance(police2, move);
    store[police1+2][police2+2] = min(total1,total2);

    if(total1 < total2){
        s = "1" +tmp1.second;
    }
    else{
        s = "2" + tmp2.second;
    }
    string_store[police1+2][police2+2] = s;
    return make_pair(min(total1,total2),s);
}

int main(){
    int tmp1,tmp2;
    cin >> n;
    cin >> w;
    for(int i=0;i<w;i++){
        cin >> tmp1;
        cin >> tmp2;
        p.push_back(make_pair(tmp1,tmp2));
    }

    for(int i=0;i<1010;i++){
        for(int j=0;j<1010;j++){
            store[i][j] = -1;
        }
        vector<string> sub;
        sub.resize(1001);
        string_store.push_back(sub);
        // string_store[i].push_back("");
            // string_store.push_back(vector<string>());
    }

    pair<int, string> answer;
    answer = find_distance(-1,-2);
    cout << answer.first << endl;
    for(int i=0;i<answer.second.length();i++){
        cout << answer.second[i] << endl;
    }
}