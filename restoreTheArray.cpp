// https://leetcode.com/problems/restore-the-array/

// Dynamic programming

// O(N), beats 95% (the inner while loop can only loop up to 10 times)

class Solution {
public:
    int numberOfArrays(string s, int k) {
        long long dp[s.size()];
        dp[s.size() - 1] = s[s.size() - 1] == '0' ? 0 : 1;
        for (int i = s.size() - 2; i >= 0; i--) {
            dp[i] = 0;
            if (s[i] != '0') {
                long long temp = (int) s[i] - 48, index = i;
                while (index < s.size() - 1 && temp <= k) {
                    dp[i] = (dp[i] + dp[++index]) % 1000000007;
                    temp = temp * 10 + (int) s[index] - 48;
                }
                dp[i] = temp <= k ? dp[i] + 1 : dp[i];
            }
        }
        return dp[0];
    }
};
