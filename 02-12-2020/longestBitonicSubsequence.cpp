
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
	public:
	int LongestBitonicSequence(vector<int> seq)
	{
	    // code here
	    int N = seq.size();
	    
	    vector<int> dpInc(N);

        for(int i = 0; i < N; i++)
        {
            dpInc[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(seq[i] > seq[j])
                {
                    dpInc[i] = max(dpInc[i], dpInc[j] + 1);
                }
            }
        }
    
        vector<int> dpDecr(N);

        for(int i = N - 1; i >= 0; i--)
        {
            dpDecr[i] = 1;
            for(int j = i + 1; j < N; j++)
            {
                if(seq[i] > seq[j])
                {
                    dpDecr[i] = max(dpDecr[i], dpDecr[j] + 1);
                }
            }
        }
        
        int maxL = 1;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(seq[i] != seq[j]) maxL = max(maxL, dpInc[i] + dpDecr[j]);
            }
        }
        
        return maxL;

	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
