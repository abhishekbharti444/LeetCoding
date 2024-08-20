class Solution {
public:
    int n;
    vector<string> res;
    unordered_map<string, vector<string>> g;
    void util(string src) {
        while (!g[src].empty()) {
            string next = g[src].back();
            g[src].pop_back();
            util(next);
        }
        res.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        
        n = tickets.size();
        for (int i = 0; i < n; ++i) {
            g[tickets[i][0]].push_back(tickets[i][1]);
        } 
        
        for (auto& el: g) {
            sort(el.second.begin(), el.second.end(), greater<>());
        }
        
        for (auto& el : g) {
            cout<<el.first<<' ';
            for (auto& a : el.second) cout<<a<<" ";
            cout<<endl;
        }

        util("JFK");
        reverse(res.begin(), res.end());
        return res;
        
    }
};