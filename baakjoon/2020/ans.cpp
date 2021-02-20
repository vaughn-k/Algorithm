#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;
 
const int MAX = 50;
const int INF = 987654321;
 
int N;
int arr[MAX];
//모든 조각의 높이의 합은 500,000을 넘지 않고 탑은 두개
int cache[MAX][500000 / 2 + 1]; //idx, height Difference
 
int maxHeight(int idx, int heightDiff)
{
        //기저 사례: 높이 차 초과, 높이가 같지 않은 상태에서 범위 초과
        if (heightDiff > 500000 / 2)
                 return -INF;
        if (idx == N && heightDiff)
                 return -INF;
       
        //높이가 동일하다면 조건 충족
        if (idx == N && heightDiff == 0)
                 return 0;
 
        int &result = cache[idx][heightDiff];
        if (result != -1)
                 return result;
 
        result = -INF;
        //idx 번쨰 조각을 쓰지 않음
        result = max(result, maxHeight(idx + 1, heightDiff));
        //idx 번째 조각을 높은 탑에 배치
        result = max(result, maxHeight(idx + 1, heightDiff + arr[idx]));
        //idx 번째 조각을 낮은 탑에 배치
        //해당 조각이 두 탑의 높이 차보다 큰 경우
        if (arr[idx] > heightDiff)
                 result = max(result, heightDiff + maxHeight(idx + 1, arr[idx] - heightDiff));
        //idx 번째 조각이 두 탑 높이 차보다 작거나 같은 경우
        else
                 result = max(result, arr[idx] + maxHeight(idx + 1, heightDiff - arr[idx]));
        return result;
}
 
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 속도 향상
        cin >> N;
 
        for (int i = 0; i < N; i++)
                 cin >> arr[i];
 
        memset(cache, -1, sizeof(cache));
        int result = maxHeight(0, 0);
       
        if (result)
                 cout << result << "\n";
        else
                 cout << -1 << "\n";
        return 0;
}