//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int N, int M, string arr){
        // code here 
        int i = 0, j = 0;
        int ans = 0;
        while(i < N) {
            if (arr[i] == 'A') {
                ans = max(ans, i - j + 1);
            } else {
                if (--M >= 0) {
                    ans = max(ans, i - j + 1);
                } else {
                    while(j < N && arr[j] == 'A') ++j;
                    ++j;
                    ++M;
                    ans = max(ans, i - j + 1);
                }
            }
            ++i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
