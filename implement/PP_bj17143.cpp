/*/////////////////////////////////////////////////////////////////////////
소요시간 : 2h 20m

문제명 - 백준 17143 - 낚시왕

알고리즘
    - 좌표이동에서 벽만났을때 방향전환

문제개요
    n by m 좌표에 상어k마리가 있고(상어의 위치, 크기, 속도, 방향 주어짐)
    각 턴마다 0열부터 가장 가까운 상어를 잡고 (이때 점수 = 점수 + 상어크기)
    상어들이 정해진 방향, 속도에따라 움직일때
    (단 움직였을대 상어가 겹치면 작은 상어가 잡아먹힘)

    m개의 열에서 낚시를 모두했을때 점수는?

    - 좌표상에서 0미만으로 가거나 n또는m 사이즈를 초과해서 넘어갈때 반대로 좌표 이동해주고 방향
    전환 해주는것이 까다로웠다.

    - 또한 상어들의 위치를 priority_queue(크기순으로 내림차순)로 관리하였으며 상어를 잡았을
    때 큐에서 빼기 쉽지않으므로 삭제할 상어를 전역변수로 가지고있다가 큐에서 후에 이동하기 위해
    뺄때마다 확인했다. 이렇게하지않으면 최대 O(K^2)만큼의 시간복잡도가 걸릴것이다.


*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Shark{
    int i;
    int j;
    int speed;
    int direction;
    int size;

};

struct cmp{
    bool operator()(Shark a, Shark b){
        return a.size < b.size;
    }
};

priority_queue<Shark, vector<Shark>, cmp> pq1;
priority_queue<Shark, vector<Shark>, cmp> pq2;
// 상어 크기가 큰것부터 출력

int n,m,k;
int score = 0;
int deleteSize;

int existShark[102][102];

// void print(){
//     cout << "now --------------" << endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout << existShark[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "------------------" << endl;
// }
pair<int, int> moveshark(int position, int direction, int cot){
    // cout << position << " " << direction << " " << cot << endl;
    int maximum;
    int pm;
    int inverse;

    if(direction <= 2){
        maximum = n;
        if(direction == 1){
            inverse = 2;
        }
        else{
            inverse = 1;
        }
    }
    else{
        maximum = m;
        if(direction == 3){
            inverse = 4;
        }
        else{
            inverse = 3;
        }
    }
    if(direction == 2 || direction == 3){
        pm = 1;
    }
    else{
        pm = -1;
    }

    position = position + cot * pm;
    if(position < 0){ // 갔는데 0이하로 간경우
        cot = abs(position); // 얼마나 초과했는가
        if(cot >= maximum){ // 다시 돌아가도 반대쪽을 넘는가?
            return moveshark(0,inverse,cot); // 0부터 cot칸 갔을때로 재귀
        }
        else{
            return make_pair(cot,inverse); // 반대쪽을 넘지않으면 바로 종료
        }
    }
    if(position > maximum-1){ // 갔는데 배열을 초과한경우
        cot = position - (maximum-1); // 얼마나 초과했는가
        if(cot >= maximum){
            return moveshark(maximum-1,inverse,cot);
        }
        else{
            return make_pair(maximum-1 - cot,inverse);
        }
    }
    return make_pair(position,direction);
}

void cycle(int humanLocation){
    // cout << endl;
    // cout << "cycle : " << humanLocation << endl;
    // print();
    // 해당 열에서 가장 가까운 상어잡기
    for(int i=0;i<n;i++){
        if(existShark[i][humanLocation] != 0){
            // cout << "size가 " << existShark[i][humanLocation] << "인 상어 포획 " << endl;
            score = score + existShark[i][humanLocation];
            deleteSize = existShark[i][humanLocation];
            break;
        }
    }


    // 상어 존재여부 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            existShark[i][j] = 0;
        }
    }

    Shark shark;
    pair<int,int> moveLocation;
    int select;
    int goi,goj;
    // cout << "상어 움직이기 시작 "<< endl;
    while(pq1.size() > 0){
        shark = pq1.top();
        pq1.pop();
        if(shark.size != deleteSize){
            if(shark.direction <= 2){
                select = shark.i;
            }
            else{
                select = shark.j;
            }
            moveLocation = moveshark(select,shark.direction,shark.speed);
            goi = shark.i;
            goj = shark.j;
            if(shark.direction <= 2){
                goi = moveLocation.first;
            }
            else{
                goj = moveLocation.first;
            }
            // cout << "size = " << shark.size << "인 상어는 " << shark.i << "," << shark.j << " -> " << goi<< "," << goj << " 로 이동하였습니다" << endl;
            shark.direction = moveLocation.second;
            
            if(existShark[goi][goj] == 0){ // 가려는 칸에 상어가 없을때만 진입
                existShark[goi][goj] = shark.size;
                shark.i = goi;
                shark.j = goj;
                pq2.push(shark);
            }
        }
    }
    pq1 = pq2;
    while(pq2.size() > 0){
        pq2.pop();
    }
}

int main(){
    Shark shark;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            existShark[i][j] = 0;
        }
    }
    
    for(int i=0;i<k;i++){
        cin >> shark.i >> shark.j >> shark.speed >> shark.direction >> shark.size;
        if(shark.direction <= 2){
            shark.speed = shark.speed % ((n-1)*2);
        }
        else{
            shark.speed = shark.speed % ((m-1)*2);
        }
        shark.i--;
        shark.j--;
        existShark[shark.i][shark.j] = shark.size;
        pq1.push(shark);
    }

    for(int i=0;i<m;i++){
        cycle(i);
    }
    cout << score;
}

/*

4 7 5
2 2 5 3 3
2 4 3 2 2
3 5 2 1 1 
1 6 3 2 4 
2 7 2 4 5

*/