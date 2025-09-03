class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        ss = s[::-1]
        print(ss)

        words = ss.split()

        print(words)

        result = []

        for i in words:
            result.append(i[::-1])

        ans = " ".join(result)

        return ans
        