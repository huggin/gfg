//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int ans = -1;
        int j = 0;
        int used = 0;
        int c[256] = {0};
        for(int i = 0; i < s.size(); ++i) {
            if (c[s[i]]++ == 0) {
                used++;
            }
            if (used == k) {
                ans = max(i-j+1, ans);
            } else if (used > k) {
                while (--c[s[j]] != 0) {
                    ++j;
                }
                --used;
                ++j;
                ans = max(i-j+1, ans);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
