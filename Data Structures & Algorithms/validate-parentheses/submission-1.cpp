class Solution {
   public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                brackets.push(ch);
                continue;
            }
            switch (ch) {
                case ')':
                    if (!brackets.empty() && brackets.top() == '(') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!brackets.empty() && brackets.top() == '{') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!brackets.empty() && brackets.top() == '[') {
                        brackets.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
            }
        }

        return brackets.empty();
    }
};
