#User function Template for python3

class Solution:
    def maxOnes(self, a, n):
        # Your code goes here
        if a.count(1) == n:
            return n
        
        prefix = [0] * n
        suffix = [0] * n
        if a[0] == 1:
            prefix[0] = 1
        for i in range(1, n):
            prefix[i] += prefix[i-1] + a[i]
            
        if a[n-1] == 1:
            suffix[n-1] = 1
        for i in range(n-2, -1, -1):
            suffix[i] += suffix[i+1] + a[i]
        
        ans = 0
        j = -1
        tt = 0
        for i in range(n):
            if a[i] == 1:
                tt += 1
            else:
                if tt >= 0:
                    tt = -1
                    j = i
                else:
                    tt -= 1
                    
                if j != -1:
                    ans = max(ans, -tt + prefix[i] + suffix[i])
                
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob=Solution()
        print(ob.maxOnes(a, n))

        T -= 1


if __name__ == "__main__":
    main()



# } Driver Code Ends
