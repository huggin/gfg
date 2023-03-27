# You are required to complete this fucntion
# Function should return the an integer
def countValues(n):
    # Code here
    ans = 0
    for i in range(n):
        if (i + n) == (i ^ n):
            ans += 1
    return ans


#{ 
 # Driver Code Starts
# Your code goes here
if __name__=='__main__':
    t =int(input())
    for i in range(t):
        n = int(input().strip())
        print(countValues(n))
# Contributed By: Harshit Sidhwa

# } Driver Code Ends
