class Solution {
public:
    const int INF = 1e9 + 7;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n + 1, INF);
        cost[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> temp_cost = cost;
            
            for (int j = 0; j < flights.size(); ++j) {
                int source = flights[j][0];
                int dest = flights[j][1];
                int price = flights[j][2];

                if (cost[source] == INF) continue;

                if (cost[source] + price < temp_cost[dest]) {
                    temp_cost[dest] = cost[source] + price;
                }
            }
            cost = temp_cost;
        }
        return cost[dst] == INF ? -1 : cost[dst];
    }
};