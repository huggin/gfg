# User function Template for python3


class Solution:
    def minSprinkler(self, arr, N):
        # your code goes here
        a = []
        for i in range(N):
            a.append((i - arr[i], i + arr[i]))

        a.sort()
        ans = 1
        left, right = 0, a[0][1]
        for i in range(1, N):
            if right >= N - 1:
                break
            if a[i][0] <= left:
                right = max(right, a[i][1])
            else:
                ans += 1
                left = right + 1
                right = a[i][1]

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        arr = [int(i) for i in input().split()]
        print(Solution().minSprinkler(arr, n))
# } Driver Code Ends
