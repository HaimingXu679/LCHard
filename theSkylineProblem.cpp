// https://leetcode.com/problems/the-skyline-problem/

// Priority queues

// O(NlogN), beats 25%

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int> > ans;
        if (buildings.size() == 0)
            return ans;
        unordered_map<int, priority_queue<pair<int, int> > > start;
        unordered_map<int, priority_queue<int> > end;
        set<int> total;
        int current = -1, dur = 0;
        for (int i = 0; i < buildings.size(); i++) {
            start[buildings[i][0]].push(make_pair(buildings[i][2], buildings[i][1]));
            end[buildings[i][1]].push(buildings[i][2]);
            total.insert(buildings[i][0]);
            total.insert(buildings[i][1]);
        }
        priority_queue<pair<int, int> > b;
        for (auto loc : total) {
            if (start.count(loc) != 0) {
                while (!start[loc].empty()) {
                    b.push(make_pair(start[loc].top().first, start[loc].top().second));
                    if (start[loc].top().first > current) {
                        vector<int> temp{loc, start[loc].top().first};
                        current = start[loc].top().first;
                        ans.push_back(temp);
                        dur = start[loc].top().second;
                    }
                    start[loc].pop();
                }
            }
            if (end.count(loc) != 0 && loc >= dur) {
                bool breaker = false;
                while (!b.empty()) {
                    if (b.top().second > loc) {
                        if (loc != dur || b.top().first != current) {
                            vector<int> temp{loc, b.top().first};
                            current = b.top().first;
                            ans.push_back(temp);
                        }
                        breaker = true;
                        dur = b.top().second;
                        break;
                    }
                    b.pop();
                }
                if (!breaker) {
                    vector<int> temp{loc, 0};
                    current = 0;
                    ans.push_back(temp);
                    dur = loc;
                }
            }
        }
        return ans;
    }
};
