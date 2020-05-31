// https://leetcode.com/problems/trapping-rain-water/

// Mathematics solution; ad-hoc

// O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, temp = 0, biggest = height.size() > 0 ? height[0] : -1;
        int *right = new int[height.size()];
        for (int i = height.size() - 1; i >= 0; i--) {
            right[i] = 0;
            if (i != height.size() - 1)
                right[i] = max(height[i + 1], right[i + 1]);
        }
        for (int i = 1; i < height.size() == 0 ? 0 : height.size() - 1; i++) {
            ans += min(biggest, right[i]) - height[i] >= 0 ? min(biggest, right[i]) - height[i] : 0;
            biggest = max(biggest, height[i]);
        }
        return ans;
    }
};
