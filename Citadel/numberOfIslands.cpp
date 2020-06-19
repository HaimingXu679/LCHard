class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int> > node;
                    set<pair<int, int> > seen;
                    node.push(make_pair(i, j));
                    ans++;
                    while (!node.empty()) {
                        pair<int, int> cur = node.front();
                        node.pop();
                        seen.insert(cur);
                        if (grid[cur.first][cur.second] == '1') {
                            grid[cur.first][cur.second] = '0';
                            if (cur.first > 0 && seen.find(make_pair(cur.first - 1, cur.second)) == seen.end())
                                node.push(make_pair(cur.first - 1, cur.second));
                            if (cur.first < grid.size() - 1 
                                && seen.find(make_pair(cur.first + 1, cur.second)) == seen.end())
                                node.push(make_pair(cur.first + 1, cur.second));
                            if (cur.second > 0 && seen.find(make_pair(cur.first, cur.second - 1)) == seen.end())
                                node.push(make_pair(cur.first, cur.second - 1));
                            if (cur.second < grid[0].size() - 1 
                                && seen.find(make_pair(cur.first, cur.second + 1)) == seen.end())
                                node.push(make_pair(cur.first, cur.second + 1));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
