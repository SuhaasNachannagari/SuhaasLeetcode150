class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> substring(26,0);
        vector<int> mainstring(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            mainstring[s2[i] - 'a']++;
            substring[s1[i] - 'a']++;
        }


        int l = 0;
        int r = s1.length() - 1;

        while (r < s2.length()) {
            if (mainstring == substring) {
                return true;
            }

            
            r++;
            mainstring[s2[r] - 'a']++;
            mainstring[s2[l] - 'a']--;
            l++;
        }

        return false;
    }
};
