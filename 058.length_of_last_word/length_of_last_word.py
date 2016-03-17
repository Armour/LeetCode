class Solution(object):
    def lengthOfLastWord(self, s):
        s = s.split()
        if len(s) == 0:
            return 0
        else:
            return len(s[-1])
