class Solution {
public:
    
    vector<int> util(string version) {
        int m = version.size();
        int curr = 0;
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            if (version[i] == '.') {
                res.push_back(curr);
                curr = 0;
            }
            else {
                if (curr == 0 && version[i] == '0') continue;
                curr = curr * 10 + (version[i] - '0');
            }
        }
        res.push_back(curr);
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        
        vector<int> vec1, vec2;
        vec1 = util(version1);
        vec2 = util(version2);
        int m = vec1.size();
        int n = vec2.size();
        
        for (int j = 0; j < m; ++j) cout<<vec1[j]<<" ";
        cout<<endl;
        for (int j = 0; j < n; ++j) cout<<vec2[j]<<" ";
        int min_len = min(m, n);
        
        
        
        int i;
        for (i = 0; i < min_len; ++i) {
            if (vec1[i] > vec2[i]) return 1;
            else if (vec1[i] < vec2[i]) return -1;
        }
        
        if (m < n) {
            for (; i < n; ++i) {
                if (vec2[i] != 0) return -1;
            }
        }
        else if (m > n) {
            for (; i < m; ++i) {
                if (vec1[i] != 0) return 1;
            }
        }
        return 0;
        
    }
};