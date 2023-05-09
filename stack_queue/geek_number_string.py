# User function Template for python3


class Solution:
    def minLength(self, s, n):
        # code here
        stack = []
        for c in s:
            if len(stack) == 0:
                stack.append(c)
            elif c == "1" and stack[-1] == "2":
                stack.pop()
            elif c == "2" and stack[-1] == "1":
                stack.pop()
            elif c == "3" and stack[-1] == "4":
                stack.pop()
            elif c == "4" and stack[-1] == "3":
                stack.pop()
            elif c == "5" and stack[-1] == "6":
                stack.pop()
            elif c == "6" and stack[-1] == "5":
                stack.pop()
            elif c == "7" and stack[-1] == "8":
                stack.pop()
            elif c == "8" and stack[-1] == "7":
                stack.pop()
            elif c == "9" and stack[-1] == "0":
                stack.pop()
            elif c == "0" and stack[-1] == "9":
                stack.pop()
            else:
                stack.append(c)

        return len(stack)


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        ob = Solution()
        print(ob.minLength(s, n))
# } Driver Code Ends
