class Solution {
public:
    
    /*
        Approach : 
        1. Create a time array which denotes how much time each car will take to reach target.
        2. Keep the time array with float values.
        3. Create an array which binds the pos and speed of each car together as we want to sort this array based on position. 
        4. Now, populate the time array and browse through it to find out how many times local maxima changes from right to left of position. 
        
        The solution involving mono stack doesnot enhance the time complexity as we will still to sort the info array. 
        All that solution does is stores the local_maxima changes in a monotonically decreasing stack and it's size becomes the number of fleets. 
        But that we are able to calculate by just keeping a curr_max value and comparing it with current time value. 
    */
    struct data {
        int pos;
        int sp;
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> time(n);
        vector<data> info;
        for (int i = 0; i < n; ++i) info.push_back({position[i], speed[i]});
        auto lmd = [&](auto& a, auto& b) {
            return a.pos < b.pos;
        };
        sort(info.begin(), info.end(), lmd);
        
        for (int i = 0; i < n; ++i) {
            time[i] = (double)(target - info[i].pos)/info[i].sp;
        }
        int res = 0;
        double curr_max = -DBL_MAX;
        for (int i = n-1; i >= 0; --i) {
            cout<<time[i]<<" ";
            if (curr_max < time[i]) {
                curr_max = time[i];
                res++;
            }
        }
        return res;
    }
};