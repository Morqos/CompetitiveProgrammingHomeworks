#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends


int maxMeetings(int S[], int end[], int N) {
    // Your code here
    
    vector<pair<int, int>> F(N);
    
    for(int i = 0; i < N; i++)
    {
        F[i].first = end[i];
        F[i].second = i;
    }
    
    sort(F.begin(), F.end());

    int ans = 1;
    int prevIndex = 0;
    for(int i = 1; i < N; i++)
    {
        if(S[F[i].second] > F[prevIndex].first)
        {
            prevIndex = i;
            ans++;
        }
    }
    
    return ans;
}
