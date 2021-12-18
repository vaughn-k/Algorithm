/*
13m

점화식 d[i] = d[i-1] + d[i-2] + d[i-3]으로 해결할수있었다.
다만 답이 매우 커져서 10억으로 나누는 부분이 있는데 각각의 결과를 int형에 저장해서 최대 21억까지만
담을 수 있어 만약 더할 3개의 숫자가 합이 21억이 넘는다면 원하는 결과가 나오지않는다.
따라서 최소 3개를 더했을때 30억이상이 담겨야 하므로 unsigned를 붙여 0~42억까지 담을수 있게
설계하였다.

*/

#include <iostream>

using namespace std;

unsigned int arr[4];
int t,n;
int main(){
    cin >> t;
    while(t>0){
        cin >> n;
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 4;
        if(n <= 2){
            cout << n << endl;
        }
        else if(n == 3){
            cout << "4" << endl;
        }
        else{
            for(int i=0;i<(n-3);i++){
                arr[3] = (arr[0] + arr[1] + arr[2])%1000000009;
                arr[0] = arr[1];
                arr[1] = arr[2];
                arr[2] = arr[3];
            }
            cout << arr[3] << endl;
        }
        t--;
    }
}