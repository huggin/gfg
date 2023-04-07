#User function Template for python3
class Solution:
    def countPairs(self, N, X, numbers): 
        #code here
        s = str(X)
        n = len(s)
        a = []
        for i in range(1, n):
            s1 = s[0:i]
            s2 = s[i:]
            if s2[0] == '0':
                continue
            a.append((int(s1), int(s2)))
        
        dist = {}
        for i in numbers:
            if i not in dist:
                dist[i] = 1
            else:
                dist[i] += 1
        
        ans = 0
        for num in a:
            if num[0] in dist and num[1] in dist:
                if num[0] == num[1]:
                    ans += dist[num[0]] * (dist[num[0]] - 1)
                else:
                    ans += dist[num[0]] * dist[num[1]]
        
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N,X = map(int,input().strip().split())
        numbers = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countPairs(N, X, numbers)
        print(ans)


# } Driver Code Ends
