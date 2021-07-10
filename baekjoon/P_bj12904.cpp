/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.19

소요시간 : 17m

문제명 - 백준 12904 - A와 B
   
알고리즘
    - 그리디
    - 다이렉트 접근

문제개요
    A,B로 이루어진 문자열이 두개 주어지고 정해진 조건에 따라 두 문자열이 같아질수 있는지 구하는 문제
    1. 문자열에 A추가 (x -> xA)
    2. 문자열을 뒤집고 B추가 (x -> x'B)

    조건에 따르면 어떤 문자열에 바로 A를 붙이거나 뒤집고 B를 붙이는 것이므로
    만약 x의 마지막 문자가 A라면 x -> xA 형태로 만들어진것이고
    x의 마지막 문자가 B라면 x -> x'B 형태로 만들어 진것이다.

    이를 이용하여 목표 문자열부터 삭제해 나가며 기존 문자열과 길이가 같아질때까지 반복한 후
    마지막에 두 문자열이 같은지 확인하면 될것이다.

*//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pqMinus;
priority_queue<int, vector<int>, less<int> > pqPlus;

int n,m;

int main(){
    int tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(tmp > 0){
            pqPlus.push(tmp);
        }
        else{
            pqMinus.push(tmp);
        }
    }

    int tot = 0;
    int cnt = m;

    int maxi;
    if(pqMinus.size() == 0){
        maxi = pqPlus.top();
    }
    else if(pqPlus.size() == 0){
        maxi = abs(pqMinus.top());
    }
    else{
        maxi = max(abs(pqMinus.top()),pqPlus.top());
    }
    while(pqMinus.size() > 0){
        if(cnt == m){
            // cout << pqMinus.top() << endl;
            tot = tot + abs(pqMinus.top());
        }
        cnt--;
        if(cnt == 0){
            cnt = m;
        }
        pqMinus.pop();
    }
    cnt = m;
    while(pqPlus.size() > 0){
        if(cnt == m){
            // cout << pqPlus.top() << endl;
            tot = tot + abs(pqPlus.top());
        }
        cnt--;
        if(cnt == 0){
            cnt = m;
        }
        pqPlus.pop();
    }
    tot = tot * 2 - maxi;
    cout << tot;
}
#include <iostream>
#include <string>

using namespace std;

string start;
string target;
string tmp;

int main(){
    cin >> start >> target;

    while(start.size() < target.size()){
        tmp = "";
        if(target[target.size()-1] == 'A'){
            for(int i=0;i<target.size()-1;i++){
                tmp.append(1,target[i]);
            }
        }
        else{
            for(int i=target.size()-2;i>=0;i--){
                tmp.append(1,target[i]);
            }
        }
        target = tmp;
    }
    for(int i=0;i<start.size();i++){
        if(start[i] != target[i]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}