class Solution {
public:
    struct data {
        int freq;
        char ch;
    };
    
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for (int i=0; i<tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        auto lmd = [&] (auto& a, auto& b) {
            return a.freq<b.freq;
        };
        priority_queue<data, vector<data>, decltype(lmd)> pq(lmd);
        for (auto a:mp) {
            pq.push({a.second, a.first});
        }
        set<pair<char, int>> st;
        string res = "";
        while(!pq.empty()) {
            auto a1 = pq.top();
            pq.pop();
            int count = 0;
            res += a1.ch;
            a1.freq -= 1;
            if (a1.freq>0) {
                st.insert({a1.ch, a1.freq});
            }
            while (count<n) {
                if (!pq.empty()) {
                    a1 = pq.top();
                    pq.pop();
                    res += a1.ch;
                    a1.freq -= 1;
                    if (a1.freq>0) {
                        st.insert({a1.ch, a1.freq});
                    }
                }
                else if (!st.empty()) {
                    res += '#';
                }
                count++;
            }
            for (auto a:st) {
                pq.push({a.second, a.first});
            }
            st.clear();
        }
        return res.size();
    }
};