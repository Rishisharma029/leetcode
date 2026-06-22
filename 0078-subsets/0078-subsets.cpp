class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int idx, vector<int>& nums) {
        // Every state is a valid subset
        ans.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(nums[i]);      // choose
            backtrack(i + 1, nums);       // recurse
            curr.pop_back();              // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};