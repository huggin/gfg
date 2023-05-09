# User function Template for python3
class Solution:
    def barcketNumbers(self, S):
        # code here
        i = 1
        ans = []
        stack = []
        for s in S:
            if s == "(":
                ans.append(i)
                stack.append(i)
                i += 1
            elif s == ")":
                ans.append(stack[-1])
                stack.pop()

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.barcketNumbers(S)
        for value in answer:
            print(value, end=" ")
        print()


# } Driver Code Ends
