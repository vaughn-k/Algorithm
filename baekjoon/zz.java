// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;

// public class Main_2482_색상환 {
//     public static int n, k;
//     public static int dp[][][];
//     public static int visit[][];
//     public static int mod = 1000000003;

//     public static int[] dfs(int level, int color) {
//         int[] result = new int[2] ;
//         if (level == k) {
//             if (color == n - 1) {
//                 result = new int[]{0, 1};
//                 return dp[level][color] = result.clone();
//             }else{
//                 result = new int[]{1, 0};
//                 return dp[level][color] = result.clone();
//             }
//         }
//         if(visit[level][color] == 1) return dp[level][color];
//         for (int i = color + 2; i <= n - 1; i++) {
//             int[] dfs = dfs(level + 1, i);
//             result[0] += dfs[0] % mod;
//             result[1] += dfs[1] % mod;
//             result[0] %= mod;
//             result[1] %= mod;


//         }
//         visit[level][color] = 1;
//         // if (result[0] < 0 || result[1]< 0) {
//         //     System.out.printf("result[0] : %d , result[1] :  %d\n", result[0],result[1]);
//         // }
//         return dp[level][color] = result.clone();
//     }
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         n = Integer.parseInt(br.readLine());
//         k = Integer.parseInt(br.readLine());
//         dp = new int[k + 1][n][2];
//         visit = new int[k + 1][n];

//         for (int i = 0; i < n; i++) {
//             dfs(1, i);
//         }
//         int sol = 0;
//         for (int i = 0; i < n; i++) {
//             if(i == 0){
//                 sol += dp[1][i][0] % mod;
//             }else{
//                 sol += (dp[1][i][0] + dp[1][i][1])%mod;
//             }
//             sol %= mod;
//         }
//         System.out.println(sol%mod);
//     }
// }ㅇ

// struct A{
//     int tmp1,
//     int tmp2
// };
// // 선언
// A dp[1000][1000];

// // 사용
// A[300][100].tmp1;
// A[300][100].tmp2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static int n, k;
    public static int dp[][][];
    public static int visit[][];
    public static int mod = 1000000003;

    public static void dfs(int level, int color) {
        if (level == k) {
            if (color == n - 1) {
                dp[level][color][1] = 1;
                return;
            }else{
                dp[level][color][0] = 1;
                return;
            }
        }
        if(visit[level][color] == 1) return;
        int[] result = new int[2] ;
        for (int i = color + 2; i <= n - 1; i++) {
            dfs(level + 1, i);
            result[0] += dp[level + 1][i][0] % mod;
            result[1] += dp[level + 1][i][1] % mod;
            result[0] %= mod;
            result[1] %= mod;
        }
        visit[level][color] = 1;
        dp[level][color][0] = result[0];
        dp[level][color][1] = result[1];
        result = null;
        return;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        dp = new int[1001][1000][2];
        visit = new int[1001][1000];

        for (int i = 0; i < n; i++) {
            dfs(1, i);
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            if(i == 0){
                sol += dp[1][i][0] % mod;
            }else{
                sol += (dp[1][i][0] + dp[1][i][1])%mod;
            }
            sol %= mod;
        }
        System.out.println(sol%mod);
    }
}