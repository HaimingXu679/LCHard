// https://leetcode.com/problems/shortest-palindrome/

// Altered version of Manacher's Algorithm

// O(N)

class Solution {
public:
    string shortestPalindrome(string s) {
        vector<char> s1, s2;
        int l = 0, c = 0, r = 0;
        string temp = "#", ans;
        for (int i = 0; i < s.length(); i++)
            temp += s.substr(i, 1) + "#";
        int *p = new int[2 * s.length() + 1], *test = new int[2 * s.length() + 1];
        for (int i = 0; i < temp.length(); i++) test[i] = p[i] = 0;
        for (int i = 1; i < temp.length() - 1; i++) {
            if (r > i) 
                p[i] = min(r - i, p[2 * c - i]);
            while (i - 1 - p[i] >= 0 && i + 1 + p[i] < temp.length() && temp[i + 1 + p[i]] == temp[i - 1 - p[i]])
                p[i]++;
            test[i] = i - p[i] > 1 ? 0 : p[i];
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
        for (int i = 0; i < 2 * s.length() + 1; i++)
            l = test[i] != 0 ? max(l, i + test[i]) : l;
        for (int i = l; i < temp.length(); i++)
            if (temp[i] != '#')
                ans.insert(0, temp.substr(i, 1));
        s.insert(0, ans);
        return s;
    }
};
