class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        right = 0
        result, current_min = -sys.maxsize, sys.maxsize
        while right < len(prices):
            if prices[right] < current_min:
                current_min = prices[right]
            
            result = max(result, prices[right] - current_min)
            right += 1
        
        return result
        