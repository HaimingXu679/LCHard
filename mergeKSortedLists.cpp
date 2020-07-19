// https://leetcode.com/problems/merge-k-sorted-lists/

// Simple heap solution (faster than 80%)

// O(NlogN)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:    
    ListNode* createAns(multiset<int> &nums) {
        if (nums.empty())
            return NULL;
        ListNode *ans = new ListNode();
        ans -> val = *nums.begin();
        nums.erase(nums.begin());
        ans -> next = createAns(nums);
        return ans;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> nums;
        for (int i = 0; i < lists.size(); i++)
            for (; lists[i] != NULL; lists[i] = lists[i] -> next)
                nums.insert(lists[i] -> val);
        return createAns(nums);
    }
};
