class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_map = defaultdict()
        for index, num in enumerate(nums):
            if index_map.get(target - num) is not None:
                return [index, index_map[target - num]]
            
            index_map[num] = index

        return [-1, -1]