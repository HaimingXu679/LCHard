// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i,j;
        int *n=new int[nums.size()+1];
        for (i=0;i<nums.size()+1;i++) n[i]=1;
        for (i=0;i<nums.size();i++)
            if (nums[i]<=nums.size()+1 && nums[i]>0)
                n[nums[i]-1]=-100000000;
        for (i=0;i<nums.size()+1;i++) cout << n[i] << endl;
        for (i=0;i<nums.size()+1;i++) if (n[i]!=-100000000) return i+1;
    }
};
