# User function Template for python3

class Solution:
    def nearestSmallestTower(self, arr):
        # code here
        s = []
        n = len(arr)

        left = [-1] * n
        right = [-1] * n
        for i in range(n):
            while len(s) > 0 and arr[s[-1]] >= arr[i]:
                s.pop()
            if len(s) == 0:
                left[i] = -1
            else:
                left[i] = s[-1]
            s.append(i)

        s = []
        for i in range(n-1, -1, -1):
            while len(s) > 0 and arr[s[-1]] >= arr[i]:
                s.pop()

            if len(s) == 0:
                right[i] = -1
            else:
                right[i] = s[-1]
            s.append(i)

        ans = [-1] * n
        for i in range(n):
            if left[i] == -1:
                ans[i] = right[i]
            elif right[i] == -1:
                ans[i] = left[i]
            elif i - left[i] < right[i] - i or i - left[i] == right[i] - i and arr[left[i]] <= arr[right[i]]:
                ans[i] = left[i]
            else:
                ans[i] = right[i]
        return ans

# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    for _ in range(int(input().strip())):
        N = int(input())
        arr = [int(i) for i in input().strip().split()]
        obj = Solution()
        ans = obj.nearestSmallestTower(arr)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
