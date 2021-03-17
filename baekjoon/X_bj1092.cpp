#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> crain;
priority_queue<int, vector<int>, less<int> > box1;
priority_queue<int, vector<int>, less<int> > box2;

int main(){
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        crain.push_back(tmp);
    }
    sort(crain.begin(),crain.end(),greater<int>());
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> tmp;
        box1.push(tmp);
    }
    // 존재하는 크레인의 최대 용량보다 큰 박스가 존재하면 불가능
    if(box1.top() > crain[0]){
        cout << -1;
        return 0;
    }
    int ct = 0;
    while(box1.size() > 0){
        ct++;
        for(int i=0;i<n;i++){
            while(box1.size() > 0){
                if(box1.top() > crain[i]){ // 현재 크레인이 담을수 없음
                    box2.push(box1.top());
                    box1.pop();
                }
                else{
                    box1.pop();
                    break;
                }
                if(box1.size() + box2.size() == 0){
                    break;
                }
            }
        }
        while(box2.size() > 0){
            box1.push(box2.top());
            box2.pop();
        }
    }
    cout << ct;
}

/*

3
1 4 5
10
5 5 5 4 4 4 1 1 1 1
*/