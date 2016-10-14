class Solution {
public:
    vector<string> res;
        
    void search(string val, int number, int depth, int maxDepth) { 
        if (depth >= maxDepth) {
            string tmp = "";
            for (int i = 0; i < number; i++) {
                tmp += ")";
            }
            res.push_back(val + tmp);
            return;
        }
        search(val + "(", number + 1, depth + 1, maxDepth);
        if (number > 0) {
            search(val + ")", number - 1, depth, maxDepth);
        }
    }

    vector<string> generateParenthesis(int n) {
        search("", 0, 0, n);
        return res;
    }
};
