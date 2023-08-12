class Solution:
    def nthFibonacci(self, n: int) -> int:
        # code here
        m = int(1e9 + 7)
        a, b = 1, 1
        for i in range(2, n):
            a, b = a + b, a
            if a > m:
                a -= m
        return a


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        obj = Solution()
        res = obj.nthFibonacci(n)

        print(res)


# } Driver Code Ends
