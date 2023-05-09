//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
  int petrol;
  int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution {
public:
  // Function to find starting point where the truck can start to get through
  // the complete circle without exhausting its petrol in between.
  int tour(petrolPump p[], int n) {
    // Your code here
    int t = 0;
    for (int i = 0; i < n; ++i) {
      t += p[i].petrol - p[i].distance;
    }
    if (t < 0)
      return -1;
    deque<int> Q;
    int c = 0;
    int i = 0;
    while (Q.size() != n) {
      if (c >= 0) {
        c += p[i].petrol - p[i].distance;
        Q.push_back(i);
        i = (i + 1) % n;
      } else {
        while (!Q.empty() && c < 0) {
          auto j = Q.front();
          Q.pop_front();
          c -= p[j].petrol - p[j].distance;
        }
      }
    }
    return Q.front();
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++)
      cin >> p[i].petrol >> p[i].distance;
    Solution obj;
    cout << obj.tour(p, n) << endl;
  }
}

// } Driver Code Ends
