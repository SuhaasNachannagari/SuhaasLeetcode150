class Solution {
public:
    bool canJump(vector<int>& nums) {
        int needJump = 1;
        int jumpTo = nums.size() - 1;


        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= needJump) {
                jumpTo = i;
                needJump = 1;
            } else {
                needJump++;
            }
        }

        return jumpTo == 0;
    }
};
