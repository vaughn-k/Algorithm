#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,m,k;
vector<vector<pair<int,int> > > v;

int main(){
    int s;
    s = 1;
    cout << s << endl;
    s = s << 3;
    cout << s;
}


// int dfs(int now, int state){
//     if(now == n){
//         return 0;
//     }
//     for(int i=0;i<v[now].size();i++){
//         if()
//     }
// }

// int main(){
//     int t1,t2,t3;
//     cin >> n >> m >> k;
//     for(int i=0;i<=n;i++){
//         v.push_back(vector<pair<int,int> >());
//     }
//     for(int j=0;j<=n;j++){
//         cin >> t1 >> t2 >> t3;
//         v[t1].push_back(make_pair(t2,t3));
//         v[t2].push_back(make_pair(t1,t3));
//     }

// }