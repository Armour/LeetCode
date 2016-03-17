class Solution(object):
    def readOff(self, s):
        ret, pre, t = "", None, 0
        for i in xrange(len(s)):
            if (s[i] != pre):
                if (pre != None):
                    ret += str(t) + str(pre)
                t, pre = 1, s[i]
            else:
                t += 1
        ret += str(t) + str(pre)
        return ret

    def countAndSay(self, n):
        s = "1"
        while n > 1:
            n, s = n - 1, self.readOff(s)
        return s

