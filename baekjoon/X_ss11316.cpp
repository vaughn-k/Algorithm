#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int t,s,p,q,m;

vector<pair<int,int> > v;

int main(){
    cin >> t;
    int next;
    int count;
    int answer;
    for(int i=0;i<1000001;i++){
        v.push_back(make_pair(-1,-1));
    }
    for(int i=0;i<t;i++){
        cin >> s >> p >> q >> m;
        next = s;
        count = 0;
        while(v[next].first != i){
            v[next].first = i;
            v[next].second = count;
            next = (next * p + q) % m;
            count++;
        }
        answer = count - v[next].second;
        cout << answer << endl;
    }
}