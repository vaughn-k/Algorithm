#include <iostream>
#include <vector>

using namespace std;

strcut 

int n,m;
vector<vector<int> > v;
vector<vector<int> > dist;


void floyd(){

}

int main(){
    int t1,t2,d;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        v.push_back(vector<int>());
    }

    // dist.push_back(vector<int>());
    for(int j=0;j<m;j++){
        cin >> t1 >> t2 >> d;
        v[t1].push_back(t2);
        // dist[i].push_back(99999999);
    }
    


}