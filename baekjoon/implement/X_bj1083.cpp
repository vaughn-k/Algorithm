// 2h 미해결

// 현재방법으로는 동일숫자가 s만큼 있을때 대처하지못함;;

#include <iostream>
#include <queue>

using namespace std;

int n,k;
int arr[51];
int priority[51];

queue<int> q;

void sub(int lft){
    // 0번 index부터 시작해서 priority[i] == 0 인 값들 lft개중 가장 큰값 1로 처리하고 큐에 넣음
    if(lft <= 0){
        return;
    }
    bool first = true;
    int maxi, maxindex;
    int cot = 1;
    int maxicot = 0;
    int index = 0;
    int now;
    while(cot <= lft){
        if(priority[index] == 0){
            now = arr[index];
            if(first){
                maxi = now;
                maxindex = index;
                maxicot = cot;
                first = false;
            }
            else{
                if(maxi < now){
                    maxi = now;
                    maxindex = index;
                    maxicot = cot;
                    cot++;
                }
            }
        }
        index++;
    }
    q.push(maxi);
    priority[maxindex] = 1;
    sub(lft - maxicot);
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        priority[i] = 0;
        cin >> arr[i];
    }
    cin >> k;
    sub(k);

    // for(int i=0;i<n;i++){
    //     cout << priority[i] << " ";
    // }
    // cout << endl;

    while(q.size() > 0){
        cout << q.front() << " ";
        q.pop();
    }

    for(int i=0;i<n;i++){
        if(priority[i] == 0){
            cout << arr[i] << " ";
        }
    }

}

/*
10
10 10 10 10 10 20 30 40 50 60
5

*/