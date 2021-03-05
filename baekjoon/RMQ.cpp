#include <iostream>

using namespace std;

int arr[1024];
int d[1024];
int n;

int rmq_init(int now){
    if(now > n){
        d[now] = arr[now-n-1];
    }
    else{
        if(now*2+1 > n*2){
            d[now] = rmq_init(now*2);
        }
        else{
            d[now] = min(rmq_init(now*2),rmq_init(now*2+1));
        }
    }
    cout << "now : " << now << " : " << d[now] << endl;
    return d[now];
}

int rmq_query(int left, int right, int node, int nodeLeft, int nodeRight){
    // 둘의 교집합이 node일때
    if(left <= nodeLeft && nodeRight <= right){
        return d[node];
    }
    // 둘의 교집합이 공집합일때
    if(right < nodeLeft || nodeRight < left){
        return 99999999;
    }
    // 그 외의 경우
    int mid = (nodeLeft + nodeRight)/2;
    return min(
        rmq_query(left,right,node*2,nodeLeft,mid),
        rmq_query(left,right,node*2+1,mid+1,nodeRight)
    );
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    rmq_init(1);
    // for(int i=0;i<n*2;i++){
    //     cout << d[i];
    // }
    cout << rmq_query(13,14,1,0,n-1);
}

/*
input

15
3 9 6 4 2 1 5 2 3 3 6 9 1 4 7
*/