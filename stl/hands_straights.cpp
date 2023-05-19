//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if (N % groupSize) {
            return false;
        }
        multiset<int> s;
        for(int a : hand) {
            s.insert(a);
        }
        for(int i = 0; i < N / groupSize; ++i) {
            auto it = s.begin();
            int curr = *it;
            for(int j = 0; j < groupSize; ++j) {
                auto it2 = s.find(curr+j);
                if (it2 == s.end()) {
                    return false;
                }
                s.erase(it2);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
