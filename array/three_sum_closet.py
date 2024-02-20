# User function Template for python3

# arr    : list of integers denoting the elements of the array
# target : as specified in the problem statement


class Solution:
    def threeSumClosest(self, arr, target):
        # Your Code Here
        arr.sort()
        n = len(arr)
        ma = 1000000000
        ans = -1
        for i in range(n):
            j, k = i + 1, n - 1
            while j < k:
                temp = arr[i] + arr[j] + arr[k]
                a = abs(temp - target)
                if a < ma or a == ma and temp > ans:
                    ans = temp
                    ma = a
                if temp < target:
                    j += 1
                else:
                    k -= 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

t = int(input())
for tc in range(t):
    n, target = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    print(Solution().threeSumClosest(arr, target))


# } Driver Code Ends
