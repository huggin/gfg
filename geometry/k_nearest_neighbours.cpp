//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Point {
  int grp;
  double x, y;
  double distance;
};

/*
A utility structure to store the info of points
x and y represents the 2D coordinates of the points
grp represents to which particular point belongs
struct Point
{
        int grp;
        double x, y;
        double distance;
};
*/
// function should return to which grp
// the test data will belong
int classifyAPoint(Point arr[], int n, int k, Point test);

// Driver code
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    Point arr[n], test;
    for (int i = 0; i < n; i++)
      cin >> arr[i].x >> arr[i].y >> arr[i].grp;
    cin >> test.x >> test.y >> k;
    cout << classifyAPoint(arr, n, k, test) << endl;
  }
  return 0;
}

// } Driver Code Ends

/*
A utility structure to store the info of points
x and y represents the 2D coordinates of the points
grp represents to which particular point belongs
struct Point
{
        int grp;
        double x, y;
        double distance;
};
*/
// function should return to which grp
// the test data will belong
double distance(const Point &p1, const Point &p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int classifyAPoint(Point arr[], int n, int k, Point test) {
  // Code here
  for (int i = 0; i < n; i++) {
    arr[i].distance = distance(arr[i], test);
  }
  sort(arr, arr + n, [](const Point &p1, const Point &p2) {
    return p1.distance < p2.distance;
  });
  vector<int> cnt(n);
  for (int i = 0; i < k; i++) {
    cnt[arr[i].grp]++;
  }
  int ans = -1;
  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] > curr) {
      curr = cnt[i];
      ans = i;
    }
  }
  return ans;
}
