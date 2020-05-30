// https://leetcode.com/problems/freedom-trail/

// Dynamic programming solution

class Solution {
public:
    int abs(int a){
        return a < 0 ? a * -1 : a;
    }

    int smaller(int a, int b){
        return a < b ? a : b;
    }
    
    int findRotateSteps(string ring, string key) {
        int **dp = new int*[key.length() + 1];
        for (int i = 0; i < key.length() + 1; i++) 
            dp[i] = new int[ring.length()];
        for (int i = key.length() - 1; i >= 0; i--){
            for (int j = 0; j < ring.length(); j++){
                dp[i][j] = 0x7fffffff;
                for (int k = 0; k < ring.length(); k++) 
                    if (ring[k] == key[i]) 
                        dp[i][j] = min(dp[i][j],dp[i + 1][k] + smaller(abs(j - k), ring.size() - abs(j - k)));
            }
        }
        return dp[0][0] + key.length();
    }
};
