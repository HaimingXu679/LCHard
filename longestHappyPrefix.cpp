// https://leetcode.com/problems/longest-happy-prefix/

// Use of string_view; creates substrings in constant time

// O(N)

class Solution {
public:
    string longestPrefix(string s) {
        string_view front = s, back = s;
        int index = -1;
        for (int i = 0; i < s.size() - 1; i++)
            if (front.substr(0, i + 1) == back.substr(s.size() - i - 1, i + 1))
                index = i + 1;
        return index == -1 ? "" : string(front.substr(0, index));
    }
};
