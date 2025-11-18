# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        result = [0]
        prefixMap = {0: 1}
        def pathSumK(root, currentSum):
            if root == None:
                return

            currentSum += root.val

            if prefixMap.get(currentSum - targetSum) != None:
                result[0] += prefixMap.get(currentSum - targetSum)
            

            prefixMap[currentSum] = prefixMap.get(currentSum, 0) + 1
            pathSumK(root.left, currentSum)
            pathSumK(root.right, currentSum)
            prefixMap[currentSum] -= 1
        
        pathSumK(root, 0)
        return result[0]
        