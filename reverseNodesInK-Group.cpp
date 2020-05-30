// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c = k;
        ListNode *curr = head, *prev = NULL, *next = NULL, *temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp -> next;
        }
        while (curr != NULL && c > 0) {
            next = curr -> next;
            if (c != k)
                curr -> next = prev;
            else
                curr -> next = reverseKGroup(temp, k);
            prev = curr;
            curr = next;
            c--;
        }
        head = prev;
        return head;
    }
};
