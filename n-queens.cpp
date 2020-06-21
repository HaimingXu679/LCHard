// https://leetcode.com/problems/n-queens/

// Classic backtracking... should be LC medium

// O(N!)

class Solution {
public:
    vector<vector<string> > ans;
    
    void helper(set<pair<int, int> > queens, int col, int n) {
        set<pair<int, int> >::iterator it;
        if (queens.size() == n) {
            vector<string> board;
            for (int i = 0; i < n; i++) {  
                string temp(n, '.');
                for (it = queens.begin(); it != queens.end(); it++) {
                    if (it -> first == i)
                        temp[it -> second] = 'Q';
                }
                board.push_back(temp);
            }
            ans.push_back(board);
        } else {
            for (int i = 0; i < n; i++) {
                for (it = queens.begin(); it != queens.end(); it++)
                    if (it -> first == i || abs(it -> first - i) == abs(it -> second - col))
                        break;
                if (it != queens.end())
                    continue;
                queens.insert(make_pair(i, col));
                helper(queens, col + 1, n);
                queens.erase(make_pair(i, col));
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        helper(set<pair<int, int> >(), 0, n);
        return ans; 
    }
};
