class Solution:
    def isValid(self, s: str) -> bool:
        char_map = {
            ")":"(",
            "]":"[",
            "}":"{"
        }

        stack = []
        for ch in s:
            if ch in char_map.values():
                stack.append(ch)
            elif ch in char_map.keys():
                if not stack or char_map[ch] != stack.pop():
                    return False
        
        return not stack
        