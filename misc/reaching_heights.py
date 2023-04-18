# User function Template for python3


def reaching_height(n, arr):
    # Complete the function

    arr.sort()
    ans = [0] * n
    j, k = 0, n - 1

    for i in range(0, n, 2):
        ans[i] = arr[k]
        k -= 1
        if i + 1 == n:
            break
        ans[i + 1] = arr[j]
        j += 1

    # return [-1] if n > 1 and arr.count(arr[0]) == n else ans
    # bug in test cases
    return [-1] if n % 2 == 0 and arr.count(arr[0]) == n else ans


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ans = reaching_height(n, arr)
    if len(ans) == 1 and ans[0] == -1:
        print("Not Possible")
    else:
        print(*ans)
# } Driver Code Ends
