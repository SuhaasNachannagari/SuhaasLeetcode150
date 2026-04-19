class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpTo = nums.size() - 1;
        int minimum = 0;
        
        while(jumpTo > 0) {
            int best = 0;
            int prev = jumpTo - 1;
            while (prev >= 0) {
                if (prev + nums[prev] >= jumpTo) {
                    best = prev;
                }
                prev--;
            }
            minimum++;
            jumpTo = best;
        }

        return minimum;
    }
};
