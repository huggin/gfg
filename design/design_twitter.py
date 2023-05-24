# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3
import heapq


class Twitter:
    def __init__(self):
        self.time = 0
        self.feed = [[] for _ in range(100001)]
        self.follower = []
        for i in range(100001):
            s = set([i])
            self.follower.append(s)

    # Compose a new tweet
    def postTweet(self, userId: int, tweetId: int):
        # Code here
        self.time += 1
        self.feed[userId].append((self.time, tweetId))

    # Retrieve the 10 most recent tweet ids as mentioned in question
    def getNewsFeed(self, userId: int):
        # Code here
        pq = []
        for id in self.follower[userId]:
            if len(self.feed[id]) > 0:
                heapq.heappush(
                    pq,
                    (
                        -self.feed[id][-1][0],
                        self.feed[id][-1][1],
                        id,
                        len(self.feed[id]) - 1,
                    ),
                )

        ans = []
        while len(ans) < 10 and len(pq) > 0:
            _, tweetId, id, pos = heapq.heappop(pq)
            ans.append(tweetId)
            if pos > 0:
                heapq.heappush(
                    pq,
                    (
                        -self.feed[id][pos - 1][0],
                        self.feed[id][pos - 1][1],
                        id,
                        pos - 1,
                    ),
                )

        return ans

    # Follower follows a followee. If the operation is invalid, it should be a no-op.
    def follow(self, followerId: int, followeeId: int):
        # Code here
        self.follower[followerId].add(followeeId)

    # Follower unfollows a followee. If the operation is invalid, it should be a no-op.
    def unfollow(self, followerId: int, followeeId: int):
        # Code here
        if followerId == followeeId:
            return
        self.follower[followerId].remove(followeeId)


# {
# Driver Code Starts.
if __name__ == "__main__":
    obj = Twitter()
    totalQueries = int(input())
    for _ in range(totalQueries):
        query = list(map(int, input().split()))
        if query[0] == 1:
            userId, tweetId = query[1], query[2]
            obj.postTweet(userId, tweetId)
        elif query[0] == 2:
            userId = query[1]
            vec = obj.getNewsFeed(userId)
            for val in vec:
                print(val, end=" ")
            print()
        elif query[0] == 3:
            follower, followee = query[1], query[2]
            obj.follow(follower, followee)
        else:
            follower, followee = query[1], query[2]
            obj.unfollow(follower, followee)
# } Driver Code Ends
