#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,h;

struct Change{
    int index;
    int height;
};

struct cmp{
    bool operator()(Change a, Change b){
        return a.height > b.height;
    }
};

priority_queue<Change,vector<Change>, cmp> pq;

int ladder[301];

int main(){
    int tmp1,tmp2;
    Change c;
    cin >> n >> m >> h;
    for(int i=1;i<=n;i++){
        ladder[i] = i;
    }
    for(int i=0;i<m;i++){
        cin >> tmp2 >> tmp1;
        c.index = tmp1;
        c.height = tmp2;
        pq.push(c);
    }

    int tmp;
    while(pq.size() > 0){
        c = pq.top();
        // cout << "-----------------" << endl;

        // cout << "index : " << c.index << endl;
        // cout << "height : " << c.height << endl;
        // for(int i=1;i<=n;i++){
        //     cout << ladder[i] << " ";
        // }
        // cout << "-----------------" << endl;
        pq.pop();
        tmp = ladder[c.index];
        ladder[c.index] = ladder[c.index+1];
        ladder[c.index+1] = tmp;
    }
    // cout << "-----------------" << endl;
    // for(int i=1;i<=n;i++){
    //     cout << ladder[i] << " ";
    // }
    // cout << "-----------------" << endl;


    int op = 0;
    for(int i=1;i<=n;i++){
        if(ladder[i] != i){
            if(op == 3){
                cout << -1;
                return 0;
            }
            op++;
            for(int j=i+1; j<=n; j++){
                if(ladder[j] == i){
                    tmp = ladder[j];
                    ladder[j] = ladder[i];
                    ladder[i] = tmp;
                }
            }
        }
    }
    cout << op;
}