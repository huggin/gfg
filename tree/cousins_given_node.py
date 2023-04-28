# User function Template for python3

from collections import deque

"""
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
"""


class Solution:
    def printCousins(self, root, node_to_find):
        # code here
        q = deque()
        q.append(root)

        parent = {root: None}
        level = {root: 0}
        found = -1
        node = None

        while len(q) > 0:
            curr = q.popleft()
            if curr == node_to_find:
                found = level[curr]
                node = curr
            if curr.left:
                parent[curr.left] = curr
                q.append(curr.left)
                level[curr.left] = level[curr] + 1
            if curr.right:
                parent[curr.right] = curr
                q.append(curr.right)
                level[curr.right] = level[curr] + 1

        if not node:
            return [-1]

        ans = []
        for k, v in level.items():
            if v == found and parent[k] != parent[node]:
                ans.append(k.data)

        if len(ans) == 0:
            return [-1]
        ans.sort()
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3
# Initial Template for Python 3
# Tree Node


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


def pointer(root, n):
    if root == None:
        return None

    if root.data == n:
        return root

    l = pointer(root.left, n)
    if l != None and l.data == n:
        return l

    r = pointer(root.right, n)
    return r


if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        s = input()
        root = buildTree(s)
        p = pointer(root, n)
        ob = Solution()
        ans = ob.printCousins(root, p)

        for i in range(len(ans)):
            print(ans[i], end=" ")

        print()

# } Driver Code Ends
