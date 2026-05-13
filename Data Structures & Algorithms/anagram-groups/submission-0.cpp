class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> keyToStrings;

        for (auto& str : strs) {
            vector<int> code(26, 0);
            for (char& c : str) {
                code[c - 'a'] ++;
            }

            string key = "";

            for (auto& num : code) {
                key += to_string(num) + "&"; 
            }

            keyToStrings[key].push_back(str);
        }

        for (auto& ele : keyToStrings) {
            results.push_back(ele.second);
        }

        return results;
        
    }
};
