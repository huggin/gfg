# User function Template for python3


class Solution:
    def profession(self, level, pos):
        # code here
        return "d" if bin(pos - 1).count("1") & 1 else "e"


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        level, pos = [int(x) for x in input().split()]

        ob = Solution()
        if ob.profession(level, pos) == "d":
            print("Doctor")
        else:
            print("Engineer")
# } Driver Code Ends
