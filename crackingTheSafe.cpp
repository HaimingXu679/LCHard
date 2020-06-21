// https://leetcode.com/problems/cracking-the-safe/

// Backtracking, DFS

// O(N^k)

class Solution {
public:
    string ans = "";
    set<string> combinations;
    bool terminate = false;
    
    void backtrack(string total, string current, int n, int k) {
        if (combinations.empty()) {
            ans = total;
            terminate = true;
            return;
        }
        if (!terminate) {
            if (current.size() == n) {
                string temp = current.substr(1, current.size() - 1);
                for (int i = 0; i < k; i++) {
                    temp += to_string(i);
                    if (combinations.find(temp) != combinations.end()) {
                        combinations.erase(temp);
                        backtrack(total + to_string(i), temp, n, k);
                        combinations.insert(temp);
                    }
                    temp = temp.substr(0, temp.size() - 1);
                }
            } else {
                for (int i = 0; i < k; i++) {
                    total += to_string(i);
                    if (combinations.find(total) != combinations.end())
                        combinations.erase(total);
                    backtrack(total, total, n, k);
                    combinations.insert(total);
                    total = total.substr(0, total.size() - 1);
                }
            }
        }
    }
    
    void createCombinations(int n, int k, string current) {
        if (current.size() == n) {
            combinations.insert(current);
            return;
        }
        for (int i = 0; i < k; i++) {
            current += to_string(i);
            createCombinations(n, k, current);
            current = current.substr(0, current.size() - 1);
        }
    }
    
    string crackSafe(int n, int k) {
        createCombinations(n, k , "");
        set<string>::iterator it;
        backtrack("", "", n, k);
        return ans;
    }
};
