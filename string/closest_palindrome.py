# User function Template for python3
def calc(a, n, k):
    start = (n - 1) // 2
    if k > 0:
        while start >= 0 and a[start] == "9":
            a[start] = "0"
            a[n - 1 - start] = "0"
            start -= 1
        a[start] = str(int(a[start]) + 1)
        a[n - 1 - start] = a[start]
    else:
        while start >= 0 and a[start] == "0":
            a[start] = "9"
            a[n - 1 - start] = "9"
            start -= 1
        a[start] = str(int(a[start]) - 1)
        a[n - 1 - start] = a[start]

    return int("".join(a))


class Solution:
    def closestPalindrome(self, num):
        # Code
        for i in range(1, 14):
            if num == 10**i:
                return num - 1
        s = str(num)
        a = [c for c in s]
        n = len(s)
        for i in range(n // 2):
            a[n - 1 - i] = a[i]

        k = 1
        num1 = int("".join(a))
        # print(num1)
        if num1 == num:
            return num
        elif num1 > num:
            k = -1

        num2 = calc(a, n, k)
        if (
            abs(num1 - num) < abs(num2 - num)
            or abs(num1 - num) == abs(num2 - num)
            and num1 < num2
        ):
            return num1

        return num2


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        num = int(input())
        obj = Solution()
        ans = obj.closestPalindrome(num)
        print(ans)

# } Driver Code Ends
