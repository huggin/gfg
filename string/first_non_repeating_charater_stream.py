# User function Template for python3


class Solution:
    def FirstNonRepeating(self, A):
        # Code here
        n = len(A)
        ans = ["#"] * n
        cnt = [0] * 26

        j = 0
        for i in range(n):
            cnt[ord(A[i]) - ord("a")] += 1
            while j <= i and cnt[ord(A[j]) - ord("a")] > 1:
                j += 1
            if j <= i:
                ans[i] = A[j]

        return "".join(ans)


# {
# Driver Code Starts

# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        A = input()
        ob = Solution()
        ans = ob.FirstNonRepeating(A)
        print(ans)

# } Driver Code Ends
