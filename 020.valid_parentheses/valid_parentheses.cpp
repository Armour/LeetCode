class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        for (char ch: s) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    pStack.push(ch);
                    break;
                case ')':
                    if (pStack.empty() || pStack.top() != '(')
                        return false;
                    else
                        pStack.pop();
                    break;
                case ']':
                    if (pStack.empty() || pStack.top() != '[')
                        return false;
                    else
                        pStack.pop();
                    break;
                case '}':
                    if (pStack.empty() || pStack.top() != '{')
                        return false;
                    else
                        pStack.pop();
                    break;
            }
        }
        return pStack.empty();
    }
};
