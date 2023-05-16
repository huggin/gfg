# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def nextGreaterElement(self, N, arr):
        # Code here
        ans = [-2] * N
        ma = max(arr)
        pos = -1
        for i in range(N):
            if arr[i] == ma:
                ans[i] = -1
                pos = i

        stack = [ma]
        for i in range(N - 1, -1, -1):
            j = (i + pos) % N
            if ans[j] == -1:
                stack[:] = [ma]
            else:
                while stack[-1] <= arr[j]:
                    stack.pop()
                ans[j] = stack[-1]
                stack.append(arr[j])

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.nextGreaterElement(N, arr)
        for val in res:
            print(val, end=" ")
        print()
# } Driver Code Ends
