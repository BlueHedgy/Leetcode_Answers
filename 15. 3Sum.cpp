class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // Sort input array
        int l = nums.size();

        //Base cases
        if (l <3) return {};
        if (nums[0] >0) return {};

        vector<vector<int>> ans;
        
        for (int i=0; i<l; i++){
            if (nums[i] >0) break; // sorted array, if >0 then numbers after is also >0 => sum can't be 0
            if (i>0 && nums[i] == nums[i-1]) continue;

            int low = i+1, high = nums.size()-1;
            int sum = 0;
            while (low < high){
                sum= nums[i] + nums[low] + nums[high];
                
                if(sum > 0) high--;
                else if(sum <0) low++;

                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int last_low = nums[low], last_high=nums[high];

                    while (low<high && last_low == nums[low]) low++;
                    while (low<high && last_high == nums[high]) high--;
                }
            }
        }
        return ans;
    }
};