# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3

class Solution:
    def check(self, pre, l1, r1, ino, l2, r2, post, l3, r3):
        if l2 > r2:
            return True

        if pre[l1] != post[r3]:
            return False

        try:
            idx = ino.index(pre[l1])
        except ValueError:
            return False

        return self.check(pre, l1+1, idx-l2+l1, ino, l2, idx-1, post, l3, l3+idx-l2-1) \
            and self.check(pre, r1+1-r2+idx, r1, ino, idx+1, r2, post, r3+idx-r2, r3-1)

    def checktree(self, preorder, inorder, postorder, N):
        # Your code goes here
        return self.check(preorder, 0, N-1, inorder, 0, N-1, postorder, 0, N-1)


# {
 # Driver Code Starts.
# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        preorder = list(map(int, input().strip().split()))
        inorder = list(map(int, input().strip().split()))
        postorder = list(map(int, input().strip().split()))
        obj = Solution()
        if (obj.checktree(preorder, inorder, postorder, n)):
            print("Yes")
        else:
            print("No")


# } Driver Code Ends
