class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        def calculateSpeed(currentSpeed):
            ans = 0
            for distance in dist[:-1]:
                ans += math.ceil((distance / currentSpeed))
            ans += (dist[-1] / currentSpeed)
            return ans <= hour

        low, high = 1, 10**7
        result = -1
        while low <= high:
            mid = (low + high) // 2
            if calculateSpeed(mid):
                result = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return result