class Solution {
public:
    long long res = 0;
    unordered_map<int, vector<int>> graph;
    unordered_set<int> vis;
    int n;
    int seats;
    long long util(int node) {
        if (vis.find(node) != vis.end()) return 0;
        vis.insert(node);
        long long count = 0;
        for (int i = 0; i < graph[node].size(); ++i) {
            count += util(graph[node][i]);
        }
        count++;
        res += ceil(double(count)/this->seats);
        // cout<<res<<" "<<node<<". ";
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size();
        this->seats = seats;
        
        for (int i = 0; i < n; ++i) {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        vis.insert(0);
        for (int i = 0; i < graph[0].size(); ++i) util(graph[0][i]);
        return res;
    }
};