# User function Template for python3
class Solution:
    def solve(self, s, k, curr, c):
        if k == len(s):
            self.ans = 0
            for i in curr:
                self.ans = self.ans * 10 + i
            self.found = True
            return True

        if s[k] == 'I':
            for i in range(curr[-1]+1, 10):
                if i in curr:
                    continue
                curr.append(i)
                if self.solve(s, k+1, curr, i):
                    return True
                curr.pop()
        else:
            for i in range(curr[-1]-1, 0, -1):
                if i in curr:
                    continue
                curr.append(i)
                if self.solve(s, k+1, curr, i):
                    return True
                curr.pop()

        return False

    def printMinNumberForPattern(self, S):
        # code here
        self.found = False
        curr = []
        for i in range(1, 10):
            curr.append(i)
            if self.solve(S, 0, curr, i):
                return self.ans
            curr.pop()

        return -1


# {
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        S = str(input())

        ob = Solution()
        print(ob.printMinNumberForPattern(S))
# } Driver Code Ends
