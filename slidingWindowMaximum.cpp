// https://leetcode.com/problems/sliding-window-maximum/

// Easy deque solution

// O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();
            window.push_back(i);
            while (!window.empty() && window.front() + k <= i)
                window.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};
