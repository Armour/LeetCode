class Solution {
public:
    vector<int> &split(const string &s, char delim, vector<int> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(stoi(item));
        }
        return elems;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        split(version1, '.', v1);
        split(version2, '.', v2);
        int i = 0;
        for (auto v: v1) {
            int vv;
            if (v2.size() <= i)
                vv = 0;
            else
                vv = v2[i];
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
