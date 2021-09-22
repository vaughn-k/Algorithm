#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Elem{
    int w;
    int index;
};

struct cmp{
    bool operator()(Elem a, Elem b){
        return a.w > b.w;
    }
};

priority_queue<Elem, vector<Elem>, cmp> pq;
vector<int> answer;
vector<int> input;

int n,t;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> t;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        input.push_back(tmp);
    }

    Elem elem;
    for(int i=0;i<n;i++){
        elem.w = input[i];
        elem.index = i;
        pq.push(elem);
        if(i < t){
            // answer.push_back(pq.top().w);
        }
        else{
            while(pq.top().index <= (i-t)){
                pq.pop();
            }
            // answer.push_back(pq.top().w);
        }
        tmp = pq.top().w;
        cout << tmp << " ";
    }
}