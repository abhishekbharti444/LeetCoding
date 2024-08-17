class Solution {
public:
    
    /*
        Great question: 
            Watch neetcode solution for the intuition. 
            This solution is inspired by lee215 solution. Very cleverly he has used max_heap as min_heap by keeping numbers negative. 
            
    */
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        unordered_map<int, int> res;
        vector<int> Q = queries;
        priority_queue<vector<int>> min_heap;
        sort(Q.begin(), Q.end());
        int i = 0;
        int n = intervals.size();
        for (int q : Q) {
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                min_heap.push({l - r - 1, r});
                i++;
            }
            
            while (!min_heap.empty() && q > min_heap.top()[1]) {
                min_heap.pop();
            }
            
            
            res[q] = min_heap.empty() ? -1 : -min_heap.top()[0];
        }
        
        vector<int> ans;
        
        for (int a : queries) {
            ans.push_back(res[a]);
        }
        
        return ans;
    }
};