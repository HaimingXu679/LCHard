// https://leetcode.com/problems/longest-valid-parentheses/

// Altered knapsack algorithm

class Solution {
public:
    int knap(string &s, int value, int l, bool skip, int i) {
        if (i == s.length() || value > s.length() / 2 || value < -1 * s.length() / 2)
            return value == 0 ? l : 0;
        if (value == 0)
            return s[i] == ')' ? (!skip ? max(l, knap(s, 0, l, skip, i + 1)) : l) : max(l, !skip ? 
                        max(knap(s, 1, l + 1, 1, i + 1), knap(s, 0, l, 0, i + 1)) : knap(s, 1, l + 1, 1, i + 1));
        return s[i] == ')' ? knap(s, value - 1, l + 1, 1, i + 1) : knap(s, value + 1, l + 1, 1, i + 1);
    }
    
    int longestValidParentheses(string s) {
        return s.find('(') != string::npos && s.find(')') != string::npos ? knap(s, 0, 0, 0, 0) : 0;
    }
};
