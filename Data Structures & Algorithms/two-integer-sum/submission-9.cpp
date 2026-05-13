class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenPos;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seenPos.count(complement) > 0) {
                return {seenPos[complement], i};
            }
            seenPos[nums[i]] = i;
        }
    }
};
