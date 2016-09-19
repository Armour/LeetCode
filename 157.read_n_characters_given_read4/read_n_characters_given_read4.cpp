// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0, ret;
        do {
            ret = read4(buf + i);
            i += ret;
        } while (ret == 4 && i < n);
        return min(i, n);
    }
};

