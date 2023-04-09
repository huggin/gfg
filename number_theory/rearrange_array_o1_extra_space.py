#User function Template for python3

##Complete this code

class Solution:
    #Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    #with O(1) extra space.
    def arrange(self,arr, n): 
        #Your code here
        M = 1000000007
        for i in range(n):
            temp = arr[arr[i]] % M
            arr[i] = temp * M + arr[i] % M
        
        for i in range(n):
            arr[i] = arr[i] // M
        
        return arr

#{ 
 # Driver Code Starts
#Initial Template for Python 3


import math



def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            ob.arrange(arr,n)
            
            for i in arr:
                print(i,end=" ")
            
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends
