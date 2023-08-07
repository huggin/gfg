# User function Template for python3
import math


class Solution:
    def countFractions(self, n, numerator, denominator):
        # Your code here
        ans = 0
        dict = {}
        for i in range(n):
            g = math.gcd(numerator[i], denominator[i])
            numerator[i] //= g
            denominator[i] //= g
            if denominator[i] not in dict:
                dict[denominator[i]] = {}
                dict[denominator[i]][numerator[i]] = 1
            else:
                if denominator[i] - numerator[i] in dict[denominator[i]]:
                    ans += dict[denominator[i]][denominator[i] - numerator[i]]
                if numerator[i] in dict[denominator[i]]:
                    dict[denominator[i]][numerator[i]] += 1
                else:
                    dict[denominator[i]][numerator[i]] = 1

        return ans


# {
# Driver Code Starts

# Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    numerator = list(map(int, input().split()))
    denominator = list(map(int, input().split()))
    ob = Solution()
    print(ob.countFractions(n, numerator, denominator))
# } Driver Code Ends
