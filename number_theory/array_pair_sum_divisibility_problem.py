# User function Template for python3


class Solution:
    def canPair(self, a, k):
        # Code here
        cnt = [0] * k
        for b in a:
            cnt[b % k] += 1

        if cnt[0] % 2 == 1 or k % 2 == 0 and cnt[k // 2] % 2 == 1:
            return False

        for i in range(1, k // 2):
            if cnt[i] != cnt[k - i]:
                return False

        return True


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, k = input().split()
        n = int(n)
        k = int(k)
        nums = list(map(int, input().split()))
        ob = Solution()
        ans = ob.canPair(nums, k)
        if ans:
            print("True")
        else:
            print("False")
# } Driver Code Ends
