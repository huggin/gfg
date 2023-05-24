//{ Driver Code Starts
// Initial Template for C++

// {Driver code starts
#include <bits/stdc++.h>
using namespace std;

//}Driver code ends

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int uglyNumber(int n) {
    // your code here
    unordered_set<long long> marked;
    priority_queue<long long, vector<long long>, greater<long long>> Q;
    Q.push(1);
    marked.insert(1);
    while (n > 0) {
      long long curr = Q.top();
      Q.pop();
      if (--n == 0) {
        return curr;
      }
      if (marked.find(curr * 2) == marked.end()) {
        marked.insert(curr * 2);
        Q.push(curr * 2);
      }
      if (marked.find(curr * 3) == marked.end()) {
        marked.insert(curr * 3);
        Q.push(curr * 3);
      }
      if (marked.find(curr * 5) == marked.end()) {
        marked.insert(curr * 5);
        Q.push(curr * 5);
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.

//{Driver code starts
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solution ob;
    int res;
    res = ob.uglyNumber(n);

    cout << res;
    cout << "\n";
  }
}

// } Driver Code Ends
