class Solution:
    def check(self, nums: List[int]) -> bool:
        peak = 0
        for i in range(0, len(nums)):
            if nums[i] > nums[(i+1) % len(nums)]:
                peak += 1
        return peak <= 1
        