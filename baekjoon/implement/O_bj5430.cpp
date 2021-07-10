/*/////////////////////////////////////////////////////////////////////////
날짜 : 2021.06.26

소요시간 : 40m

문제명 - 백준 5430 AC
   
알고리즘
    - 구현

문제개요
    정수의 배열이 주어지고, R,D로 이루어진 명령어가 주어진다
    (ex RDD, RRDD 등..)

    R : 주어진 배열 리버스(뒤집기)
    D : 주어진 배열의 맨 앞 정수 삭제

    주어진 배열을 주어진 명령어로 실행했을때 최종 배열의 결과값 출력하기.

    주어질 배열과 명렁어의 원소개수가 최대 10만씩이므로 R이 10만번 주어질시에 실제로 배열을 리버스
    해버리면 시간초과가 되므로, 배열의 시작인덱스와 마지막인덱스를 변수로 관리하여 리버스시 두 변수값
    만 바꾸는 방식으로 구현.

    추가로 원소 삭제(D연산)의 경우도 실제로 배열에서 삭제하지 않고 인덱스를 ++ 시켜서 구현
    (리버스된 배열의 경우에는 마지막인덱스에서 --연산 수행)

*//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

string order;
string inputInt;
int input[100001];
int t;
string tmp;
int cot;
int st,ed;
int maxi;

void func(){
    bool straght = true;
    for(int now=0;now<order.size();now++){
        if(straght){ // 정방향일때
            if(order[now] == 'R'){
                straght = false;
            }
            else{
                if(ed+2 == st){
                    cout << "error" << '\n';
                    return;
                }
                else{
                    st++;
                }
            }
            
        }
        else{ // 역방향일때
            if(order[now] == 'R'){
                straght = true;
            }
            else{
                if(ed+2 == st){
                    cout << "error" << '\n';
                    return;
                }
                else{
                    ed--;
                }
            }
        }
    }
    if(ed+2 == st){
        cout << "error" << '\n';
        return;
    }
    if(ed+1 == st){
        cout << "[]" << '\n';
        return;
    }
    bool first = true;
    int start,end,var;
    if(straght){
        start = st;
        end = ed;
        var = 1;
        cout << "[";
        for(int k=start;k<=end;){
            if(first){
                first = false;
            }
            else{
                cout << ",";
            }
            cout << input[k];
            k = k+var;
        }
        cout << "]";
    }
    else{
        start = ed;
        end = st;
        var = -1;
        cout << "[";
        for(int k=start;k>=end;){
            if(first){
                first = false;
            }
            else{
                cout << ",";
            }
            cout << input[k];
            k = k+var;
        }
        cout << "]";
    }
    cout << '\n';
    return;
}

int main(){
    cin >> t;
    for(int p=0;p<t;p++){
        cin >> order;
        cin >> maxi;
        cin >> inputInt;
        tmp = "";
        cot = 0;
        if(inputInt.size() > 2){
            for(int i=1;i<inputInt.size();i++){
                if(inputInt[i] == ',' || i == inputInt.size()-1){
                    input[cot] = stoi(tmp);
                    tmp = "";
                    cot++;
                }
                else{
                    tmp.append(1,inputInt[i]);
                }
            }
        }
        st = 0;
        ed = maxi-1;
        func();

        // for(int j=0;j<ed;j++){
        //     cout << input[j] << ", ";
        // }
        // cout << endl << "-----------------" << endl;
    }
}