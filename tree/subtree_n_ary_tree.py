# User function Template for python3

"""
class Node:
	def __init__(self, key, children=None):
		self.key = key
		self.children = children or []
	
	def __str__(self):
		return str(self.key)
"""
from collections import defaultdict


class Solution:
    def postOrder(self, p):
        if p == None:
            return ""
        path = str(p.key)
        for child in p.children:
            path = path + "#" + self.postOrder(child)

        if self.table[path] == 1:
            self.ans += 1

        self.table[path] += 1

        return path

    def duplicateSubtreeNaryTree(self, root):
        # code here
        self.ans = 0
        self.table = defaultdict(int)
        self.postOrder(root)

        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import defaultdict
from collections import deque


class NodeNotFoundException(Exception):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return repr(self.value)


class Node:
    def __init__(self, key, children=None):
        self.key = key
        self.children = children or []

    def __str__(self):
        return str(self.key)


class N_ary_Tree:
    def __init__(self):
        self.root = None
        self.size = 0

    def find_node(self, node, key):
        if node == None or node.key == key:
            return node
        for child in node.children:
            return_node = self.find_node(child, key)
            if return_node:
                return return_node
        return None

    def add(self, new_key, parent_key=None):
        new_node = Node(new_key)
        if parent_key == None:
            self.root = new_node
            self.size = 1
        else:
            parent_key.children.append(new_node)
            self.size += 1
        return new_node


if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        N = [el for el in input().split()]
        """
        N-ary Tree Building
        """

        tree = N_ary_Tree()
        curr = 0
        for i in range(len(N)):
            if i == 0:
                q = deque()
                curr = tree.add(int(N[0]))
            elif N[i] == " " or N == "\n":
                continue
            elif q and N[i] == "N":
                curr = q.popleft()
            elif N[i] != "N":
                q.append(tree.add(int(N[i]), curr))

        res = Solution().duplicateSubtreeNaryTree(tree.root)
        print(res)
# } Driver Code Ends
