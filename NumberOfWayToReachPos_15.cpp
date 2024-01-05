class Solution {
public:
    vector<vector<long long>> dp;
    const int mod = 1e9 + 7;
    long long solve(int stPos, int endPos, int k) {
        if (k == 0) {
            return (stPos == endPos) ? 1 : 0;
        }
        if (dp[stPos+1000][k] != -1) return dp[stPos+1000][k]%mod;
        long long ways = (solve(stPos + 1, endPos, k - 1) % mod + solve(stPos - 1, endPos, k - 1) % mod) % mod;
        dp[stPos+1000][k] = ways;
        return ways;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        dp.resize(3000, vector<long long>(1002, -1));
        return solve(startPos, endPos, k)%mod;
    }
};
