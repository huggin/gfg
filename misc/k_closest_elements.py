# User function Template for python3
import bisect


class Solution:
    def printKClosest(self, arr, n, k, x):
        # code here
        i = bisect.bisect_left(arr, x)
        j = i - 1
        ans = []
        while len(ans) < k:
            if j < 0 and i == n:
                break
            if i == n:
                ans.append(arr[j])
                j -= 1
            elif arr[i] == x:
                i += 1
            elif j < 0:
                ans.append(arr[i])
                i += 1
            elif arr[i] - x <= x - arr[j]:
                ans.append(arr[i])
                i += 1
            else:
                ans.append(arr[j])
                j -= 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k, x = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.printKClosest(arr, n, k, x)
        for xx in ans:
            print(xx, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
