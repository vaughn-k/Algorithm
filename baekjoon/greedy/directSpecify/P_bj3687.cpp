/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.09.22

소요시간 : 1h 10m

문제명 - 백준 3687 성냥깨비

알고리즘
    - greedy
    - 이게 왜 dp에 분류되어 있는지?

문제개요
    
    n개의 성냥깨비를 이용해서 가장 작은수와 가장큰수를 출력

    - 가장 큰 수
    주어진 성냥깨비로 가장 큰 수를 만들어야한다. 먼저 수가 크다는 것은 첫번째로 자릿수가 커야하고
    그다음으로 같은 자릿수에서 앞자리부터 숫자가 커야한다.

    가장 숫자를 길게 만드려면 성냥깨비가 적게드는 "1"을 많이 만드는 것이 이득이다.
    그러나 성냥깨비가 짝수일때는 "1"을 n/2개 만들 수 있지만, 홀수일때는 부득이하게 3개를 이용해서
    만들수 있는 가장 큰 숫자인 "7"을 만들어야하므로
    
    홀수일때는 7111... 이런식으로 만들고
    짝수일때는 1111... 이런식으로 만들면 될것이다.

    - 가장 작은 수
    가장 작은 수를 만들기 위해서는 먼저 자릿수가 작아야한다. 그러기 위해서는 주어진 성냥깨비로 만들
    수 있는 자릿수 중 가장 작은 자릿수를 알아내야한다. 

    성냥깨비로 만들수 있는 숫자는 총 10개이고 소요되는 성냥깨비 숫자는 2~7개 이다.
    따라서 7개를 기준으로 자릿수가 결정된다.
    만약 성냥깨비가 23개라면 7/7/7/2 이런식으로 4개가 필요하고 이것은 n을 7로 나눈값과 나머지
    유무를 통해 도출해 낼 수 있다. (find_min_length 함수 참고)

    이후 최소 자릿수를 구했다면 이제 최소 수를 구할 차례이다.

    성냥깨비로 만들 수 있는 숫자별로 우선순위가 다르다.

    성냥깨비 5개로 만들수 있는 수는 2,3,5이고, 6개로 만들수 있는 수는 0,6,9이다.
    전자의 경우 greedy적으로 접근했을 때 같은 5개로 작게 만들거면 2를 두고 3,5를 사용할 필요는
    없어보인다.

    마찬가지로 후자의 경우도 6,9보다는 0을 사용해야 할 것인데, 여기서 중요한 점은 첫째자리수에는
    0이 올 수 없다는 것이다. 따라서 현재 첫째자리에 배치중이라면 0은 제외하고 고려해야하며, 그
    경우에는 6을 사용하는 것도 최소를 만드는것이 될 수 있으므로 전자에서 3,5를 모두 제외한 것과는
    다르게 후자에서는 0과 6모두 포함해야한다.

    우선순위 표
    필요한 성냥깨비 수 : 6 -> 2 -> 5 -> 4 -> 6 -> 3 -> 7    
    실제 숫자        : 0 -> 1 -> 2 -> 4 -> 6 -> 7 -> 8
    
    또한 현재 어떤 숫자를 만든다고 했을 때 해당 숫자를 만들었을 때 처음에 구했던 최소 길이를 넘
    도록 만드는 숫자를 골라서는 안된다.

    예를들어 n값으로 k라는 최소자릿수를 구했는데
    p라는 숫자를 만들었을 때 이후에 남은 성냥개비 개수를 계산해보니 k+1이라는 자릿수가 나올수밖에
    없어진다면, 오히려 숫자가 늘어나므로 그것을 제한해야한다.


*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t,n;
int seq_count[] = {6,2,5,4,6,3,7};
char seq_value[] = {'0','1','2','4','6','7','8'};
vector<int> v;

int find_min_length(int k){
    if(k%7 == 0){
        return k/7;
    }
    else{
        return k/7+1;
    }
}

string find_min(){
    int length = find_min_length(n);
    int left = n;
    bool first = true;
    string answer = "";
    while(left >= 1){
        for(int i=0;i<7;i++){
            if((answer.size()+1+find_min_length(left-seq_count[i])) <= length){
                if(!(i == 0 && first)){
                    answer = answer + seq_value[i];
                    left = left - seq_count[i];
                    break;
                }
            }
        }
        first = false;
    }
    return answer;
}

string find_max(){
    string output;
    int sub = n;
    // 홀수일 때
    if(n%2 == 1){
        output  = "7";
        sub = sub - 3;
    }
    else{
        output = "1";
        sub = sub - 2;
    }
    for(int i=0;i<(sub/2);i++){
        output = output + '1';
    }
    return output;
}

int main(){
    int ans;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        v.push_back(n);
    }
    for(int i=0;i<t;i++){
        n = v[i];
        cout << find_min() << " " << find_max() << '\n';
    }
}