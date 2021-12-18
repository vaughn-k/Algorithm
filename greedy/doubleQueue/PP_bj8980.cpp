/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.03.31

소요시간 : 4h++

문제명 - 백준 8980 택배
   
알고리즘
    - 그리디
    - triple priority queue

문제개요
    n개의 마을이 있고 m개의 택배 정보가 있다(보내는마을, 받는마을, 보낼박스개수)
    이때 트럭의 최대 적재용량이 주어질때 보낼수있는 최대 박스개수

    (보낼박스개수 중에 일부만 보낼수도 있다)

    출발지부터 시작하며 한사이클에 4단계로 구분하였다.
    1. 현재 트럭리스트에 있는 택배중에 현재 마을에 내릴수있는(도착지가 현재 마을인) 택배를 내린다

    2. 현재 트럭에 남아있는 박스들을 임시 리스트에 모두 넘긴다.

    3. 이번 마을에서 새로 보낼수 있는 택배리스트들을 모두 임시 리스트에 넣는다.

    4. 임시리스트에 있는 택배들중 최대 용량에 맞춰 재조정한후 finalList에 넣는다.
    (여기서는 도착지가 가까운 순으로 maxWeight까지만 담는다.)


    이문제의 경우 초기에 골랐던 택배(최악의 경우 1번마을에서 n번마을로 가는택배)가 최악일 경우
    마지막까지 그 선택이 영향을 주게된다.

    따라서 1번마을에서 보낼택배는 n번마을에 가보기 전까지 보낼지말지 선택을 할 수 없다.
    
    따라서 이렇게 이해하면 쉬울것이다.
    
    먼저 마을에 도착하면 그 마을에 내릴수있는 박스들을 내린다.
    그리고 그 마을에서 보낼수있는 택배들을 모두 종합한후 그들중 도착지가 가까운순으로 max개만큼만
    담는다.
    이 과정을 반복한다.

    이러한 최적화는 실제 택배에서는 말도안되는 일이다.
    1번마을에서 10번마을로 가는 택배를 실었는데 갑자기 5번마을에서 6번마을로 가는 택배가 생기면
    (그 무게가 최대 적재용량이라면) 이 택배기사는 가지고있던 택배(1->10로 가는택배) 를 그냥 
    버리고 5->6 으로 가는 택배를 담고 다음마을로 가게된다.
    

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

struct Item{
    int send;
    int recv;
    int box;
};

struct lowSend{
    bool operator()(Item a, Item b){
        if(a.send == b.send){
            return a.recv > b.recv;
        }
        else{
            return a.send > b.send;
        }
    }
};

struct lowRecv{
    bool operator()(Item a, Item b){
        return a.recv > b.recv;
    }
};



priority_queue<Item, vector<Item>, lowSend> allList;
priority_queue<Item, vector<Item>, lowRecv> truckList;
priority_queue<Item, vector<Item>, lowRecv> finalList; // 도착치 작은순



int n,m;
int maxTruck;
int truck = 0;
int tot = 0;

int main(){
    Item item;
    Item addWait;
    int t1,t2,t3;
    cin >> n >> maxTruck >> m;
    for(int i=0;i<m;i++){
        cin >> t1 >> t2 >> t3;
        item.send = t1;
        item.recv = t2;
        item.box = t3;
        allList.push(item);
    }
    
    int tot = 0;
    int weight;
    int able;
    for(int vilage = 1; vilage <= n; vilage++){
        // 현재마을에서 내릴수있는 택배 내리기
        while(finalList.size() > 0){
            item = finalList.top();
            if(item.recv == vilage){
                // cout << item.send << "에서 " << item.recv << "로 " << able << "만큼 보냄" << endl;
                tot += item.box;
                weight -= item.box;
                finalList.pop();
            }
            else{
                break;
            }
        }

        // 남은택배 선택지에 추가
        while(finalList.size() > 0){
            truckList.push(finalList.top());
            finalList.pop();
        }

        // vilage에서 보낼수있는 가능한 목록 모두 업데이트(무게 상관 x)
        while(allList.size() > 0){
            item = allList.top();
            if(item.send == vilage){
                truckList.push(item);
                allList.pop();
            }
            else{
                break;
            }
        }

        // 최대 무게 맞춰서 최대효율 박스들만 골라내기
        weight = 0;
        while(truckList.size() > 0){
            item = truckList.top();
            if(weight < maxTruck){ // 남은 용량이 있을때만
                able = min(maxTruck - weight, item.box);
                item.box = able;
                weight += able;
                finalList.push(item);
            }
            truckList.pop();
        }
    }
    cout << tot;
}
