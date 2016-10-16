class Solution {
public:
    vector<string> v;
    
    void split(string input, vector<string> &v) {
        istringstream ss(input);
        string str;
        while (getline(ss, str, '\n')) {
            v.push_back(str);
        }
    }
    
    bool isFile(const string &str) {
       auto dot = str.find('.');
       return dot != string::npos && dot != str.length() - 1;
    }
    
    int lengthLongestPath(string input) {
        if (input.compare("") == 0) return 0;
        split(input, v);
        int res = 0;
        int tmp_res = 0;
        stack<string> path;
        for (int i = 0; i < v.size(); i++) {
            int cnt = 0;
            while (true) {
                if (cnt < v[i].length()) {
                    if (v[i][cnt] == '\t') {
                        cnt++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            v[i] = v[i].substr(cnt);
            while (path.size() > cnt) {
                tmp_res -= path.top().length() + (path.size() != 1);
                path.pop();
            }
            tmp_res += v[i].length() + (path.size() != 0);
            path.push(v[i]);
            if (isFile(v[i])) {
                res = max(res, tmp_res);
            }
        }
        return res;
    }
};
