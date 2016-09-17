class Solution {
public:
   int romanToInt(string s) {
        int tmp = 0, res = 0, cur = 0;
        for (auto c = s.rbegin(); c != s.rend(); c++) {
            switch (*c) {
                case 'I': cur = 1; break;
                case 'V': cur = 5; break;
                case 'X': cur = 10; break;
                case 'L': cur = 50; break;
                case 'C': cur = 100; break;
                case 'D': cur = 500; break;
                case 'M': cur = 1000;
                default: break;
            }
            cur >= tmp ? res += cur : res -= cur;
            tmp = cur;
        }
        return res;
    }
};
