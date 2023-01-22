//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    
    bool validate(const vector<int>& a, int K, int v) {
        if (v == 1) return true;
        int k = 0;
        int t = 0;
        for(int i = 0; i < a.size(); ++i) {
            t += a[i];
            if (t % v == 0) {
                ++k;
                t = 0;
            } 
        }
        if (k >= K) return true;
        return false;
    }
    
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> factor;
        for(int i=2; i<=sqrt(sum); ++i) {
            if (sum % i == 0) {
                factor.push_back(i);
                factor.push_back(sum / i);
            }
        }
        factor.push_back(sum);
        int ans = 1;
        for(auto c : factor) {
            //cout << c << endl;
            if (validate(arr, K, c)) {
                ans = max(ans, c);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
