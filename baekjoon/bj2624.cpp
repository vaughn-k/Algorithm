/*
45m

- 이전의 2293 동전문제랑 비슷하다.

그러나 이전 2293번 문제는 각 동전의개수가 무한이였지만
해당 문제에서는 사용할수 있는 동전의 개수가 제한되어있었다.

그래서 이전 문제에서는 store[price][1] 을 구할때 store[price - 액면가][1] 로
한번에 구할수 있었지만, 이문제의 경우 동전의 개수만큼만 순회해서 store[price - 액면가 * i][0] (0 <= i  <= 동전개수) 들의 합으로 구해야했다.

*/

#include <iostream>

using namespace std;

int t,k;
int coin_value[101];
int coin_count[101];
int store[10001][2];

int main(){
    cin >> t;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> coin_value[i];
        cin >> coin_count[i];
    }

    store[0][0] = 1;
    store[0][1] = 1;
    int loop;
    for(int index = 0; index < k; index++){
        for(int price = 1; price <= t; price++){
            if(index == 0){
                if(price % coin_value[index] == 0 && 
                    price / coin_value[index] <= coin_count[index]){
                    store[price][1] = 1;
                }
                else{
                    store[price][1] = 0;
                }
            }
            else{
                if(coin_value[index] > price){
                    store[price][1] = store[price][0];
                }
                else if(coin_value[index] == price){
                    store[price][1] = store[price][0] + 1;
                }
                else{
                    loop = 0;
                    while(loop <= coin_count[index] && (price - coin_value[index] * loop) >= 0){
                        store[price][1] = 
                        store[price][1] 
                        + store[price - coin_value[index] * loop][0];
                        loop++;
                    }
                }
            }
        }
        for(int s=1 ; s<=t ; s++){
            store[s][0] = store[s][1];
            store[s][1] = 0;
        }
    }

    cout << store[t][0];
}