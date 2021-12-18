/*/////////////////////////////////////////////////////////////////////////

날짜 : 2021.05.27

소요시간 : 12m

문제명 - 백준 1620 나는야 포켓몬 마스터 이다솜
   
알고리즘
    - hash

문제개요
    hash테이블 2개 or hash테이블 + string 배열을 이용해서
    이름+id로 구성된 테이블에서 이름입력시 id를, id입력시 이름을 출력

*//////////////////////////////////////////////////////////////////////////


#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

// map 정의
map <string, int> pkm_name;
map <int, string> pkm_num;

int n,m;
string input[100000];
string output[100000];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int tmp;
    cin >> n;
    cin >> m;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    for(int i=0;i<m;i++){
        cin >> output[i];
    }
 
    // 맵에 원소 추가
    for(int i=0;i<n;i++){
        pkm_num.insert(pair<int,string>(i+1,input[i]));
        pkm_name.insert(pair<string,int>(input[i],i+1));
    }
    
    // 맵과 비교 숫자(0 ~ 9 : 48 ~ 57)
    for(int i=0;i<m;i++){
        tmp = output[i][0];
        if(tmp >= 48 && tmp <= 57){ // 숫자일때
            cout << pkm_num.find(stoi(output[i]))->second << '\n';
        }
        else{ // 문자일때
            cout << pkm_name.find(output[i])->second << '\n';
        }
    }
}