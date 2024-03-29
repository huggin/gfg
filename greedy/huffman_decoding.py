# User function Template for python3

"""
class MinHeapNode:
    def __init__(self, data, freq):
        self.data = data
        self.freq = freq
        self.left = None
        self.right = None
"""


# Function to return the decoded string.
def decodeHuffmanData(root, binaryString):
    # your code here
    ans = []

    i = 0
    n = len(binaryString)

    def build(s, i):
        p = root
        j = i
        while j < n:
            if s[j] == "0":
                p = p.left
            else:
                p = p.right
            if p.data != "$":
                return p.data, j - i + 1
            j += 1
        return "$", -1

    while i < n:
        c, l = build(binaryString, i)
        i += l
        ans.append(c)

    return "".join(ans)


# {
# Driver Code Starts
# Initial Template for Python 3

import heapq

minheap = []
heapq.heapify(minheap)
cnt = 0
codes = {}
freq = {}


class MinHeapNode:
    def __init__(self, data, freq):
        self.data = data
        self.freq = freq
        self.left = None
        self.right = None


def printCodes(root, strr):
    if root == None:
        return
    if root.data is not "$":
        print(str(root.data) + ": " + strr)
    printCodes(root.left, strr + "0")
    printCodes(root.right, strr + "1")


def storeCodes(root, strr):
    if root == None:
        return
    if root.data is not "$":
        codes[root.data] = strr
    storeCodes(root.left, strr + "0")
    storeCodes(root.right, strr + "1")


def huffmanCodes(s):
    global cnt
    for v in freq:
        heapq.heappush(minheap, (freq[v], freq[v] + cnt, MinHeapNode(v, freq[v])))
        cnt += 1
    while len(minheap) is not 1:
        left = minheap[0][2]
        heapq.heappop(minheap)
        right = minheap[0][2]
        heapq.heappop(minheap)
        top = MinHeapNode("$", left.freq + right.freq)
        top.left = left
        top.right = right
        heapq.heappush(minheap, (top.freq, top.freq + cnt, top))
        cnt += 1
    storeCodes(minheap[0][2], "")


def calcFreq(strr, n):
    for i in range(n):
        if strr[i] not in freq:
            freq[strr[i]] = 1
        else:
            freq[strr[i]] += 1


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        strr = input()
        encodedString = ""
        decodedString = ""
        calcFreq(strr, len(strr))
        # print(freq)
        huffmanCodes(len(strr))
        # print(codes)
        for i in strr:
            encodedString += codes[i]

        decodedString = decodeHuffmanData(minheap[0][2], encodedString)
        print(decodedString)
        t = t - 1


# } Driver Code Ends
