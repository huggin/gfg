#User function Template for python3

def save_gotham (arr, n) : 
    #Complete the function
    s = []
    ans = []
    for j in range(n-1, -1, -1):
        while len(s) > 0 and s[-1] <= arr[j]:
            s.pop()
        if len(s) == 0:
            ans.append(0)
        else:
            ans.append(s[-1])
        s.append(arr[j])
    
    return sum(ans) % 1000000001



#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    ans = save_gotham(arr, n)
    print(ans)
    





# } Driver Code Ends
