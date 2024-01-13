# User function Template for python3


class TrieNode:
    def __init__(self):
        self.children = [None, None]


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def find(self, a):
        n = len(a)
        p = self.root
        i = 0
        while i < n:
            if p.children[a[i]] is None:
                return False
            p = p.children[a[i]]
            i += 1
        return True

    def insert(self, a):
        n = len(a)
        p = self.root
        i = 0
        while i < n:
            if p.children[a[i]] is None:
                p.children[a[i]] = TrieNode()
            p = p.children[a[i]]
            i += 1


class Solution:
    def repeatedRows(self, arr, m, n):
        # code here
        ans = []
        root = Trie()
        for i in range(m):
            if root.find(arr[i]):
                ans.append(i)
            root.insert(arr[i])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))

        arr = []
        for i in range(n):
            nums = list(map(int, input().strip().split()))
            arr.append(nums)
        ob = Solution()
        ans = ob.repeatedRows(arr, n, m)

        for x in ans:
            print(x, end=" ")

        print()
        tc -= 1

# } Driver Code Ends
