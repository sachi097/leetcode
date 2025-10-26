class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq_map = [-1] * 256
        left, right = 0, 0
        max_window = 0
        while right < len(s):
            index = ord(s[right])
            if freq_map[index] != -1:
                left = max(freq_map[index] + 1, left)
            
            freq_map[index] = right
            if max_window < right - left + 1:
                max_window = right - left + 1
            
            right += 1
        
        return max_window

