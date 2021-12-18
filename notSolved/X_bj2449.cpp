#include <iostream>

using namespace std;

int n,k;

void print(int arr[][2]){
    // for(int i=1;i<=n;i++){
    //     cout << arr[i][1] << " ";
    // }
    // cout << endl;
}

int run(int arr[][2]){
    int now = 1;
    int next,before;
    int left = 99999999;
    int right = 99999999;
    int tmp1,tmp2,tmp3,tmp4;
    int minimum = 99999999;
    if(arr[now][0] == n){
        return 0;
    }
    while(now <= n){
        next = now + arr[now][0];
        if(now != 1 && now + arr[now][0] <= n){ // 좌우모두 합체 가능할때
            if(arr[before][1] == arr[next][1]){ // 좌우의 타입이 같을때
                // cout << "here!! : " << now << endl;

                tmp1 = arr[before][0];
                arr[before][0] = arr[before][0] + arr[now][0] + arr[next][0]; 

                print(arr);
                right = run(arr) + 1;
                if(minimum > right){
                    minimum = right;
                }

                // 변경사항 리셋
                arr[before][0] = tmp1;
            }
            else{
                if(now != 1){ // 왼쪽으로 합체 
                    tmp1 = arr[before][0];
                    arr[before][0] = arr[before][0] + arr[now][0];
                    print(arr);    
                    left = run(arr) + 1;
                    if(minimum > left){
                        minimum = left;
                    }
                    // 변경사항 리셋
                    arr[before][0] = tmp1;

                }
                if(now + arr[now][0] <= n){ // 오른쪽으로 합체
                    tmp1 = arr[now][0];
                    tmp2 = arr[now][1];
                    arr[now][0] = arr[now][0] + arr[next][0];
                    arr[now][1] = arr[next][1];
                    print(arr);    
                    right = run(arr) + 1;
                    if(minimum > right){
                        minimum = right;
                    }

                    // 변경사항 리셋
                    arr[now][0] = tmp1;
                    arr[now][1] = tmp2;
                }
            }
        }
        else{
            if(now != 1){ // 왼쪽으로 합체 
                tmp1 = arr[before][0];
                arr[before][0] = arr[before][0] + arr[now][0];
                print(arr);    
                left = run(arr) + 1;
                if(minimum > left){
                    minimum = left;
                }
                // 변경사항 리셋
                arr[before][0] = tmp1;

            }
            if(now + arr[now][0] <= n){ // 오른쪽으로 합체
                tmp1 = arr[now][0];
                tmp2 = arr[now][1];
                arr[now][0] = arr[now][0] + arr[next][0];
                arr[now][1] = arr[next][1];
                print(arr);    
                right = run(arr) + 1;
                if(minimum > right){
                    minimum = right;
                }

                // 변경사항 리셋
                arr[now][0] = tmp1;
                arr[now][1] = tmp2;
            }

        }
        before = now;
        now = next;
    }
    return minimum;
}


int main(){
    int p[201][2];
    int tmp;
    int start,type,count;
    cin >> n;
    cin >> k;
    for(int i=1;i<=200;i++){
        p[i][0] = -1;
        p[i][1] = -1;
    }
    for(int i=1;i<n+1;i++){
        cin >> tmp;
        if(i == 1){
            start = 1;
            count = 1;
            type = tmp;
        }
        else{
            if(type != tmp){
                p[start][0] = count;
                p[start][1] = type;
                type = tmp;
                count = 1;
                start = i;
                if(i == n){
                    p[n][0] = 1;
                    p[n][1] = tmp;
                }
            }
            else{
                count++;
                if(i == n){
                    p[start][0] = count;
                    p[start][1] = type;
                }
            }
        }
    }

    // for(int i=1;i<n+1;i++){
    //     cout << "(" << p[i][0] << "," << p[i][1] << ")" << " ";
    // }
    cout << run(p);
}


/*

200 10
1 2 3 1 2 3 1 2 4 6 5 1 2 3 7 6 4 8 5 1 2 3 9 4 1 8 7 3 4 6 5 1 2 7 8 3 6 4 5 1 9 2 3 4 5 6 1 2 8 9 7 3 4 5 6 1 7 9 3 4 5 6 9 1 2 5 3 6 2 3 5 4 2 3 8 7 1 2 5 3 4 9 6 7 1 5 2 3 7 6 4 5 1 9 2 3 6 7 8 5 1 8 2 7 3 6 4 5 9 1 
2 3 7 6 5 4 8 9 7 1 2 3 6 4 8 9 7 1 2 3 6 4 8 9 7 
1 2 5 3 4 8 9 7 2 3 5 6 4 8 7 1 2 3 6 1 2 3 6 4 7 8 2 3 6 8 7 1 3 8 4 7 6 1 2 3 9 4 6 1 2 6 2 3 8 7 4 6 8 1 3 2 4 6 2 7 8 3 4 6 8 

*/