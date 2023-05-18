# User function Template for python3


class Solution:
    def delta(self, Arr, i, j, k):
        ans = Arr[0][i] * Arr[1][j] * Arr[2][k]
        ans += Arr[0][j] * Arr[1][k] * Arr[2][i]
        ans += Arr[0][k] * Arr[1][i] * Arr[2][j]
        ans -= Arr[0][i] * Arr[1][k] * Arr[2][j]
        ans -= Arr[0][j] * Arr[1][i] * Arr[2][k]
        ans -= Arr[0][k] * Arr[1][j] * Arr[2][i]

        return ans

    def myCalculator(self, Arr):
        # code here
        d = self.delta(Arr, 0, 1, 2)
        p = self.delta(Arr, 3, 1, 2)
        q = self.delta(Arr, 0, 3, 2)
        r = self.delta(Arr, 0, 1, 3)
        if d == 0:
            if p == 0 and r == 0 and q == 0:
                return [1]
            else:
                return [0]

        return [int(p // d), int(q // d), int(r // d)]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        Arr = []
        for i in range(3):
            arr = input().split()
            for itr in range(4):
                arr[itr] = float(arr[itr])
            Arr.append(arr)

        ob = Solution()
        ans = ob.myCalculator(Arr)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
