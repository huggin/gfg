# your task is to complete this function
# function should return the missing number
# else return -1
def solve(d, k, s, n, ans):
    if k == n:
        return 1
    m = len(d)
    d2 = s[k : k + m]
    if int(d) + 1 == int(d2):
        return solve(d2, k + m, s, n, ans)
    elif int(d) + 2 == int(d2):
        if ans[0] != -1:
            return 0

        ans[0] = int(d) + 1
        return solve(d2, k + m, s, n, ans)
    else:
        d2 = s[k : k + m + 1]
        if int(d) + 1 == int(d2):
            return solve(d2, k + m + 1, s, n, ans)
        elif int(d) + 2 == int(d2):
            if ans[0] != -1:
                return 0
            ans[0] = int(d) + 1
            return solve(d2, k + m + 1, s, n, ans)

    return 0


def missingNumber(s):
    # Code here
    n = len(s)
    ans = [-1]
    for i in range(1, n // 2 + 1):
        ans[0] = -1
        d = s[0:i]
        if solve(d, i, s, n, ans) and ans[0] != -1:
            return ans[0]

    return -1


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        string = input().strip()
        print(missingNumber(string))
# Contributed by: Harshit Sidhwa

# } Driver Code Ends
