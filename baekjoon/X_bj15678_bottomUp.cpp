/*/////////////////////////////////////////////////////////////////////////
소요시간 : 1h 4m

문제명 - 백준 15678 - 연세워터파크
   
알고리즘
    - 우선순위큐 2개 전달형
    - 슬라이딩윈도우
    - 그리디

문제개요
    n개의 징검다리가 있고 각 징검다리마다 점수가 있다.
    이때 시작지점은 아무곳이나 상관없고 항상 d칸이내로만 움직여야하며, 한번 방문한 칸에는 다시 
    갈수 없을때 최대로 얻을 수 있는 점수는?

    1. dfs 접근 
    dfs로 메모이제이션 해가면서 한다면 될것같았지만 시간초과가 났다.

    2. bottom up 접근
    아하, 재귀호출이 많아져서 시간초과가 난것같았다. 그래서 bottom up으로 설계하였다.
    그러나 또 시간초과가 났다.
    시간복잡도를 계산해보니 d=n-1 일때 최악이며 n(n-1)/2 로 O(N^2) 이였다.
    다른 방법이 필요해보였다.

    3. 그리디 접근
    위의 bottom up 접근법에서처럼 ans[i] 를 i번째를 시작으로 오른쪽으로 진행할때 가장 큰 값
    이라고 정의할 때,
    i=n-1 일때부터 모든 값을 구해서 i=0이 되었다고 생각해보자.

    이때 통상적인 방법으로는 i=1일때부터 n-1 일때까지 중 가장 큰 수를 찾아야 할것이다.
    이과정에서 n-1 번 탐색을 해야했고 이것을 줄여야했다.

    그래서 우선순위큐를 이용해 현재 가능한 돌다리중 가장 최대값을 항상 내뿜는 방법을 사용하면 될것
    같았다.

    그런데 이때 주의해야할 부분이 하나있었다.
    만약 현재 돌다리가 k번째이고 k+1 ~ k+d돌다리 까지 중 가장 높은 점수의 돌다리가 k+p 돌다리
    라고 해보자.

    그런 상황일때 새로 pq에 값을 추가할때 현재 돌다리에 해당값을 더한값을 넣게될것인데, 이때 기존에
    최대값이던 돌다리는 삭제해야하는가 그대로 두어야하는가?

    답은 그대로 두어야 한다.

    더 엄밀하게 말하자면, 현재돌다리값이 양수라면 삭제해도 무방하지만, 음수라면 두어야한다.

    음수일때 두어야 하는 이유는 
    10 -5 -5 -5 100 (d=4)
    이 경우에 최고점수는 모든 돌다리를 다 밟았을 때이다.
    만약 이상태에서 삭제하는 방법을 사용한다면 최대값이 95 90 85로 계속 떨어져 결국 10을더해
    95라는 답을 도출해낼것이다.

    삭제하지 않는 이유는 p라는 돌다리가 q라는 돌다리를 선택했을때, 이후에 r이라는 돌다리가 d값에 
    의해 p만 선택해야 할수도 있지만, p,q모두 선택가능할수도 있기때문에 굳이 p가 q를 고른 선택에
    따를 필요는 없다.
    q만 고르는것이 p,q 모두 고르는것 보다 높은 점수일수 있기 때문이다.
    그러나 p의 입장에선 q를 고르는것이 최선의 선택이였을 수 있기때문에 맹목적으로 p의 선택에 의존
    해서는 안된다.
    그래서 q라는 값 자체를 p에서 사용했다고 해서 삭제해서는 안된다.

    어떤 Elem이 삭제되는 경우는 단 한가지 이다. 현재 d값의 범위를 넘어서서 더이상 해당 돌다리로
    부터 시작할 수 없게될때 그때 bag로 보내는것이다.

    

*//////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Elem{
    int index;
    long long w;
};

struct cmp{
    bool operator()(Elem a, Elem b){
        return a.w < b.w;
    }
};

