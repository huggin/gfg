# User function Template for python3


def stockBuySell(price, n):
    # code here
    ans = []
    j = 0
    i = 0
    while i < n:
        if i - 1 > j and price[i] < price[i - 1]:
            ans.append((j, i - 1))
            j = i
        elif price[i] < price[j]:
            j = i

        i += 1

    if n - 1 > j and price[n - 1] > price[j]:
        ans.append((j, n - 1))

    if len(ans) == 0:
        print("No Profit")
    else:
        for a in ans:
            print("({} {})".format(a[0], a[1]), end=" ")
        print()


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        price = list(map(int, input().split()))
        stockBuySell(price, n)
# } Driver Code Ends
