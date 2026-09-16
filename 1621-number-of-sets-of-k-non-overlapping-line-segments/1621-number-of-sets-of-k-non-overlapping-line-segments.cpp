class Solution {
public:
    int m = 1e9 + 7 ;
    int numberOfSets(int n, int k) {
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int j = 1; j <= k; j++) {
        long long suffix = 0;

        for(int i = n - 1; i >= 0; i--) {

            // suffix = sum of dp[x][j-1] for x > i
            dp[i][j] = (dp[i + 1][j] + suffix) % MOD;

            suffix = (suffix + dp[i][j - 1]) % MOD;
        }
    }

    return dp[0][k];
}
    
};