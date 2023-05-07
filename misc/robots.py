# User function Template for python3


class Solution:
    def moveRobots(self, s1, s2):
        # code here
        n1 = len(s1)
        n2 = len(s2)
        if n1 != n2:
            return "No"

        i, j = 0, 0
        while i < n1 and j < n2:
            while i < n1 and s1[i] == "#":
                i += 1
            while j < n2 and s2[j] == "#":
                j += 1
            if i == n1 and j == n2:
                return "Yes"
            if i == n1 or j == n2:
                return "No"

            if s1[i] == "A" and s2[j] == "B":
                return "No"
            elif s1[i] == "B" and s2[j] == "A":
                return "No"
            elif s1[i] == "A" and i < j:
                return "No"
            elif s1[i] == "B" and i > j:
                return "No"
            i += 1
            j += 1

        return "Yes"


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s1 = input()
        s2 = input()

        ob = Solution()
        print(ob.moveRobots(s1, s2))

# } Driver Code Ends
