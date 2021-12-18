/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.19

소요시간 : 40m

문제명 - 백준 17629 - 개구리 점프
   
알고리즘
    - 그리디
    - 우선순위 큐
    - 다이렉트 접근

문제개요
    통나무 n개가 주어지고 통나무의 길이와 위치가 두 좌표로 주어지고, 통나무를 위아래로만 이동 가능
    할 때, 두 통나무 번호가 주어졌을 때 두 통나무간 이동이 가능한지 구하는 문제.

    통나무의 시작지점 기준으로 정렬 한 후 현재까지 이동가능한 최대 거리좌표를 저장해두고 새로운
    통나무가 그 이하라면 같은 id값을 부여하고 end길이를 최신화한다.
    그렇지 않다면 id값을 +1 해서 부여한후, end길이를 최신화한다.

    

*//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Tree{
    int start;
    int end;
    int height;
    int id;
};

int d[100001];
// d[i] = i번째 통나무의 아이디값. 이 값이 같다면 서로 이동가능함을 의미한다.
struct cmp{
    bool operator()(Tree a, Tree b){
        return a.start > b.start;
    }
};

priority_queue<Tree, vector<Tree>, cmp> qt;
int n,q;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    Tree tree;
    int t1,t2,t3;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> t1 >> t2 >> t3;
        tree.start = t1;
        tree.end = t2;
        tree.height = t3;
        tree.id = i+1;
        qt.push(tree);
    }

    tree = qt.top();
    qt.pop();
    int id = 0; 
    int end = tree.end;
    d[tree.id] = 0;
    for(int i=2;i<=n;i++){
        tree = qt.top();
        qt.pop();
        if(tree.start <= end){
            d[tree.id] = id;
            if(end < tree.end){
                end = tree.end;
            }
        }
        else{
            id++;
            end = tree.end;
            d[tree.id] = id;
        }
    }

    for(int i=0;i<q;i++){
        cin >> t1 >> t2;
        if(d[t1] == d[t2]){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
}