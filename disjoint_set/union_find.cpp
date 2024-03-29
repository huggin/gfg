//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int head(int par[], int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

public:
  // Function to merge two nodes a and b.
  void union_(int a, int b, int par[], int rank1[]) {
    // code here
    int h1 = head(par, a);
    int h2 = head(par, b);
    if (h1 == h2)
      return;
    if (rank1[h1] > rank1[h2]) {
      par[h2] = h1;
      rank1[h1] = rank1[h1] + rank1[h2];
    } else {
      par[h1] = h2;
      rank1[h2] = rank1[h1] + rank1[h2];
    }
  }

  // Function to check whether 2 nodes are connected or not.
  bool isConnected(int x, int y, int par[], int rank1[]) {
    // code here
    return head(par, x) == head(par, y);
  }
};

//{ Driver Code Starts.

int main() {
  // taking number of testcases
  int t;
  cin >> t;
  while (t--) {
    // taking number of elements
    int n;
    cin >> n;

    int par[n + 1];
    int rank1[n + 1];

    // initializing the parent and
    // the rank array
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      rank1[i] = 1;
    }

    // taking number of queries
    Solution obj;
    int q;
    cin >> q;
    while (q--) {
      int a, b;
      char c;
      cin >> c >> a >> b;

      // if query type is 'U'
      // then calling union_ method
      if (c == 'U') {
        obj.union_(a, b, par, rank1);
      } else // else calling isConnected() method
        cout << obj.isConnected(a, b, par, rank1) << endl;
    }
  }
  return 0;
}

// } Driver Code Ends
