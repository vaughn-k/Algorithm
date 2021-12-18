#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t,n,k,target;
int build[1002];
int visited[1002];
int subVisited[1002];
int must[1002];

int v[1002][1002];
int vInverse[1002][1002];
int vCount[1002];
int vInverseCount[1002];

queue<int> q;

int go(int id){
    if(id == target){
        return build[id];
    }
    int maxi = -1;
    int next;
    int ret;
    for(int i=0;i<vCount[id];i++){
        next = v[id][i];
        if(must[next] == 1){
            if(visited[next] >= 0){
                ret = visited[next];
            }
            else{
                ret = max(maxi, go(next));
            }
            maxi = max(maxi, ret);
        } 
    }
    visited[id] = maxi + build[id];
    return maxi + build[id];
}

void findHead(int id){
    must[id] = 1;
    if(vInverseCount[id] == 0){
        q.push(id);
        return;
    }
    for(int i=0;i<vInverseCount[id];i++){
        if(subVisited[vInverse[id][i]] == -1){
            subVisited[vInverse[id][i]] = 1;
            findHead(vInverse[id][i]);
        }
    }
}

int main(){
    
    int t1,t2,maxi;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> k;
        for(int j=1;j<=n;j++){
            visited[j] = -1;
            subVisited[j] = -1;
            must[j] = 0;
            cin >> build[j];
            vCount[j] = 0;
            vInverseCount[j] = 0;
        }
        for(int j=0;j<k;j++){
            cin >> t1 >> t2;
            v[t1][vCount[t1]] = t2;
            vCount[t1]++;

            vInverse[t2][vInverseCount[t2]] = t1;
            vInverseCount[t2]++;
        }
        cin >> target;
        maxi = -1;
        findHead(target);
        while(q.size() > 0){
            maxi = max(maxi, go(q.front()));
            q.pop();
        }
        cout << maxi << '\n';
    }
}