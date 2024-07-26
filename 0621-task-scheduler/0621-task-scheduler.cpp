class Solution {
public:
    
    /*
        Really difficult to come up with
        Approach: 
            1. To be able to capture the idle time with the tasks properly we are introducing adding a char('#') everytime idle is encoutered. 
            2. There is a max_heap that can store the tasks with their remaining frequencies to be executed. We can push the data after counting the freq through a hashmap. 
            3. If in one cycle you encounter that the heap didn't have enough task to complete, we are counting the idle_time by appending '#' to res. 
            4. To facilitate appending the tasks again to max_heap we can use an intermediary set, a vector could also have worked. 
        
        
        
    */
    struct TaskFreq {
        int freq;
        char task;
    };
    int leastInterval(vector<char>& tasks, int n) {
        
        queue<TaskFreq> q;
        unordered_map<char, int> mp;
        auto lmd = [&](auto& a, auto& b) {
            return a.freq < b.freq;
        };
        priority_queue<TaskFreq, vector<TaskFreq>, decltype(lmd)> max_heap(lmd);
        for (int i = 0; i < tasks.size(); ++i) mp[tasks[i]]++;
        for (auto& a : mp) max_heap.push({a.second, a.first});
        
        string res = "";
        set<pair<int, char>> st;
        while (!max_heap.empty()) {
            auto top = max_heap.top();
            max_heap.pop();
            res += top.task;
            top.freq -= 1;
            if (top.freq > 0) st.insert({top.freq, top.task});
            int count = 0;
            while (count < n) {
                if (!max_heap.empty()) {
                    auto curr_top = max_heap.top();
                    max_heap.pop();
                    res += curr_top.task;
                    curr_top.freq -= 1;
                    if (curr_top.freq > 0) st.insert({curr_top.freq, curr_top.task});
                }
                else if (!st.empty()) {
                    res += '#';
                }
                count++;
            }
            
            for (auto& a : st) max_heap.push({a.first, a.second});
            st.clear();
        }
        
        return res.size();   
    }
};