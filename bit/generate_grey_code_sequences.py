# Your task is to complete this function
# Function should return a list of all the Grey Code Generated
class Solution:
    def generateCode(self, n):
        # Code here
        return ["{:0{n}b}".format(x ^ (x >> 1), n=n) for x in range(1 << n)]


# {
# Driver Code Starts


# Driver Program

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        res = Solution().generateCode(int(input()))
        for j in range(len(res)):
            print(res[j], end=" ")
        print()


# Contributed By: Harshit Sidhwa

# } Driver Code Ends
