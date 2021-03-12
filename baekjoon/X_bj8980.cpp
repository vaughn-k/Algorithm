#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Item{
    int end;
    int box;
};

struct cmp{
    bool operator()(Item a, Item b){
        return a.end > b.end;
    }
};

priority_queue<Item, vector<Item>, cmp> pq;
int n,c,m;
int truck = 0;
int tot = 0;

int town[2001][2001];

int loadItems(int start){
    // start 지점에서 짐을 싣는 경우
    // 1. 현재 마을에서 내릴수 있는 짐 모두 내리기
    Item item;
    while(pq.size() > 0){
        item = pq.top();
        if(item.end == start){
            pq.pop();
            tot = tot + item.box;
            truck = truck - item.box;
            // cout << start << "지점에서 " << item.box << "개의 짐을 내림" << endl;
        }
        else{
            break;
        }
    }

    // 2. 현재 마을에서 담을수있는 짐 담기
    int ableLoad;
    for(int i=start+1;i<=n;i++){
        if(truck == c){
            return 0;
        }
        else{
            if(town[start][i] > 0){ // start 마을에서 뒷마을(i)로 보낼 상품이 있을때
                if(truck + town[start][i] > c){ // 보낼 박스를 다 넣으면 트럭의 최대 용량을 초과할때
                    ableLoad = c - truck;
                }
                else{
                    ableLoad = town[start][i]; // 보낼 박스를 다 넣어도 트럭의 최대용량을 안넘을때
                }
                // cout << start << "번째 마을에서 " << i << "번째 마을로 " << ableLoad << "개의 박스를 담음." << endl;
                item.box = ableLoad;
                item.end = i;
                pq.push(item);
                truck = truck + ableLoad;
            }
        }
    }
    return 1;
}

int main(){
    cin >> n >> c >> m;
    for(int i=0;i<2001;i++){
        for(int j=0;j<2001;j++){
            town[i][j] = 0;
        }
    }
    int s,e,b;
    for(int i=0;i<m;i++){
        cin >> s >> e >> b;
        town[s][e] = town[s][e] + b;
    }
    
    for(int i=1;i<=n;i++){
        loadItems(i);
    }
    cout << tot;
}

/*

4 40
3
1 4 40
2 3 40
3 4 40


*/