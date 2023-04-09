#User function Template for python3
from collections import Counter
class Solution:

	def matchPairs(self,nuts, bolts, n):
		# code here
		c1 = Counter(nuts)
		c2 = Counter(bolts)
		s = "!#$%&*@^~"
		ans = []
		for i in s:
		    if c1[i] > 0 and c2[i] > 0:
		        ans.extend(min(c1[i], c2[i]) * [i])
		
		nuts[:] = ans
		bolts[:] = ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        nuts = list(map(str, input().strip().split()))
        bolts = list(map(str, input().strip().split()))
        ob = Solution()
        ob.matchPairs(nuts, bolts, n)
        for x in nuts:
            print(x, end=" ")
        print()
        for x in bolts:
            print(x, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
