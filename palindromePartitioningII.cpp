// https://leetcode.com/problems/palindrome-partitioning-ii/

// Manacher's algorithm, dynamic programming

// O(N^2)

class Solution {
public:
    int minCut(string s) {
        bool **checker = new bool*[s.size()];
        for (int i = 0; i < s.size(); i++)
            checker[i] = new bool[s.size()];
        string copy = "#";
        for (int i = 0; i < s.size(); i++)
            copy += s.substr(i, 1) + "#";
        int *dp = new int[s.size()], *p = new int[copy.size()], right = 0, center = 0;
        for (int i = 0; i < copy.size(); i++)
            p[i] = 0;
        for (int i = 0; i < copy.size(); i++) {
            if (i < right)
                p[i] = min(p[2 * center - i], right - i);
            int j = 1 + p[i];
            while (i + j < copy.size() && i - j >= 0 && copy[i + j] == copy[i - j]) {
                p[i]++;
                j++;
            }
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
        }
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < s.size(); j++)
                checker[i][j] = false;
        for (int i = 0; i < copy.size(); i++)
            for (int j = i % 2 == 0 ? 1 : 0; j <= p[i] / 2; j++)
                checker[(i % 2 == 0 ? i + 1 : i - 1) / 2 - j][(i - 1) / 2 + j] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            dp[i] = 0x7fffffff;
            for (int j = i; j < s.size(); j++) {
                if (checker[i][j]) {
                    if (j == s.size() - 1)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[j + 1] + 1, dp[i]);
                }
            }
        }
        return dp[0];
    }
};
