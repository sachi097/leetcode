class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        prefixSumMap = {0: 1}
        result = 0

        for num in nums:
            prefixSum += num
            if prefixSumMap.get(prefixSum - k) != None:
                result += prefixSumMap.get(prefixSum - k)
            
            prefixSumMap[prefixSum] = prefixSumMap.get(prefixSum, 0) + 1
        
        return result

        