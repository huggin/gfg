# User function Template for python3

"""
class Node:

    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None
"""


def build(ino, start, end, d):
    if start > end:
        return None
    if start == end:
        return Node(ino[start])
    idx = start
    for i in range(start + 1, end + 1):
        if d[ino[i]] < d[ino[idx]]:
            idx = i

    root = Node(ino[idx])
    root.left = build(ino, start, idx - 1, d)
    root.right = build(ino, idx + 1, end, d)
    return root


def buildTree(level, ino):
    # code here
    # return root of tree
    n = len(ino)
    d = {}
    for i in range(n):
        d[level[i]] = i

    return build(ino, 0, n - 1, d)


# {
# Driver Code Starts
# Initial Template for Python 3

# contributed by RavinderSinghPB


class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


def preOrd(root):
    if not root:
        return
    print(root.data, end=" ")
    preOrd(root.left)
    preOrd(root.right)


if __name__ == "__main__":
    tcs = int(input())

    for _ in range(tcs):
        n = int(input())

        InOrd = [int(x) for x in input().split()]
        LvlOrd = [int(x) for x in input().split()]

        root = buildTree(LvlOrd, InOrd)

        preOrd(root)
        print()


# } Driver Code Ends
