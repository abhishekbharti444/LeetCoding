class Solution {
public:
    struct data
    {
        int node;
        int time;
    };
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        unordered_map<int, vector<int>> mp;
        
        for (int i=0; i<n; i++) 
        {
            if (manager[i]!=-1)
                mp[manager[i]].push_back(i);
        }
        
        queue<data> q;
        
        q.push({headID, 0});
        
        int time = 0;
        
        while( q.empty() == false ) 
        {
            int k = q.size();
            for (int i=0; i<k; i++) 
            {
                auto  t = q.front();
                q.pop();
                
                for (auto& it : mp[t.node]) 
                {
                    int value = informTime[t.node] + t.time;
                    q.push({it, value});
                    time = max(time, value);
                }
                
            }
            
        }
        
        return time;
        
    }
};