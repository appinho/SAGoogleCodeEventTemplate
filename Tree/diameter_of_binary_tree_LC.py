# LC
# MIDDLE
# Prime

def diameterOfBinaryTree(self, root):
    """
    :type root: TreeNode
    :rtype: int
    """
    self.output=0
    def lengthOfTree(root):
        if not root:
            return 0
        l = lengthOfTree(root.left)
        r = lengthOfTree(root.right)
        self.output=max(self.output, l+r)
        return max(l, r)+1
    
    lengthOfTree(root)
    return self.output