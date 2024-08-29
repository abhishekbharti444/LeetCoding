class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        for (int i = 1; i <= n; ++i) dq.push_back(i);
        
        while (dq.size() > 1) {
            // int mod_k = dq.size()%k;
            for (int i = 0; i < k; ++i) {
                int curr = dq.front();
                dq.pop_front();
                dq.push_back(curr);
            }
            dq.pop_back();
        }
        return dq.front();
    }
};