#User function Template for python3

class Solution:
    #Complete this function
    # Function for finding maximum AND value.
	def maxAND (self, arr,  n) :
		ans = 0
        for i in range(18, -1, -1):
            temp = []
            for a in arr:
                if a & (1 << i):
                    temp.append(a)
            
            if len(temp) == 2:
                return temp[0] & temp[1]
            elif len(temp) > 2:
                arr = temp
                ans += (1 << i)
        
        return ans
             

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    
    T=int(input())
    
    while(T>0):
        
        
        n=int(input())
        
        arr=[int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxAND(arr,n))
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
