# User function Template for python3
from collections import OrderedDict
from collections import defaultdict


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.freq = defaultdict(OrderedDict)
        self.min_freq = 0
        self.size = 0

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        value, freq = self.cache[key]
        del self.freq[freq][key]

        if not self.freq[self.min_freq]:
            self.min_freq += 1

        self.freq[freq + 1][key] = value
        self.cache[key] = (value, freq + 1)
        return value

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.cache:
            self.cache[key] = (value, self.cache[key][1])
            self.get(key)
            return

        if self.size == self.capacity:
            del_key, _ = self.freq[self.min_freq].popitem(last=False)
            del self.cache[del_key]
            self.size -= 1

        self.cache[key] = (value, 1)
        self.freq[1][key] = value
        self.min_freq = 1
        self.size += 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        capacity = int(input())
        obj = LFUCache(capacity)
        runs = int(input())
        for testCase in range(runs):
            queryType = int(input())
            if queryType == 1:
                key = int(input())
                param_1 = obj.get(key)
                print(param_1)
            else:
                key, val = list(map(int, input().split()))
                obj.put(key, val)
# } Driver Code Ends
