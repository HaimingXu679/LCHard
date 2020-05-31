// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// Dynamic programming solution

// O(k * N^2)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int answer = 0;
        if (prices.size() == 0) 
            return 0;
        if (k < prices.size() / 2) {
            int **arr = new int*[prices.size()];
            for (int i = 0; i < prices.size(); i++)
                arr[i] = new int[k + 1];
            for (int i = 0; i <= k; i++)
                for (int j = 0; j < prices.size(); j++)
                    arr[j][i] = 0;
            for (int i = prices.size() - 2; i >= 0; i--) {
                for (int j = 0; j <= k; j++) {
                    if (j == 0)
                        arr[i][j] = 0;
                    else {
                        for (int l = i + 1; l < prices.size(); l++) {
                            if (l + 1 < prices.size()) 
                                arr[i][j] = max(arr[i][j], prices[l] - prices[i] + arr[l + 1][j - 1]);
                            else
                                arr[i][j] = max(arr[i][j], prices[l] - prices[i]);    
                        }
                        arr[i][j] = max(arr[i][j], arr[i + 1][j]);
                        answer = max(answer, arr[i][j]);
                    }
                }
            }
        } else {
            int *arr = new int[prices.size()];
            for (int i = 0; i < prices.size(); i++)
                arr[i] = 0;
            for (int i = prices.size() - 2; i >= 0; i--) {
                for (int l = i + 1; l < prices.size(); l++) {
                    if (l + 1 < prices.size()) 
                        arr[i] = max(arr[i], prices[l] - prices[i] + arr[l + 1]);
                    else
                        arr[i] = max(arr[i], prices[l] - prices[i]);    
                }
                arr[i] = max(arr[i], arr[i + 1]);
                answer = max(answer, arr[i]);
            }
        }
        return answer;
    }
};
