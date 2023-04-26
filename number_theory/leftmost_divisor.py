# User function Template for python3
class Solution:
    def leftMostDiv(self, p, q):
        # code here
        a = p**q
        s = str(a)
        if len(s) > 18:
            s = s[0:10]
        a = int(s)
        for i in s:
            d = int(i)
            if d == 0:
                continue
            if a % d == 0:
                return i
        return -1


# {
# Driver Code Starts
# Initial Template for Python 3

# Initial Template for Python 3
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        p, q = input().split()
        p = int(p)
        q = int(q)
        ob = Solution()
        print(ob.leftMostDiv(p, q))

# } Driver Code Ends
