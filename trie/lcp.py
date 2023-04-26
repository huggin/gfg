# User function Template for python3


class TrieNode:
    def __init__(self):
        self.children = {}
        self.leaf = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def put(self, s):
        p = self.root
        for c in s:
            if not c in p.children:
                p.children[c] = TrieNode()
            p = p.children[c]

    def get(self, s):
        p = self.root
        for i in range(len(s)):
            if not s[i] in p.children:
                return s[:i]
            p = p.children[s[i]]
        return s


class Solution:
    def LCP(self, arr, n):
        # code here
        root = Trie()
        root.put(arr[0])
        ans = arr[0]
        for i in range(1, n):
            s = root.get(arr[i])
            if len(s) < len(ans):
                ans = s

        return ans if len(ans) else "-1"


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tcs = int(input())
    for _ in range(tcs):
        n = int(input())
        arr = [x for x in input().split()]
        obj = Solution()
        print(obj.LCP(arr, n))
# } Driver Code Ends
