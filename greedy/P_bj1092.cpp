/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.31

소요시간 : 2h+

문제명 - 백준 1092 - 배
   
알고리즘
    - 그리디
    - brute-force

문제개요
    n개의 크레인이 있고 각각 들수있는 최대무게가 있다.
    m개의 박스가 있다.

    이때 모든 박스를 옮기는데 필요한 최소시간 출력

    박스무게와 크레인 무게를 정렬한 후
    박스무게가 큰거부터 크레인에 넣고 구하거나, 박스무게가 작은것부터 크레인에 넣으면 다른 크레인
    들과 병렬적으로 작업하기 까다롭다.

    가장 일반적으로 생각할 수 있는 방법이 크레인이 들수있는 최대무게에 가깝게 박스들을 담는것이다.
    n 사이즈가 50이고 M 사이즈가 10000이므로

    최악의 경우 n*m = 500000이므로 생각보다 오래걸리지 않았다.

    즉, 크레인을 세워놓고 박스들을 하나씩보면서 실을수 있는 것들을 보는것이 아니라, 
    박스들을 하나씩 돌면서 이것을 실을수있는 크레인을 찾는것이다.

    다시말해서, 크레인1번이 박스1번부터 들수있는것을 찾고, 찾은박스가 k번째 박스라면, 
    크레인2번은 k+1부터 들수있는 박스를 찾는다.

    이런식으로 반복하면서 각 배열별로 찾은 박스는 0으로 변경해준다.

    따라서 최악의 경우 50만이 나오는것이다.

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> crain;
vector<int> box;

int boxState[10001];

int main(){
    int tmp;
    int maxi = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        crain.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        boxState[i] = 0;
        cin >> tmp;
        box.push_back(tmp);
    }

    sort(crain.begin(),crain.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());

    // 존재하는 크레인의 최대 용량보다 큰 박스가 존재하면 불가능
    if(box[0] > crain[0]){
        cout << -1;
        return 0;
    }
    int time = 0;
    int lft = m;
    int nowCrain;
    int nowBox;
    while(true){

        time++;
        nowCrain = 0;
        for(nowBox = 0; nowBox < m; nowBox++){
            if(boxState[nowBox] == 0){
                if(crain[nowCrain] >= box[nowBox]){
                    boxState[nowBox] = 1;
                    nowCrain++;
                    lft--;
                }
            }
            if(lft == 0){
                cout << time;
                return 0;
            }
        }
    }
}
