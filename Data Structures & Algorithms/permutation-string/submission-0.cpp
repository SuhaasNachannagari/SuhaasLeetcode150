class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }

        vector<int> s1Permutation(26, 0);
        for (char c : s1) {
            s1Permutation[c - 'a']++;
        }

        vector<int> s2Permutation(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s2Permutation[s2[i] - 'a']++;
        }

        int l = 0;
        int r = s1.length() - 1;

        while (r < s2.length()) {
            if (s1Permutation == s2Permutation) {
                return true;
            }
            s2Permutation[s2[l] - 'a']--;
            l++;
            r++;
            s2Permutation[s2[r] - 'a']++;
        }
        return false;
    }
};
