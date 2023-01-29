//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int left = 0, right = n - 1;
        int i = left + 1, j = right - 1;
        while(i < n) {
            if (arr[i] < arr[i-1]) {
                left = i - 1;
                break;
            } else {
                ++i;
            }
        }
        while(j >= 0) {
            if (arr[j] < arr[j+1]) {
                right = j + 1;
                break;
            } else {
                --j;
            }
        }
        if (left >= right) return 0;
        i = left, j = right;
        long long ans = 0;
        while (i < j) {
            if (arr[left] <= arr[right]) {
                ++i;
                if (arr[i] < arr[left]) {
                    ans += arr[left] - arr[i];
                } else {
                    left = i;
                }
            } else {
                --j;
                if (arr[j] < arr[right]) {
                    ans += arr[right] - arr[j];
                } else {
                    right = j;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
