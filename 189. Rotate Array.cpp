class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); 
        int temp;
        vector<int> ans;
        for (int i = nums.size()-k; i<nums.size(); i++){
            ans.push_back(nums[i]);
        }

        for (int j=0; j<nums.size()-k; j++){
            ans.push_back(nums[j]);
        }
        nums = ans;
    }
};