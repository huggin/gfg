#User function Template for python3

class Solution:
    def decodedString(self, s : str) -> str:
        # code here
        
        stack = []
        for c in s:
            if c == ']':
                substr = ''
                while stack[-1] != '[':
                    substr = stack.pop() + substr
                stack.pop()  # remove '['
                num = ''
                while stack and stack[-1].isdigit():
                    num = stack.pop() + num
                stack.append(int(num) * substr)
            else:
                stack.append(c)
        return ''.join(stack)
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        
        ob = Solution()
        print(ob.decodedString(s))
# } Driver Code Ends
