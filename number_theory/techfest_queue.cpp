//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  using ll = long long;
  vector<ll> prime;
  vector<ll> factorial;
  vector<ll> cnt;

  ll count(ll n) {
    ll ans = 0;
    for (int i = 0; i < prime.size(); ++i) {
      if (n < prime[i])
        break;
      while (n % prime[i] == 0) {
        ++ans;
        n /= prime[i];
      }
    }
    return ans > 1 ? ans + 1 : ans;
  }

  void sieve(ll a, ll b) {
    ll n = sqrt(b);
    vector<bool> is_prime(n + 2, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; ++i) {
      if (is_prime[i]) {
        prime.push_back(i);
        for (ll j = i * i; j <= n; j += i) {
          is_prime[j] = false;
        }
      }
    }

    factorial.assign(b - a + 1, 0);
    cnt.assign(b - a + 1, 0);
    for (ll i = a; i <= b; ++i) {
      factorial[i - a] = i;
    }
    for (auto p : prime) {
      for (ll j = (a + p - 1) / p * p; j <= b; j += p) {
        while (factorial[j - a] % p == 0) {
          cnt[j - a]++;
          factorial[j - a] /= p;
        }
      }
    }
    for (ll i = a; i <= b; ++i) {
      if (factorial[i - a] > 1)
        cnt[i - a]++;
    }
  }

public:
  long long int Sum(long long int n, long long int a, long long int b) {
    // Code here
    prime.clear();
    sieve(a, b);

    ll ans = 0;
    for (ll i = a; i <= b; ++i) {
      // cout << i << ' ' << cnt[i-a] << endl;
      ans += cnt[i - a];
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int n, a, b;
    cin >> n >> a >> b;
    Solution obj;
    long long int ans = obj.Sum(n, a, b);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
