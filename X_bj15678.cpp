#include <iostream>
#include <vector>

using namespace std;

int n,d;
int input[100001];
long long save[100001];

long long dfs(int index){
    if(index >= n){
        return 0;
    }
    if(save[index] != -1){
        return save[index];
    }
    // index 번째부터 밟고 오른쪽으로 진행했을때 나올수 있는 최대점수
    long long maximum = input[index];
    long long original = input[index];
    long long tmp;
    for(int i=1;i<=d;i++){
        tmp = original + dfs(index+i);
        if(maximum < tmp){
            maximum = tmp;
        }
    }
    save[index] = maximum;
    return maximum;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> d;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> input[i];
        save[i] = -1;
    }
    
    long long answer = -1000000000ll;
    long long tmp2;
    for(int i=0;i<n;i++){
        tmp2 = dfs(i);
        if(answer < tmp2){
            answer = tmp2;
        }
    }
    cout << answer;
}   

