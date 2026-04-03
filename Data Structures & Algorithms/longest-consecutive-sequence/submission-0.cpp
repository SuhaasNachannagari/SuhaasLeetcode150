
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;

        for (const int& num : nums) {
            check.insert(num);
        }
        int result = 0;
        for (auto ele : check) {
            int beginning = ele;
            // Make sure this is the beginning of a sequence
            if (check.count(beginning - 1) > 0) {
                continue;
            } 

            int length = 1;
            while (check.count(beginning + 1) > 0) {
                length++;
                beginning++;
            }

            result = max(result, length);
        }
        return result;
    }
};