priority_queue<Elem, vector<Elem>, cmp> pq;
priority_queue<Elem, vector<Elem>, cmp> bag;

int n,d;
int input[100001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> d;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    Elem elem;
    for(int i=(n-1);i>=0;i--){
        if(pq.size() == 0){
            elem.index = i;
            elem.w = input[i];
            pq.push(elem);
        }
        else{
            while(pq.top().index > (i+d)){
                elem = pq.top();
                bag.push(elem);
                pq.pop();
            }
            if(pq.top().w < 0){ // 오른쪽으로 더 가는것보다 그냥 현재자신이 더 클때
                elem.index = i;
                elem.w = input[i];
            }
            else{
                elem.index = i;
                elem.w = input[i] + pq.top().w;
            }
            pq.push(elem);
        }
    }
    if(bag.size() == 0){
        cout << pq.top().w;
    }
    else{
        if(pq.top().w < bag.top().w){
            cout << bag.top().w;
        }
        else{
            cout << pq.top().w;
        }
    }
}   

/*

6 2
-10 -10 -10 -10 -10 1

*/

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// struct Elem{
//     int index;
//     int w;
// };

// struct cmp{
//     bool operator()(Elem a, Elem b){
//         return a.w < b.w;
//     }
// };

// priority_queue<Elem, vector<Elem>, cmp> pq;
// priority_queue<Elem, vector<Elem>, cmp> bag;

// int n,d;
// int input[100001];

// int main(){
//     ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
//     cin >> n >> d;
//     int tmp;
//     for(int i=0;i<n;i++){
//         cin >> input[i];
//     }
//     Elem elem;
//     long long answer = -1000000000ll;
//     for(int i=(n-1);i>=0;i--){
//         // cout << "i : " << i << " | size : " << pq.size() << endl;
//         if(pq.size() == 0){
//             elem.index = i;
//             elem.w = input[i];
//             pq.push(elem);
//         }
//         else{
//             while(pq.top().index > (i+d)){
//                 elem = pq.top();
//                 bag.push(elem);
//                 pq.pop();
//             }
//             if(pq.top().w < 0){ // 오른쪽으로 더 가는것보다 그냥 현재자신이 더 클때
//                 elem.index = i;
//                 elem.w = input[i];
//             }
//             else{
//                 elem.index = i;
//                 elem.w = input[i] + pq.top().w;
//                 // pq.pop();
//             }
//             pq.push(elem);
//         }
//     }
//     if(bag.size() == 0){
//         cout << pq.top().w;
//     }
//     else{
//         if(pq.top().w < bag.top().w){
//             cout << bag.top().w;
//         }
//         else{
//             cout << pq.top().w;
//         }
//     }
// }   


// // int n,d;
// // int input[100001];
// // long long maxi[100001]; // i번째를 시작으로 오른쪽으로 진행할때 얻을수있는 최대점수

// // int main(){
// //     ios_base::sync_with_stdio(false);
// // 	cin.tie(NULL);
// //     cin >> n >> d;
// //     int tmp;
// //     for(int i=0;i<n;i++){
// //         cin >> input[i];
// //         maxi[i] = -1000000000ll;
// //     }
    
// //     long long answer = -1000000000ll;
// //     for(int i=(n-1);i>=0;i--){
// //         maxi[i] = input[i];
// //         if((n-1-i) <= d){
// //             for(int j=(i+1);j<n;j++){
// //                 if(maxi[i] < (input[i] + maxi[j])){
// //                     maxi[i] = input[i] + maxi[j];
// //                 }
// //             }
// //         }
// //         else{
// //             for(int j=(i+1);j<=(i+d);j++){
// //                 if(maxi[i] < (input[i] + maxi[j])){
// //                     maxi[i] = input[i] + maxi[j];
// //                 }
// //             }
// //         }
// //         if(answer < maxi[i]){
// //             answer = maxi[i];
// //         }
// //     }
// //     cout << answer;
// // }   

