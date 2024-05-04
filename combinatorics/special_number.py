# User function Template for python3


class Solution:
    def countOfSpeacialNo(self, n, b):
        # Code here
        if n == 1:
            return b
        if n == 2:
            return b
        if n == 3:
            return b * b

        ans = 0
        if n <= 5:
            cnt = [0] * 2 * b
            for i in range(b):
                for j in range(b):
                    cnt[i + j] += 1
            for i in range(len(cnt)):
                ans += cnt[i] * cnt[i]
            if n == 5:
                ans *= b
            return ans

        cnt = [0] * 3 * b
        for i in range(b):
            for j in range(b):
                for k in range(b):
                    cnt[i + j + k] += 1
        ans = 0
        for i in range(len(cnt)):
            ans += cnt[i] * cnt[i]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, b = input().split()
        n = int(n)
        b = int(b)
        obj = Solution()
        ans = obj.countOfSpeacialNo(n, b)
        print(ans)

# } Driver Code Ends
