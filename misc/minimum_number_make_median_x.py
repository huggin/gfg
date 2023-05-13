# User function Template for python3
# bug in test cases


class Solution:
    def minimumAppend(self, arr, n, x):
        # Complete the function
        small, big = 0, 0
        same = 0
        biggest_less, smallest_larger = 0, int(1e8)
        for a in arr:
            if a < x:
                small += 1
                biggest_less = max(biggest_less, a)
            elif a > x:
                big += 1
                smallest_larger = min(smallest_larger, a)
            else:
                same = 1

        ans = abs(small - big)
        if same or biggest_less + smallest_larger == 2 * x:
            return ans

        if small == n or big == n:
            return n

        ans += 1
        if small > big and biggest_less + smallest_larger > 2 * x:
            ans -= 1
        elif small < big and biggest_less + smallest_larger < 2 * x:
            ans -= 1

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
