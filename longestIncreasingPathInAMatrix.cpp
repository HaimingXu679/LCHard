// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// Dynamic programming solution

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int **ans = new int*[matrix.size()], largest = 0, counter = 0, iter = 0;
        for (int i = 0; i < matrix.size(); i++)
            ans[i] = new int[matrix[0].size()];
        do {
            for (int i = counter = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    int temp = ans[i][j] = iter == 0 ? 1 : ans[i][j];
                    if (i > 0 && matrix[i - 1][j] > matrix[i][j])
                        ans[i][j] = max(ans[i][j], iter == 0 ? 2 : ans[i - 1][j] + 1);
                    if (j > 0 && matrix[i][j - 1] > matrix[i][j])
                        ans[i][j] = max(ans[i][j], iter == 0 ? 2 : ans[i][j - 1] + 1);
                    if (j < matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j])
                        ans[i][j] = max(ans[i][j], iter == 0 ? 2 : ans[i][j + 1] + 1);
                    if (i < matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j])
                        ans[i][j] = max(ans[i][j], iter == 0 ? 2 : ans[i + 1][j] + 1);
                    counter = ans[i][j] - temp > 0 ? counter + 1 : counter;
                    largest = max(largest, ans[i][j]);
                }
            }
            iter++;
        } while (counter > 0);
        return largest;
    }
};
