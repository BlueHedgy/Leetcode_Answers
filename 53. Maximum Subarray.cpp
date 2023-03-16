class Solution {
public:
// Kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int curr_max = INT_MIN;
        int max_here = 0;

        for (int i=0; i<nums.size(); i++){
            max_here = max_here + nums[i];
            if (curr_max < max_here){
                curr_max = max_here;
            }
            if (max_here < 0){
                max_here =0;
            }
        }

        return curr_max;
    }
};