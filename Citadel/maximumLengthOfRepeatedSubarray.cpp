class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int **dp = new int *[A.size()];
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
            dp[i] = new int[B.size()];
        for (int i = A.size() - 1; i >= 0; i--) {
            for (int j = B.size() - 1; j >= 0; j--) {
                if (A[i] == B[j]) {
                    dp[i][j] = i == A.size() - 1 || j == B.size() - 1 ? 1 : max(1, 1 + dp[i + 1][j + 1]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
