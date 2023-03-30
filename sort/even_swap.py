#User function Template for python3

class Solution():
    def lexicographicallyLargest(self, a, n):
        #your code here
        ans = []
        j = 0
        for i in range(len(a)):
            if (a[i] - a[j]) % 2:
                t = a[j:i]
                t.sort(reverse=True)
                ans.extend(t)
                j = i
        
        t = a[j:len(a)]
        t.sort(reverse=True)
        ans.extend(t)
        
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        a = [int(i) for i in input().split()]
        ans = Solution().lexicographicallyLargest(a, n)
        for i in ans:
            print(i,end=" ")
        print()

# } Driver Code Ends
