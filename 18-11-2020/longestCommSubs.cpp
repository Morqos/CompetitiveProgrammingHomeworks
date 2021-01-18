#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    int s1Size = s1.size();
    int s2Size = s2.size();
    
    vector<vector<int>> dp(s1Size + 1, vector<int>(s2Size + 1));
    
    for(int i = 1; i <= s1Size; i++)
    {
        for(int j = 1; j <= s2Size; j++)
        {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[s1Size][s2Size];
    
}
