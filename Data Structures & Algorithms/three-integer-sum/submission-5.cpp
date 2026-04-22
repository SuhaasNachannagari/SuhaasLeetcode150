/*1,0,1,2,-1,-4


-4, -1, -1, 0, 1, 1, 2
     i  k            j
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;

        for (int i = 0; i < nums.size() - 2; i ++) {
            // Basic edge case checks
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int k = i + 1;
            int j = nums.size() - 1;

            while (k < j) {
                int sum = nums[i] + nums[j] + nums[k];
                // if less that 0, move k up
                // if greater than 0 move j down
                // process duplicates, skip them

                if (sum == 0) {
                    results.push_back({nums[i], nums[k], nums[j]});
                    while (k < j && nums[k] == nums[k + 1]) {
                        k++;
                    }
                    while (k < j && nums[j] == nums[j - 1]) {
                        j--;
                    }
                    k++;
                    j--;

                } else if (sum < 0) {
                    k++;
                }  else if (sum > 0) {
                    j--;
                }
            }
        }

        return results;
        

    }
};
