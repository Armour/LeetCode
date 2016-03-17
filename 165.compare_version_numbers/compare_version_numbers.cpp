class Solution {
public:
    vector<int> &split(const string &s, char delim, vector<int> &ret) {
        stringstream ss(s);
        string str;
        while (getline(ss, str, delim)) {
            if (str.compare("") != 0)
                ret.push_back(stoi(str));
        }
        return ret;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        split(version1, '.', v1);
        split(version2, '.', v2);
        int i = 0;
        for (auto v: v1) {
            int vv = v2.size() <= i ? 0 : v2[i];
            if (v > vv)
                return 1;
            else if (v < vv)
                return -1;
            i++;
        }
        for (; i < v2.size(); i++)
            if (v2[i] > 0)
                return -1;
        return 0;
    }
};
