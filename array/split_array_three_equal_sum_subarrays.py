# User function Template for python3
class Solution:

    def findSplit(self, arr):
        # Return an array of possible answer, driver code will judge and return true or false based on
        s = sum(arr)
        if s % 3 != 0:
            return [-1, -1]
        s //= 3
        ans = []
        curr = 0
        for i in range(len(arr)):
            if len(ans) == 2:
                break
            curr += arr[i]
            if curr == s:
                if i != len(arr) - 1:
                    ans.append(i)
                curr = 0
            elif curr > s:
                return []

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == "__main__":
    t = int(input())
    while t:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.findSplit(arr)

        if (result == [-1, -1]) or len(result) != 2:
            print("false")

        else:
            sum1 = sum2 = sum3 = 0
            for i in range(len(arr)):
                if i <= result[0]:
                    sum1 += arr[i]
                elif i <= result[1]:
                    sum2 += arr[i]
                else:
                    sum3 += arr[i]

            if sum1 == sum2 == sum3:
                print("true")
            else:
                print("false")
        print("~")
# } Driver Code Ends
