#include <iostream>
#include <utility>

using namespace std;

int n;
int arr[1000001];

int main(){ 
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    long long minimum_1;
    int count_1;
    long long  best_minimum_total;
    int best_minimum_count;
    int min_index = n-2;
    minimum_1 = arr[n-1] + arr[n-2];
    best_minimum_total = arr[n-1] + arr[n-2];
    count_1 = 2;
    best_minimum_count = 2;
    if(n == 2){
        cout << 0;
    }
    else{
        for(int i=n-3;i>=0;i--){
            if(((minimum_1 + arr[i]) * 2) < ((arr[i] + arr[i+1]) * (count_1 + 1))){
                // 이전거에 합치는게 더 최소인경우
                minimum_1 = minimum_1 + arr[i];
                count_1++;
            }
            else{
                // 2개 합치는게 더 최소인 경우
                minimum_1 = arr[i] + arr[i+1];
                count_1 = 2;
                
            }
            if(best_minimum_total * count_1 >= minimum_1 * best_minimum_count){
                // 현재까지중 가장 최소일 경우
                best_minimum_total = minimum_1;
                best_minimum_count = count_1;
                min_index = i;
            }
        }
        cout << min_index;
    }
}

