# User function Template for python3


class Solution:
    def find_xor(self, n):
        # Code here
        s = bin(n)
        one = 0
        zero = 0
        for i in range(2, len(s)):
            if s[i] == "0":
                zero += 1
            else:
                one += 1

        return one ^ zero


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.find_xor(n)
        print(ans)

# } Driver Code Ends
