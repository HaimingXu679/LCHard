// https://leetcode.com/problems/minimum-window-substring/

// Two pointers, deque

// O(N), faster than 50%

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> required;
        unordered_set<char> seen;
        deque<char> window;
        int i = 0, j = 0;
        for (char c : t)
            required[c]++;
        string ans = "";
        while (j < s.size() || seen.size() >= required.size()) {
            if (seen.size() < required.size()) {
                window.push_back(s[j]);
                if (required.find(s[j]) != required.end() && --required[s[j]] <= 0)
                    seen.insert(s[j]);
                j++;
            } else {
                char temp = window.front();
                window.pop_front();
                if (required.find(temp) != required.end() && ++required[temp] > 0)          
                    seen.erase(temp);
                i++;
            }
            if (seen.size() == required.size() && (ans.size() > j - i || ans == ""))
                    ans = s.substr(i, j - i);
        }
        return ans;
    }
};
