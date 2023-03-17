//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
  int id;      // Job Id
  int dead;    // Deadline of job
  int profit;  // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
 public:
  // Function to find the maximum profit and the number of jobs done.
  vector<int> JobScheduling(Job arr[], int n) {
    // your code here
    sort(arr, arr + n, [](Job l, Job r) {
      if (l.profit > r.profit) return true;
      if (l.profit < r.profit) return false;
      if (l.dead < r.dead) return true;
      return false;
    });

    vector<int> used(100);
    int ans = 0;
    int k = 0;
    for (int i = 0; i < n; ++i) {
      // cout << arr[i].dead << ' ' << arr[i].profit << endl;
      for (int j = arr[i].dead - 1; j >= 0; --j) {
        if (used[j] == 0) {
          ++k;
          ans += arr[i].profit;
          used[j] = 1;
          break;
        }
      }
    }
    return vector<int>{k, ans};
  }
};

//{ Driver Code Starts.
// Driver program to test methods
int main() {
  int t;
  // testcases
  cin >> t;

  while (t--) {
    int n;

    // size of array
    cin >> n;
    Job arr[n];

    // adding id, deadline, profit
    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      arr[i].id = x;
      arr[i].dead = y;
      arr[i].profit = z;
    }
    Solution ob;
    // function call
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}

// } Driver Code Ends
