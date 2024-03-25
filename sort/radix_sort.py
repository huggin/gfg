# User function Template for python3


def radixSort(arr, n):
    # code here
    BITS_PER_BYTE = 8
    BITS = 32
    R = 1 << BITS_PER_BYTE
    MASK = R - 1
    w = BITS // BITS_PER_BYTE
    aux = [0] * n
    for d in range(w):
        count = [0] * (R + 1)
        for i in range(n):
            c = arr[i] >> (d * BITS_PER_BYTE) & MASK
            count[c + 1] += 1

        for r in range(R):
            count[r + 1] += count[r]

        if d == w - 1:
            shift1 = count[R] - count[R // 2]
            shift2 = count[R // 2]
            for r in range(R // 2):
                count[r] += shift1
            for r in range(R // 2, R):
                count[r] -= shift2

        for i in range(n):
            c = arr[i] >> (d * BITS_PER_BYTE) & MASK
            aux[count[c]] = arr[i]
            count[c] += 1
        temp = aux
        aux = arr
        arr = temp


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        radixSort(arr, n)
        for ele in arr:
            print(ele, end=" ")
        print()
        t = t - 1

# } Driver Code Ends
