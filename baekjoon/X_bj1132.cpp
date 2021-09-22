#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;
vector<string> v;
vector<int> alph;
// 65 - 74

int main(){
    int t;
    cin >> n;
    for(int i=0;i<10;i++){
        alph.push_back(0);
    }
    int p;
    for(int i=0;i<n;i++){
        cin >> s;
        p = 1;
        for(int j=(s.size()-1);j>=0;j--){
            t = s[j] - 65;
            alph[t] = alph[t] + p;
            p = p * 10;
        }
    }
    sort(alph.begin(),alph.end());
    int tot = 0;
    for(int i=9;i>=0;i--){
        tot = tot + alph[i] * i;
    }
    cout << tot;
}






#include <iostream>

using namespace std;

int N, M, r, dg, d, tmp;
int arr[1001][1001];

int max(int a, int b) 
{
    if (a > b) return a; return b;
}

int dfs(int n, int m)
{
    if (n == 0 && m == 0)
    {
        return dfs(1, 1) + arr[1][1];
    }

    // No more moves left
    if (n + 1 > N && m + 1 > M)
        return 0;

    // No space downwards, but theres space on the right
    else if (n + 1 > N && m + 1 <= M)
    {
        return dfs(n, m + 1) + arr[n][m+1];
    }

    // No space on the right, but theres space downwards
    else if (n + 1 <= N && m + 1 > M)
    {
        return dfs(n + 1, m) + arr[n+1][m];
    }

    // Theres space downwards and rightwards
    else
    {
        r = dfs(n, m + 1) + arr[n][m+1];
        dg = dfs(n + 1, m + 1) + arr[n+1][m+1];
        d = dfs(n + 1, m) + arr[n+1][m];
        return max(max(r, dg), d);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << dfs(0, 0) << endl;
    return 0;
}