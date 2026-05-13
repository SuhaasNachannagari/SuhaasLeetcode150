class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        char mostFreq = '1';

        int result = 0;

        unordered_map<char, int> counts;
        
        while (r < s.length()) {
            counts[s[r]]++;

            if (counts[mostFreq] <= counts[s[r]]) {
                mostFreq = s[r];
            }

            if (r - l + 1 - counts[mostFreq] > k) {
                counts[s[l]]--;
                l++;
            }

            result = max(result, r - l + 1);
            r++;      
        }

        return result;

        
    }
};
