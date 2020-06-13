// https://leetcode.com/problems/word-search-ii/ 

// Backtracking, DFS, Trie 

// O(N ^ 3)

class Solution {
public:
    set<string> found;
    
    void dfs(vector<vector<char>>& board, set<string>& prefix, int r, int c, string current, set<string>& words, set<pair<int, int> >& visited) {
        visited.insert(make_pair(r, c));
        current += board[r][c];
        if (words.find(current) != words.end())
            found.insert(current);
        if (r > 0 && visited.find(make_pair(r - 1, c)) == visited.end()) {
            string temp = current + board[r - 1][c];
            if (prefix.find(temp) != prefix.end())
                dfs(board, prefix, r - 1, c, current, words, visited);
        }
        if (c > 0 && visited.find(make_pair(r, c - 1)) == visited.end()) {
            string temp = current + board[r][c - 1];
            if (prefix.find(temp) != prefix.end())
                dfs(board, prefix, r, c - 1, current, words, visited);
        }
        if (r < board.size() - 1 && visited.find(make_pair(r + 1, c)) == visited.end()) {
            string temp = current + board[r + 1][c];
            if (prefix.find(temp) != prefix.end())
                dfs(board, prefix, r + 1, c, current, words, visited);
        }
        if (c < board[0].size() - 1 && visited.find(make_pair(r, c + 1)) == visited.end()) {
            string temp = current + board[r][c + 1];
            if (prefix.find(temp) != prefix.end())
                dfs(board, prefix, r, c + 1, current, words, visited);
        }
        visited.erase(make_pair(r, c));

    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> prefix, w2;
        set<pair<int, int> > v;
        for (int i = 0; i < words.size(); i++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                temp += words[i][j];
                prefix.insert(temp);
                w2.insert(words[i]);
            }
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, prefix, i, j, "", w2, v);
        vector<string> ans;
        set<string>::iterator it;
        for (it = found.begin(); it != found.end(); it++)
            ans.push_back(*it);
        return ans;
    }
};
