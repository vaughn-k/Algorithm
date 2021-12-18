#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n;
int originX, originY, originZ;

struct Box{
    int x;
    int y;
    int z;
    int ct;
};

struct cmp{ // xyz 중 최소값이 큰순서대로
    bool operator()(Box a, Box b){
        if(a.z == b.z){
            if(a.y == b.y){
                return a.x < b.x;
            }
            return a.y < b.y;
        }
        return a.z < b.z;
    }
};

priority_queue<Box, vector<Box>, cmp> pq;
priority_queue<Box, vector<Box>, cmp> list;
priority_queue<int, vector<int>, less<int> > tmpQueue;

Box makeBox(int x, int y, int z, int ct){ // x >= y >= z 순으로 박스 생성
    Box tmp;
    tmpQueue.push(x);
    tmpQueue.push(y);
    tmpQueue.push(z);
    tmp.x = tmpQueue.top(); 
    tmpQueue.pop();
    tmp.y = tmpQueue.top(); 
    tmpQueue.pop();
    tmp.z = tmpQueue.top(); 
    tmpQueue.pop();
    tmp.ct = ct;
    return tmp;
}

int main(){
    int tmp1,tmp2;
    Box box;
    Box mainbox;
    Box tmpbox;
    cin >> originX >> originY >> originZ;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        tmp1 = pow(2,tmp1);
        box = makeBox(tmp1,tmp1,tmp1,tmp2);
        list.push(box);
    }

    int tot = 0;

    pq.push(makeBox(originX, originY, originZ, 1));
    while(pq.size() > 0){
        if(list.size() == 0){ // 더이상 못만듬
            cout << -1;
            return 0;
        }
        mainbox = pq.top();
        box = list.top();
        // cout << "tot : " << tot << endl;
        // cout << "x,y,z : " << mainbox.x << "|" << mainbox.y << "|" << mainbox.z << endl;
        if(mainbox.z < box.z){ // 만들어야 할 박스중에 쓸수있는 최대 박스 크기보다, 쓸수있는 박스의 크기가 더 크다면
        // 현재 이 박스는 절대 사용할수 없다.
            list.pop();
        }
        else{
            tot++;
            if(mainbox.ct == 1){
                pq.pop();
            }
            else{
                mainbox.ct = mainbox.ct - 1;
                pq.pop();
                pq.push(mainbox);
            }

            if(box.ct == 1){
                list.pop();
            }
            else{
                box.ct = box.ct - 1;
                list.pop();
                list.push(box);
            }

            // a박스 만들기
            tmpbox.x = mainbox.x - box.z;
            tmpbox.y = mainbox.y;
            tmpbox.z = mainbox.z;
            tmpbox.ct = 1;
            // cout << "now make : " << tmpbox.x << "|" << tmpbox.y << "|" << tmpbox.z << endl;
            if(min(min(tmpbox.x,tmpbox.y),tmpbox.z) != 0){
                pq.push(tmpbox);
            }
            // b박스 만들기
            tmpbox.x = box.z;
            tmpbox.y = mainbox.y - box.z;
            tmpbox.z = mainbox.z;
            tmpbox.ct = 1;
            // cout << "now make : " << tmpbox.x << "|" << tmpbox.y << "|" << tmpbox.z << endl;
            if(min(min(tmpbox.x,tmpbox.y),tmpbox.z) != 0){
                pq.push(tmpbox);
            }
            // c박스 만들기
            tmpbox.x = box.z;
            tmpbox.y = box.y;
            tmpbox.z = mainbox.z - box.z;
            tmpbox.ct = 1;
            // cout << "now make : " << tmpbox.x << "|" << tmpbox.y << "|" << tmpbox.z << endl;
            if(min(min(tmpbox.x,tmpbox.y),tmpbox.z) != 0){
                pq.push(tmpbox);
            }
        }
    }
    cout << tot;
}