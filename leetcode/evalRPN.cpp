class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> nums;
        for (int i=0, n=tokens.size(); i<n; ++i)
            if (tokens[i] == "+") {
                int a = nums.back(); nums.pop_back();
                int b = nums.back(); nums.pop_back();
                nums.push_back(b+a);
            }
            else if (tokens[i] == "-") {
                int a = nums.back(); nums.pop_back();
                int b = nums.back(); nums.pop_back();
                nums.push_back(b-a);
            }
            else if (tokens[i] == "*") {
                int a = nums.back(); nums.pop_back();
                int b = nums.back(); nums.pop_back();
                nums.push_back(b*a);
            }
            else if (tokens[i] == "/") {
                int a = nums.back(); nums.pop_back();
                int b = nums.back(); nums.pop_back();
                nums.push_back(b/a);
            }
            else {
                int num;
                sscanf(tokens[i].c_str(), "%d", &num);
                nums.push_back(num);
            }
        return nums[0];
    }
};