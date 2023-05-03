//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long minNumber(long long arr[], long long N);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
      cin >> arr[i];
    cout << minNumber(arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends

bool prime(long long n) {
  if (n < 2)
    return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

long long minNumber(long long arr[], long long N) {
  long long n = accumulate(arr, arr + N, 0LL);
  for (int i = n;; ++i) {
    if (prime(i))
      return i - n;
  }
  return -1;
}
