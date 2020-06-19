class Solution {
public:
    vector<string> ans;
    map<string, multiset<string> > adj;

    void euler(string loc) {
        stack<string> v;
        v.push(loc);
        while (!v.empty()) {
            string temp = v.top();
            if (adj[temp].size() > 0) {
                v.push(*adj[temp].begin());
                adj[temp].erase(adj[temp].begin());
            } else {
                v.pop();
                ans.push_back(temp);
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string> ticket : tickets)
            adj[ticket[0]].insert(ticket[1]);
        euler("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
