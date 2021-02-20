#include <iostream>
#include <queue>

using namespace std;

struct Location{
    int x;
    int y;
    int value;
};

struct cmp{
    bool operator()(Location a, Location b){
        return a.value > b.value;
    }
};



void basic(){
    // int 자료구조에서 가장 최대값 리턴해주는 Priority_queue
    priority_queue<int, vector<int>, less<int> > pq;
    /*
    비교 연산자는 기본적으로 less 로 설정되어 있으며 가장 큰 자료부터 나온다.
    greater로 설정할 경우 가장 작은 자료부터 나온다.
    */
    pq.push(10);
    pq.push(1);
    pq.push(3);
    pq.push(4);
    pq.push(6);
    pq.push(8);

    cout << pq.top() << endl;
}

void struct_queue(){
    // x,y좌표와 value로 구성된 struct에서 value 가 가장 작은 것부터 나오는 큐
    priority_queue<Location, vector<Location>, cmp > pq;
    Location l;
    l.x = 10;
    l.y = 5;
    l.value = 13;
    pq.push(l);

    l.x = 1;
    l.y = 2;
    l.value = 4;
    pq.push(l);

    l.x = 14;
    l.y = 2;
    l.value = 8;
    pq.push(l);

    Location output;
    output = pq.top();

    cout << output.x << endl;
    cout << output.y << endl;
    cout << output.value << endl;

}

int main(){
    basic();
    struct_queue();
}