//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;   
    queue<long long> Q, Q2;
    int i = 0;
    while(Q.size() < K) {
        if (A[i] < 0) {
            Q2.push(A[i]);
        }
        Q.push(A[i]);
        ++i;
    }
    for(; i<N+1;) {
        if (Q2.size() == 0) {
            ans.push_back(0);
        } else {
            ans.push_back(Q2.front());
        }
        if (i == N+1) break;
        if (Q2.size() != 0 && Q.front() == Q2.front()) {
            Q.pop();
            Q2.pop();
        } else {
            Q.pop();
        }
        if (A[i] < 0) {
            Q2.push(A[i]);
        }
        Q.push(A[i]);
        ++i;
    }  
    return ans;
}
