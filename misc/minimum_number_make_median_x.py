# User function Template for python3


class Solution:
    def minimumAppend(self, arr, n, x):
        # Complete the function
        small, big = 0, 0
        same = 0
        bl, sg = 0, int(1e8)
        for a in arr:
            if a < x:
                small += 1
                bl = max(bl, a)
            elif a > x:
                big += 1
                sg = min(sg, a)
            else:
                same = 1

        if small == n or big == n:
            return n

        ans = abs(small - big)
        if same or bl + sg == 2 * x:
            return ans

        if bl + sg > 2 * x:
            if small > big:
                return small - big
        else:
            if small < big:
                return big - small

        return ans + 1


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n, K = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    res = Solution().minimumAppend(arr, n, K)
    print(res)


# } Driver Code Ends# User function Template for python3


class Solution:
    def minimumAppend(self, arr, n, x):
        # Complete the function
        small, big = 0, 0
        same = 0
        bl, sg = 0, int(1e8)
        for a in arr:
            if a < x:
                small += 1
                bl = max(bl, a)
            elif a > x:
                big += 1
                sg = min(sg, a)
            else:
                same = 1

        __import__("pdb").set_trace()
        ans = abs(small - big)
        if same or bl + sg == 2 * x:
            return ans

        if bl + sg > 2 * x:
            if small > big:
                return small - big - 1
        else:
            if small < big:
                return big - small - 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n, K = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    res = Solution().minimumAppend(arr, n, K)
    print(res)


# } Driver Code Ends
