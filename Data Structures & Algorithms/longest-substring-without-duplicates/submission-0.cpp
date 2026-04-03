class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        int result = 0;

        unordered_set<char> windowChars;

        while (r < s.length()) {
            while (windowChars.count(s[r]) > 0) {
                windowChars.erase(s[l]);
                l++;
            }

            result = max(result, r - l + 1);
            windowChars.insert(s[r]);
            r++;
        }

        return result;
        
    }
};
