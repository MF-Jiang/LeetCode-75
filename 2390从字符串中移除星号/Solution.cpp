class Solution {
public:
    string removeStars(string s) {
        std::stack<char> stack;
        for (auto c : s) {
            if (stack.empty()) {
                stack.push(c);
                continue;
            }
            if (c == '*') {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        string res;
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

