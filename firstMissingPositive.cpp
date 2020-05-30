// https://leetcode.com/problems/first-missing-positive/

// Mathematics solution; ad-hoc

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int *n = new int[nums.size() + 1];
        for (int i = 0; i < nums.size() + 1; i++) 
            n[i] = 1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= nums.size() + 1 && nums[i] > 0)
                n[nums[i] - 1] = -100000000;
        for (int i = 0; i < nums.size() + 1; i++) 
            if (n[i] != -100000000) 
                return i + 1;
    }
};
