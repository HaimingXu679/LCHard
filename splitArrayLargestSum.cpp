// https://leetcode.com/problems/split-array-largest-sum/

// Dynamic programming

// O(N^2 * M), faster than 26%

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long dp[nums.size()][m], accumulator = 0, postfix[nums.size()];
        for (int i = nums.size() - 1; i >= 0; i--) {
            postfix[i] = accumulator += nums[i];
            for (int j = 0; j < m; j++)
                dp[i][j] = j == 0 ? accumulator : 0x7fffffff;
        }
        for (int i = nums.size() - 2; i >= 0; i--)
            for (int j = 1; j < m; j++)
                for (int k = i + 1; k < nums.size(); k++)
                    dp[i][j] = min(dp[i][j], max(postfix[i] - postfix[k], dp[k][j - 1]));
        return dp[0][m - 1];
    }
};
