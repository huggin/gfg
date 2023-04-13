#User function Template for python3

class Solution:
    def isValid(self, board):
        # code here
        if board[0] == board[1] and board[0] == board[2]:
            if board[0] == 'O':
                return False
        if board[3] == board[4] and board[3] == board[5]:
            if board[3] == 'O':
                return False
        if board[6] == board[7] and board[6] == board[8]:
            if board[6] == 'O':
                return False
        if board[0] == board[3] and board[0] == board[6]:
            if board[0] == 'O':
                return False
        if board[1] == board[4] and board[1] == board[7]:
            if board[1] == 'O':
                return False
        if board[2] == board[5] and board[2] == board[8]:
            if board[2] == 'O':
                return False

        if board[0] == board[4] and board[0] == board[8]:
            if board[0] == 'O':
                return False
        if board[2] == board[4] and board[2] == board[6]:
            if board[2] == 'O':
                return False
        
        count = board.count('X')
        return True if count == 5 else False
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        board = list(map(str, input().strip().split()))
        ob = Solution()
        ans = ob.isValid(board)
        if ans:
            print("Valid")
        else:
            print("Invalid")
        tc -= 1

# } Driver Code Ends
