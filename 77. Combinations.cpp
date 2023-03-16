class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int k){
        if (temp.size() == k){
            ans.push_back(temp);
        }
        else{
            for (int i=0; i<nums.size(); i++){
                if (temp.size() == 0 || nums[i]>temp[temp.size()-1]){
                    temp.push_back(nums[i]);
                    backtrack(ans, temp, nums, k);
                    temp.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums;
        
        for (int i=1; i<=n; i++) nums.push_back(i);

        backtrack(ans, temp, nums, k);
        return ans;
    }
};