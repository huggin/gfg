//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> m;
        while (i < N) {
            m[fruits[i]]++;
            if (m.size() <= 2) {
                ans = max(ans, i - j + 1);
            } else {
                while (j < N) {
                    if (--m[fruits[j]] == 0) {
                        m.erase(fruits[j]);
                    }
                    ++j;
                    ans = max(ans, i - j + 1);
                    break;
                }
            }
            ++i;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends
