#User function Template for python3
class Solution:
    def valid(self, s): 
        #code here
        stack = []
        for c in s:
            if c in '([{':
                stack.append(c)
            elif c == ')':
                if len(stack) == 0 or stack[-1] != '(':
                    return 0
                else:
                    stack.pop()
            elif c == ']':
                if len(stack) == 0 or stack[-1] != '[':
                    return 0
                else:
                    stack.pop()
            elif c == '}':
                if len(stack) == 0 or stack[-1] != '{':
                    return 0
                else:
                    stack.pop()
        
        return 1 if len(stack) == 0 else 0
            

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        if ob.valid(s):
            print(1)
        else:
            print(0)
# } Driver Code Ends
