#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n,m;
vector<int> v;
// int d[101][]

int go(int index, int left){
    cout << "index | left : " << index << " " << left << endl;
    if(index == -1){
        return -1;
    }
    // index : 현재 사탕종류, left : 채워야할 사탕개수
    int set; // 최대로 만들수있는 가방개수
    int ret;
    for(int i=0;i<=v[index];i++){ // i : 가방 1개에 넣을 사탕개수
        // cout << "for";
        if(i == 0){
            set = 0;
            ret = go(index-1,left-i);
            if(ret != -1){ // 가능한 결과
                return ret;
            }
        }
        else{
            set = v[index]/i;
            if(left - i == 0){
                return set;
            }
            ret = go(index-1,left-i);
            if(ret != -1){ // 가능한 결과
                cout << v[index] << " 's set : " << set << endl;
                return min(set,ret);
            }
        }
    }
    return -1;
}

int main(){
    int tmp;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());
    // for(int i=0;i<n;i++){
    //     cout << v[i] << " ";
    // }

    cout << go(v.size()-1,m);
}

// 100 0000 0000 0000 0000


/*

4 10
4 2 10 8

3 3
5 6 7

3 1
5 6 7

4 10
6894 4999 3441 2771
*/