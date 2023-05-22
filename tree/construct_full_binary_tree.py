# User function Template for python3


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Solution:
    def solve(self, pre, preMirror, l1, r1, l2, r2):
        if l1 > r1:
            return None
        if l1 == r1:
            return Node(pre[l1])

        p = Node(pre[l1])
        idx = preMirror.index(pre[l1 + 1])
        if idx == l2 + 1:
            p.left = self.solve(pre, preMirror, l1 + 1, r1, l2 + 1, r2)
        else:
            right_idx = pre.index(preMirror[l2 + 1])
            p.left = self.solve(pre, preMirror, l1 + 1, right_idx - 1, idx, r2)
            p.right = self.solve(pre, preMirror, right_idx, r1, l2 + 1, idx - 1)

        return p

    def constructBinaryTree(self, pre, preMirror, size):
        # code here
        return self.solve(pre, preMirror, 0, size - 1, 0, size - 1)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":

    def printInorder(node):
        if node == None:
            return
        printInorder(node.left)
        print(node.data, end=" ")
        printInorder(node.right)

    test_cases = int(input())
    for _ in range(test_cases):
        N = int(input())
        pre = list(map(int, input().split()))
        preMirror = list(map(int, input().split()))
        res = Solution().constructBinaryTree(pre, preMirror, N)
        if printInorder(res) != None:
            print(printInorder(res)[: len(printInorder(res)) - 2])
        print()
# } Driver Code Ends
