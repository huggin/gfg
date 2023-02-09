//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int t[3] = {0};
        reverse(S1.begin(), S1.end());
        reverse(S2.begin(), S2.end());
        reverse(S3.begin(), S3.end());
        t[0] = accumulate(S1.begin(), S1.end(), 0);
        t[1] = accumulate(S2.begin(), S2.end(), 0);
        t[2] = accumulate(S3.begin(), S3.end(), 0);

        while(t[0] != t[1] || t[0] != t[2]) {
            auto c = max_element(t, t+3);
            int i = c - t;
            if (i == 0) {
                t[0] -= S1[S1.size() -1];
                S1.pop_back();
            }
            if (i == 1) {
                t[1] -= S2[S2.size() -1];
                S2.pop_back();
            }
            if (i == 2) {
                t[2] -= S3[S3.size() -1];
                S3.pop_back();
            }
        }
        return t[0];
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
