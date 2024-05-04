class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        
        int i = 0; 
        int res = 0;
        
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            }
            else {
                right--;
            }
            res++;
        }
        return res;
    }
};