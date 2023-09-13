class Solution:
    def reverseWords(self, s: str) -> str:
        t = ""
        for word in s.split():
            t = word + " " + t
        return t.rstrip()
        