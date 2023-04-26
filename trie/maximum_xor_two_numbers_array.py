# User function Template for python3
class Trie:
    def __init__(self):
        self.root = {}

    def put(self, num):
        node = self.root
        for i in range(30, -1, -1):
            bit = (num >> i) & 1
            if not bit in node:
                node[bit] = {}
            node = node[bit]

    def get(self, num):
        node = self.root
        ans = 0
        for i in range(30, -1, -1):
            bit = (num >> i) & 1
            op_bit = 1 - bit
            if op_bit in node:
                node = node[op_bit]
                ans |= 1 << i
            else:
                node = node[bit]

        return ans


class Solution:
    def max_xor(self, arr, n):
        # code here
        t = Trie()
        for a in arr:
            t.put(a)

        ans = 0
        for a in arr:
            ans = max(ans, t.get(a))

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.max_xor(arr, n))

# } Driver Code Ends
