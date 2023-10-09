# User function Template for python3


class Solution:
    def getMaxandMinProduct(self, arr, n):
        # Your code goes here
        if n == 1:
            return [arr[0], arr[0]]

        prod = 1
        cnt = 0
        neg = -10
        pos = 10
        neg_cnt = 0
        for a in arr:
            if a == 0:
                cnt += 1
            else:
                prod *= a
                if a < 0:
                    neg_cnt += 1
                    neg = max(a, neg)
                else:
                    pos = min(a, pos)

        if cnt == n:
            return [0, 0]

        if neg == -10:
            if prod > 0:
                if cnt > 0:
                    return [0, prod]
                else:
                    return [pos, prod]

        if prod > 0:
            return [prod // neg, prod]
        else:
            if neg_cnt == 1 and cnt == n - 1:
                return [prod, 0]
            else:
                return [prod, prod // neg]


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        product = ob.getMaxandMinProduct(a, n)
        print(product[1], end=" ")
        print(product[0])

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
