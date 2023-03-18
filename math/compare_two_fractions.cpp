//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  string compareFrac(string s) {
    // Code here
    int a, b, c, d;
    sscanf(s.c_str(), "%d/%d, %d/%d", &a, &b, &c, &d);
    if (a * d == c * b) return "equal";
    char buf[32];

    if (a * d > c * b) {
      sprintf(buf, "%d/%d", a, b);
    } else {
      sprintf(buf, "%d/%d", c, d);
    }
    return buf;
  }
};

//{ Driver Code Starts.

int main() {
  Solution ob;
  int t;
  cin >> t;
  cin.ignore();
  for (int i = 0; i < t; i++) {
    string s;
    getline(cin, s);

    cout << ob.compareFrac(s) << endl;
  }
  return 0;
}

// } Driver Code Ends
