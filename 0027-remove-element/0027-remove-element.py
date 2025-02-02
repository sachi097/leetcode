class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0 
        right = 0
        while right < len(nums):
            if nums[left] == val:
                while right < len(nums) and nums[right] == val:
                    right += 1
                if right < len(nums):
                    nums[left] = nums[right]
                    nums[right] = val
            left += 1
            right += 1
        return len(nums) - (right - left)