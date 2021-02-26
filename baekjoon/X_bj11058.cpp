#include <iostream> 
#include <queue> 
#include <utility> 

using namespace std;

int n;
queue<pair<int,int> > q1;
queue<pair<int,int> > q2;
queue<pair<int,int> > use;
queue<pair<int,int> > wait1;
queue<pair<int,int> > wait2;


void run(){
    pair<int,int> now;
    q1 = q2;
    while(q2.size() > 0){ q2.pop(); }
    
    use = wait1;
    wait1 = wait2;
    while(wait2.size() > 0){ wait2.pop(); }
    while(use.size() > 0){
        now = use.front();
        // 4. 선택한 내용 붙여넣기
        q1.push(make_pair(now.first+now.second,now.second));
    }

    
    for(int i=0;i<n;i++){
    
        while(q1.size() > 0){
            now = q1.front();
            q1.pop();

            // 1. 화면에 A 출력
            q2.push(make_pair(now.first+1,now.second));

            // 2. 화면 전체 선택
            q2.push(make_pair(now.first+1,now.second));

            // 3. 버퍼에 복사하기 
            
        }
        
    }
}

int main(){
    cin >> n;
    q2.push(make_pair(0,0));
    run();

}