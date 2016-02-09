class Solution {
public:
    static bool compare(string &s1, string &s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int> &num) {
        vector<string> arr;

        for (int i : num)
            arr.push_back(to_string(i));

        sort(arr.begin(), arr.end(), compare);

        string ret;
        for (string s : arr)
            ret += s;

        if (ret[0] == '0' && ret.size() > 0)
            return "0";

        return ret;
    }
};
