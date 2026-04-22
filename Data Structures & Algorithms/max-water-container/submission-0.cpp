class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int area = (r - l) * min(heights[l], heights[r]);
            res = max(res, area);

            if (heights[l] >= heights[r]) {
                r--;
            } else {
                l++;
            } 
        }

        return res;
    }
};
