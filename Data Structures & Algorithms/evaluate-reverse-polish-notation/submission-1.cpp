class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string tok : tokens) {
            if (tok == "*") {
                int valOne = nums.top(); nums.pop();
                int valTwo = nums.top(); nums.pop();
                nums.push(valTwo * valOne);
            } else if (tok == "/") {
                int valOne = nums.top(); nums.pop();
                int valTwo = nums.top(); nums.pop();
                nums.push(valTwo / valOne);
            } else if (tok == "-") {
                int valOne = nums.top(); nums.pop();
                int valTwo = nums.top(); nums.pop();
                nums.push(valTwo - valOne);
            } else if (tok == "+") {
                int valOne = nums.top(); nums.pop();
                int valTwo = nums.top(); nums.pop();
                nums.push(valTwo + valOne);
            } else {
                nums.push(stoi(tok));
            }
        }
        return nums.top();
    }
};
