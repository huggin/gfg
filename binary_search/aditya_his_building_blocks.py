# User function Template for python3


def maximised_height(arr, n, m):
    # Complete the function
    lo = min(arr)
    hi = max(arr) + m
    ans = -1
    while lo <= hi:
        mi = (lo + hi) // 2
        if ok(arr, n, mi, m):
            ans = mi
            lo = mi + 1
        else:
            hi = mi - 1
    return ans


def ok(a, n, mi, m):
    ans = 0
    for i in range(n):
        if a[i] < mi:
            ans += mi - a[i]

    return ans <= m


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    ans = maximised_height(arr, n, m)
    print(ans)


# } Driver Code Ends
