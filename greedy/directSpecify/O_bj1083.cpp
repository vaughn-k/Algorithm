/*/////////////////////////////////////////////////////////////////////////
소요시간 : 30m

문제명 - 백준 1083 - 소트

알고리즘
    - 그리디

문제개요
    N개의 서로다른 숫자들의 배열이 주어지고, S만큼 연속된 두 숫자를 교환할 수 있을 때, 가장 사전
    순으로 뒷서게 하는 배열 출력

    사전순으로 정렬하는 문제는 일단 사전순이라는 것이 맨 앞의 값부터 확인하는 것이기 때문에 현재 내
    가 맨 앞에 배치할 수 있는 숫자 중 가장 큰 숫자를 배치해야 사전순으로 가장 뒷서게 된다.

    교환할 수 있는 횟수의 최대값은 S이므로 0번 인덱스부터 S번 인덱스(N보다 클 경우 N번 인덱스)
    중 가장 큰 값을 찾아 맨 앞으로 보내고, 0번 인덱스와 가장 큰 값의 인덱스만큼 S를 차감한다.

    이후 1번 인덱스부터 이전의 과정을 반복하면 될것이다.

    단, k번째에서 가장 큰 수가 발견되었을 때 start지점부터 k까지 원소들을 swap해 주어야하는데
    여기서 시간복잡도를 고려했을 때 N 최대값이 50이므로 50(49)/2 약 1250회 이하 이므로 가능하다.
    
*///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int n,s;
vector<int> v;

int action(int start, int left){
    // v배열에 인덱스가 start ~ start+left 까지 중 가장 큰 숫자를 start 인덱스와 교환하고
    // 남은 교환횟수 출력
    int end,maxi_value,maxi_index;
    maxi_value = -1;
    maxi_index;
    end = min(start+left,n-1);
    for(int index=start;index<=end;index++){
        if(maxi_value < v[index]){
            maxi_value = v[index];
            maxi_index = index;
        }
    }
    // maxi값과 start 값 교환
    if(maxi_index != start){
        for(int i=maxi_index;i>start;i--){
            v[i] = v[i-1];
        }
        v[start] = maxi_value;
    } 

    return maxi_index-start;
}

void loop(){
    int left = s;
    int output;
    int start = 0;
    while(left > 0 && start < (n-1)){
        output = action(start,left);
        left = left - output;

        start++;
    }
}

int main(){
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> s;
    loop();
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}

/*

20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
100000

*/