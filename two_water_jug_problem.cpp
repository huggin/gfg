i//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
	public:
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    if (d > m && d > n) return -1;
	    int c = gcd(m, n);
	    //cout << c << endl;
	    if (d % c != 0) return -1;
	    if (m > n) swap(n, m);
	    int ans = 0;
	    int i = 0, j = 0;
	    while(true) {
	        ++ans;
	        i += m;
	        if (i == d) break;
	        if (n - j >= m) {
	            j += m;
	            i -= m;
	            ++ans;
	            if (j == d) break;
	        } else {
	            i -= n - j;
	            ++ans;
	            if (i == d) break;
	            ans += 2;
	            j = i;
	            i = 0;
	        }
	    }
	    
	    int ans2 = 0;
	    i = 0, j = 0;
	    while(true) {
	        if (j == 0) {
	            ++ans2;
	            j = n;
	        }
	        if (j == d) break;
	        if (j >= m - i) {
	            j -= (m - i);
	            i = m;
	            ++ans2;
	            if (j == d) break;
	            ++ans2;
	            i = 0;
	        } else {
	            i += j;
	            ++ans2;
	            j = 0;
	            if (i == d) break;
	        }
	    }
	    
	    return min(ans, ans2);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends
