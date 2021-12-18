/*/////////////////////////////////////////////////////////////////////////

날짜 : 2021.05.27

소요시간 : 15m

문제명 - 백준 10816 숫자카드
   
알고리즘
    - hash

문제개요
    전형적인 hash를 사용하는 문제였는데 계속 시간초과가 발생하였다.

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    위 코드로 해결

*//////////////////////////////////////////////////////////////////////////


#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;



// map 정의
map <int, int> cards;

int n,m;
vector<int> input;
int output[500000];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        input.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> output[i];
    }
    sort(input.begin(),input.end());
    int origin;
    bool haveNum = false;
    int now;
    int count = 0;
    // 맵에 원소 추가
    for(int i=0;i<n;i++){
        if(haveNum){ // 이미 선택된 숫자 있을 때
            if(now == input[i]){ // 이전과 동일
                count++;
                if(i == n-1){ // 만약 마지막 원소라면 바로 추가해준다.
                    cards.insert(pair<int,int>(now,count));
                }
            }
            else{ // 이전과 다름 -> 저장해야함
                cards.insert(pair<int,int>(now,count));
                // 그리고 새로 추가
                now = input[i];
                count = 1;
            }
        }
        else{ // 처음진입
            now = input[i];
            count = 1;
            haveNum = true;
        }
    }
    
    // 맵과 비교
    for(int i=0;i<m;i++){
        if(cards.find(output[i]) == cards.end()){ // 존재하지 않을 때 
            cout << 0 << " ";
        }
        else{ // 존재할때
            origin = cards.find(output[i])->second;
            cout << origin << " ";
        }
    }
}