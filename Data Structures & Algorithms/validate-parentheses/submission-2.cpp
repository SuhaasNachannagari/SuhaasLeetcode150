

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        unordered_map<char, char> mapping = 
            {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };

        for (char c : s) {
            if (mapping.count(c) > 0) {
                if (parentheses.empty() || mapping[c] != parentheses.top()) {
                    return false;
                } 
                parentheses.pop();
                
            } else {
                parentheses.push(c);
            }
        }

        return parentheses.empty();
    }
};
