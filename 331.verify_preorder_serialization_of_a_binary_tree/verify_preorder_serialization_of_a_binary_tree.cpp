class Solution {
public:
    vector<string> vs;
    
    void split(string preorder) {
        istringstream ss(preorder);
        string str;
        while (getline(ss, str, ',')) {
            vs.push_back(str);
        }
    }

    bool isValidSerialization(string preorder) {
        if (preorder.compare("#") == 0) return true;
        int count = 1;
        split(preorder);
        for (auto s: vs) {
            if (s.compare("#") != 0) {
                if (count == 0)
                    return false;
                count++;
            } else {
                count--;
            }
        }
        return count == 0;
    }
};
