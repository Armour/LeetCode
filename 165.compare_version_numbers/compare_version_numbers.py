class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = map(int, version1.split("."))
        v2 = map(int, version2.split("."))
        while len(v1) > len(v2):
            v2.append(0);
        while len(v2) > len(v1):
            v1.append(0);
        if v1 < v2:
            return -1
        elif v1 > v2:
            return 1
        else:
            return 0
