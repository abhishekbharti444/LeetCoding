class Solution {
public:
    
    /*
        Approach:
            1. Every node has a traversal to make from itself to 0th. 
            2. Notice all we need to know at each node to travel to it's parent is how many people are there in that subtree. We can consider this to be a tree which is rooted at 0.
                This way each node will have children and parent.
            3. At each node you return the number of nodes present in that whole subtree including itself.
            4. Add the result on the way. To take 4 people from curr node to it's parent with 3 seats in each car will take ceil(4/3) = 2 cars. 
            
            5. Make sure you are calling the dfs from all the children of 0 and not on 0. 
            
        Time: O(N);
        Space: O(N); Recursion stack space
    */
    
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