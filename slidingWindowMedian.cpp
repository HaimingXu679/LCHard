// https://leetcode.com/problems/sliding-window-median/

// Sorted array

// O(NlogN), faster than 34%

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> window, ans;
        for (int i = 0; i < k; i++) window.push_back(nums[i]);
        sort(window.begin(), window.end());
        for (int i = k; ; i++) {
            ans.push_back(k % 2 == 0 ? (window[k / 2] + window[k / 2 - 1]) / 2 : window[k / 2]);
            if (i == nums.size()) break;
            window.erase(lower_bound(window.begin(), window.end(), nums[i - k]));
            window.insert(upper_bound(window.begin(), window.end(), nums[i]), nums[i]);
        }
        return ans;
    }
};
