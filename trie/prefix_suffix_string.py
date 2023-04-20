# {
# Driver Code Starts
# Initial Template for Python 3


# } Driver Code Ends
# User function Template for python3
class TrieNode:
    def __init__(self):
        self.children = {}


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def put(self, word):
        node = self.root
        for c in word:
            if not c in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]

    def get(self, word):
        node = self.root
        for c in word:
            if not c in node.children:
                return False
            node = node.children[c]

        return True


class Solution:
    def prefixSuffixString(self, s1, s2) -> int:
        # code here
        trie = Trie()
        for s in s1:
            trie.put(s)
            trie.put(reversed(s))

        ans = 0
        for s in s2:
            if trie.get(s):
                ans += 1
            elif trie.get(reversed(s)):
                ans += 1

        return ans


# {
# Driver Code Starts.

if __name__ == "__main__":
    for _ in range(int(input())):
        s1 = list(map(str, input().split()))
        s2 = list(map(str, input().split()))
        obj = Solution()
        print(obj.prefixSuffixString(s1, s2))
# } Driver Code Ends
