# User function Template for python3


class Solution:
    def Search(self, n, arr, k):
        # code here
        lo, hi = 0, n - 1
        while lo <= hi:
            if hi - lo <= 5:
                return 1 if k in arr[lo : hi + 1] else 0
            mid = (lo + hi) // 2
            if arr[mid] == k or arr[lo] == k or arr[hi] == k:
                return 1
            elif arr[lo] == arr[hi] and arr[lo] == arr[mid]:
                lo += 1
                hi -= 1
            elif arr[lo] < arr[mid] or (arr[lo] == arr[mid] and arr[mid] > arr[hi]):
                if arr[lo] < k and k < arr[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            elif arr[hi] >= arr[mid] or (arr[hi] == arr[mid] and arr[mid] < arr[lo]):
                if arr[mid] < k and k < arr[hi]:
                    lo = mid + 1
                else:
                    hi = mid + 1

        return 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        ans = ob.Search(n, arr, k)
        print(ans)
        tc -= 1
# } Driver Code Ends
