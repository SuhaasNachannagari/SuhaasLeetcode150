class Solution {
public:
    vector<int> subset;
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
    void dfs(vector<int>& nums, int level) {
        if (level == nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[level]);
        dfs(nums, level + 1);
        subset.pop_back();
        dfs(nums, level + 1);
    }

};
