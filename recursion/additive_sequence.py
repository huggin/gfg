# User function Template for python3


def solve(a, b, s, k, n, start=0):
    if k == n and start > 0:
        return 1
    for i in range(1, n):
        if k + i > n:
            break
        c = int(s[k : k + i])
        if c == a + b:
            return solve(b, c, s, k + i, n, start + 1)
        elif c > a + b:
            return 0
    return 0


def isAdditiveSequence(num):
    # code here
    n = len(num)
    for i in range(1, n):
        for j in range(1, n):
            a = int(num[0:i])
            b = int(num[i : i + j])
            if solve(a, b, num, i + j, n):
                return 1
    return 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        s = input()

        print(isAdditiveSequence(s))
# } Driver Code Ends
