//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  bool game(int a, int b) {
    // Code Here
    int diff = abs(a - b);
    double gr = (1 + sqrt(5)) / 2;
    double temp = gr * diff;
    return min(a, b) != (int)temp;
  }
};

//{ Driver Code Starts.

int main() {
  Solution obj;
  int tt;
  int a, b;
  cin >> tt;
  while (tt--) {
    cin >> a >> b;
    bool dolly = obj.game(a, b);
    puts(dolly ? "Dolly" : "Bunty");
  }
  return 0;
}
// } Driver Code Ends
