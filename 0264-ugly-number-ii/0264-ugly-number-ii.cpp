/*
 Watch the neetcode solution on the same. 
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec;
        
        vec.push_back(1);
        
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        
        for (int i = 1; i < n; ++i) {
            int next_num = min({vec[i2] * 2, vec[i3] * 3, vec[i5] * 5});
            vec.push_back(next_num);
            if (next_num == vec[i2] * 2) i2++;
            if (next_num == vec[i3] * 3) i3++;
            if (next_num == vec[i5] * 5) i5++;
        }
        
        return vec[n-1];
    }
};