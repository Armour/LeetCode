class Solution(object):
    def isValid(self, s):
        stack = []
        dict = {"(":")", "[":"]", "{":"}"}
        for i in range(len(s)):
            if s[i] in dict:
                stack.append(s[i])
            else:
                if len(stack) > 0 and s[i] == dict[stack[-1]]:
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
