# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """

        result = []

        def pre_order(node):
            if node == None:
                result.append("N")
                return
            
            result.append(str(node.val))
            pre_order(node.left)
            pre_order(node.right)
            
        pre_order(root)
        return ",".join(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self.i = -1
        data = data.split(",")

        def pre_order():
            self.i += 1
            if data[self.i] == "N":
                return None
            
            new_node = TreeNode(int(data[self.i]))
            new_node.left = pre_order()
            new_node.right = pre_order()
            return new_node

        return pre_order()



# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))