# User function Template for python3
def inv(a, m):
    b = m - 2
    ans = 1
    while b:
        if b & 1:
            ans = ans * a % m
        a = a * a % m
        b >>= 1
    return ans


def getAnswer(arr, n, k, x):
    # Your code goes here
    M = int(1e9 + 7)
    arr.sort()
    ans = 0
    j = 0
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % M

    for i in range(n):
        while j < n and arr[j] - arr[i] <= x:
            j += 1
        if j - i >= k:
            ans = (
                ans + fact[j - i - 1] * inv(fact[k - 1] * fact[j - i - k], M) % M
            ) % M

    return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        sz = [int(x) for x in input().strip().split()]
        n, k, x = sz[0], sz[1], sz[2]
        arr = [int(x) for x in input().strip().split()]
        print(getAnswer(arr, n, k, x))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
