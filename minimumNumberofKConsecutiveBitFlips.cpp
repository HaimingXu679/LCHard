// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

// Greedy, notice that you flip the first 0 you see

// O(N), faster than 65%

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int counter = 0, right = 0;
        queue<int> influence;
        for (int i = 0; i < A.size(); i++) {
            if (!influence.empty() && influence.front() < i)
                influence.pop();
            if ((A[i] == 0 && influence.size() % 2 == 1) || (A[i] == 1 && influence.size() % 2 == 0))
                continue;
            if (i + K - 1 >= A.size())
                return -1;
            right = i + K - 1;
            influence.push(right);
            counter++;
        }
        return counter;
    }
};
