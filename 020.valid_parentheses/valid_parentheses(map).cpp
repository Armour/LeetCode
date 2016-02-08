class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        map<char, char> pMap;
        pMap.insert(make_pair('(',')'));
        pMap.insert(make_pair('[',']'));
        pMap.insert(make_pair('{','}'));
        for (char ch: s) {
            if (pMap.find(ch) != pMap.end()) {
                pStack.push(ch);
            } else {
                if (!pStack.empty() && pMap[pStack.top()] == ch)
                    pStack.pop();
                else
                    return false;
            }
        }
        return pStack.empty();
    }
};
