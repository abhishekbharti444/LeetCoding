class Solution {
public:
    struct data {
        int x;
        int y; 
        double dist;
    };
    double distanceFromOrigin(int a, int b) {
        return sqrt(pow(a, 2) + pow(b, 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        auto lmd = [&](auto& a, auto& b) {
            return a.dist < b.dist;
        };
        priority_queue<data, vector<data>, decltype(lmd)> min_heap(lmd);
        
        for (int i = 0; i < n; ++i) {
            min_heap.push({points[i][0], points[i][1], distanceFromOrigin(points[i][0], points[i][1])});
            if (min_heap.size() > k) min_heap.pop();
        }
        
        vector<vector<int>> res;
        while (!min_heap.empty()) {
            res.push_back({min_heap.top().x, min_heap.top().y});
            min_heap.pop();
        }
        return res;
    }
};