// https://leetcode.com/problems/dungeon-game/description/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int dp[dungeon.size()][dungeon[0].size()];
        for (int i = 0; i < dungeon.size(); i++) for (int j = 0; j < dungeon[i].size(); j++) dp[i][j] = 0x7ffffff;
        dp[dungeon.size() - 1][dungeon[0].size() - 1] = dungeon[dungeon.size() - 1][dungeon[0].size() - 1] > 0 ? 1 : -1 * dungeon[dungeon.size() - 1][dungeon[0].size() - 1] + 1;
        for (int i = dungeon.size() - 1; i >= 0; i--) {
            for (int j = dungeon[0].size() - 1; j >= 0; j--) {
                if (i + 1 < dungeon.size()) dp[i][j] = max(1, dp[i + 1][j] - dungeon[i][j]);
                if (j + 1 < dungeon[0].size()) dp[i][j] = min(dp[i][j], max(1, dp[i][j + 1] - dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};
