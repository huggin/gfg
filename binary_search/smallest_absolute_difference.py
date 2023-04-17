# User function Template for python3
import bisect


def ok(a, n, mid, k):
    cnt = 0
    for i in range(n):
        cnt += n - bisect.bisect(a, a[i] + mid)

    return n * (n - 1) // 2 - cnt >= k


def kthDiff(a, n, k):
    a.sort()
    lo = min(a[i + 1] - a[i] for i in range(n - 1))
    hi = a[-1] - a[0]
    if k >= n * (n - 1) // 2:
        return hi
    ans = -1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if ok(a, n, mid, k):
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1

    return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())

        print(kthDiff(a, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
