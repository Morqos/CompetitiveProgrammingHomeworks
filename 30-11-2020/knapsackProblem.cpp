#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 1e6 + 5;


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int S, N;
    scanf("%d %d", &S, &N);

    vector<pairIntInt> arr(N); // (size, value) of the item

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }

    vector<ll> dp(S + 1);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = S; j >= 0; j--)
        {
            if(j + arr[i].first <= S) dp[j + arr[i].first] = max(dp[j + arr[i].first], dp[j] + arr[i].second);
        }
    }

    ll storeMax = -1;
    for(int i = 0; i <= S; i++)
    {
        storeMax = max(storeMax, dp[i]);
    }

    cout << storeMax << endl;


    return 0;
}
