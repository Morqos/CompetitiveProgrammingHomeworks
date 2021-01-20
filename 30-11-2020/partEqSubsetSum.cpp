// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum = 0;
        for(int i = 0; i < N; i++)
        {
            totalSum += arr[i];
        }
    
        if(totalSum % 2 != 0) return 0;
    
        int halfTotalSum = totalSum / 2;
    
        vector<bool> dp(totalSum + 1);
    
        dp[0] = true;
        for(int i = 0; i < N; i++)
        {
            for(int j = halfTotalSum; j >= 0; j--)
            {
                if(dp[j]) dp[j + arr[i]] = true;
            } 
        }
        
        return dp[halfTotalSum] ? 1 : 0;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
