# User function Template for python3


def word(k, ans):
    dist = {
        1: "one",
        2: "two",
        3: "three",
        4: "four",
        5: "five",
        6: "six",
        7: "seven",
        8: "eight",
        9: "nine",
    }
    dist2 = {
        10: "ten",
        11: "eleven",
        12: "twelve",
        13: "thirteen",
        14: "fourteen",
        15: "fifteen",
        16: "sixteen",
        17: "seventeen",
        18: "eighteen",
        19: "nineteen",
    }
    dist3 = {
        2: "twenty",
        3: "thirty",
        4: "forty",
        5: "fifty",
        6: "sixty",
        7: "seventy",
        8: "eighty",
        9: "ninety",
    }
    if k >= 100:
        ans.append(dist[k // 100])
        ans.append("hundred")
        k %= 100
        if k > 0:
            ans.append("and")

    if 10 <= k <= 19:
        ans.append(dist2[k])
        return

    k1 = k // 10
    k2 = k % 10
    if k1 != 0:
        ans.append(dist3[k1])
    if k2 != 0:
        ans.append(dist[k2])


class Solution:
    def convertToWords(self, n):
        # code here
        ans = []
        while n > 0:
            if n >= 10000000:
                k = n // 10000000
                n %= 10000000
                word(k, ans)
                ans.append("crore")
            elif n >= 100000:
                k = n // 100000
                n %= 100000
                word(k, ans)
                ans.append("lakh")
            elif n >= 1000:
                k = n // 1000
                n %= 1000
                word(k, ans)
                ans.append("thousand")
            else:
                if len(ans) != 0 and n < 100:
                    ans.append("and")
                word(n, ans)
                n = 0

        return " ".join(ans)


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.convertToWords(n)
        print(ans)
        tc -= 1

# } Driver Code Ends
