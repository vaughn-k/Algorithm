/*
참고문제

백준 11000 - 강의실 배정

알고리즘
    - 그리디
    - 우선순위큐      
        수업(시작시간,종료시간) 시작시간기준 오름차순 큐
        강의실(종료시간=시작가능시간) 오름차순 큐

        
        
문제개요
    n개의 수업(수업시작시간, 수업끝시간)이 주어지고 최소의 강의실로 모든 수업을 가능하게 해야할때 그 수 출력

    우선 수업들을 수업시간순으로 오름차순(같을경우 끝나는 시간으로 오름차순) 으로 우선순위큐(pq) 생성
    이후 끝나는 시간 기준으로 오름차순 정렬된 우선순위큐(classroom) 생성

    pq에서 하나씩 빼면서 만약 그 수업이 시작하는 시간이 classroom 의 top 값보다 크다면 해당 수업을 그 수업이후에 시작할 수 있고
    그게 아니라면 새로운 강의실을 만들어야한다.
*/ 

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Class{
    int start;
    int end;
};

struct cmp{
    bool operator()(Class a, Class b){
        if(a.start != b.start){
            return a.start > b.start;
        }
        else{
            return a.end > b.end;
        }
    }
};

priority_queue<Class,vector<Class>,cmp> pq;
priority_queue<int,vector<int>,greater<int> > classroom;

int n;

int main(){
    cin >> n;
    int tmp1,tmp2;
    Class cl;
    for(int i=0;i<n;i++){
        cin >> tmp1 >> tmp2;
        tmp2 = tmp2 - 1;
        cl.start = tmp1;
        cl.end = tmp2;
        pq.push(cl);
    }
    int front_class;
    while(pq.size() > 0){ // 아직 강의실 배정 안된 강의가 있으면 반복
        cl = pq.top();
        pq.pop();
        if(classroom.size() == 0){ // 현재 만든 강의실이 없을때
            classroom.push(cl.end);
        }
        else{
            front_class = classroom.top();
            if(front_class >= cl.start){ // 현재강의실중 현재 강의를 넣을곳이 없을때
            // 현재 만들어진 강의실에 현재 넣어야할 강의를 넣을 수 없는 상황이다.
            // 즉 현재 강의실이 3,5(3시까지, 5시까지 강의가 있는 강의실들)일때 2시에 시작하는 강의를 넣을 수 없는 상황이다. 
                classroom.push(cl.end); // 새로운 강의실 추가
            }
            else{ // 현재강의실중 현재 강의를 넣을곳이 있을때
                classroom.pop(); // 넣을 강의실을 큐에서 빼고
                classroom.push(cl.end); // 현재 강의를 넣어서 종료시간을 최신화 시켜서 다시 큐에 넣는다.
            }
        }
    }
    cout << classroom.size(); // 최종적으로 큐의 크기가 강의실의 개수가 된다.
    // 추가로, 큐에있는 int들은 강의들을 모두 배정했을때 각 강의실 별로 마지막강의가 끝나는 시간이 된다.
}