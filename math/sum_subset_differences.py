# Your task is to complete this function
# Your function should return desired Answer
def sumDiff(S, n):
    # Code here
    p = [1] * (n + 1)
    for i in range(1, n + 1):
        p[i] = p[i - 1] * 2

    ans = 0
    for i in range(n):
        ans += S[i] * p[i] - S[i] * p[n - 1 - i]
    return ans


# {
# Driver Code Starts
# Your Code goes here
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(sumDiff(arr, n))
# Contributed By: Harshit Sidhwa
# } Driver Code Ends
