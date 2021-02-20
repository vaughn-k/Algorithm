#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int t;
int n;
vector<pair<int, int> > vp;

int main(){
    cin >> t;
    vp.push_back(make_pair(1,0));
    vp.push_back(make_pair(0,1));
    for(int i=2;i<41;i++){
        vp.push_back(make_pair(
            vp[i-2].first+vp[i-1].first,
            vp[i-2].second+vp[i-1].second)
        );
    }

    while(t > 0){
        cin >> n;
        cout << vp[n].first << " " << vp[n].second << endl;
        t--;
    }
} 