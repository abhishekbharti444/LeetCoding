class Solution {
public:
    /*
        Approach:
            1. Keep the counts of each characters in an unordered_map
            2. Take a max_heap to have only the frequecies stored in descending order.
            3. Compare top two elements only of the max_heap and if they are equal, add 1 to the res.
            4. Decrease the top value by one and push it again to the max_heap to have processed for next iterations as well in case the top two were equal.
            5. Each time only pop the top element(first). second is only used to compare with first.
            
            
        Time: O(N + K^2 * logK); N => len of string, K => Maximum possible number of distinct chars in string.
        Space: O(K)
    */
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        priority_queue<int> max_heap;
        for (auto& el: mp) max_heap.push(el.second);
        int res = 0;
        while (max_heap.size() > 1) {
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            if (first == second) {
                if (first - 1 > 0) max_heap.push(first-1);
                res++;
            }
        }
        return res;
    }
};