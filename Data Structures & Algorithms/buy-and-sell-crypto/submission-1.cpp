

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int result = 0;

        while (r < prices.size()) {
            if (prices[r] <= prices[l]) {
                l = r;
            }

            result = max (prices[r] - prices[l], result);
            r++;
        }
        return result;
    }
};
