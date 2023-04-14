from typing import List
from collections import defaultdict

class Solution:
    def totalTime(self, n : int, arr : List[int], time : List[int]) -> int:
        # code here
        finish = defaultdict(int)
        ans = 0
        for i in range(n):
            if arr[i] in finish and finish[arr[i]] + time[arr[i]-1] > ans: 
                ans = finish[arr[i]] + time[arr[i]-1]
            temp = ans
            finish[arr[i]] = temp
            ans += 1

        return temp
        
#{ 
 # Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        arr=IntArray().Input(n)
        
        
        time=IntArray().Input(n)
        
        obj = Solution()
        res = obj.totalTime(n, arr, time)
        
        print(res)
        

# } Driver Code Ends
