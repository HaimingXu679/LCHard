// https://leetcode.com/problems/insert-interval/

// Ad-hoc, pretty simple interval checking

// O(N)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        bool added = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (!added && intervals[i][0] > newInterval[1]) {
                added = true;
                ans.push_back(newInterval);
            }
            if (!added && ((intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) || (intervals[i][1] >= newInterval[1]) || (newInterval[1] >= intervals[i][1] && newInterval[0] <= intervals[i][0]))) {
                int first = min(intervals[i][0], newInterval[0]);
                if (newInterval[1] < intervals[i][0])
                    intervals.insert(intervals.begin() + i, intervals[i]);
                while (i < intervals.size() - 1 && intervals[i + 1][0] <= newInterval[1])
                    i++;
                added = true;
                vector<int> temp;
                temp.push_back(first);
                temp.push_back(max(newInterval[1], intervals[i][1]));
                ans.push_back(temp);
            } else
                ans.push_back(intervals[i]);
        }
        if (intervals.size() == 0 || !added)
            ans.push_back(newInterval);
        return ans;
    }
};
