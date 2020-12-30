#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 2e5 + 1;
const int maxD = 1e9 + 1;
 
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    string s;
    cin >> s;

    int sSize = s.length();

    // dp[i] - How many i such that s_i = s_i+1 from s[0] to s[i]
    //      dp[] is a slightly different version of the prefixSum array
    vector<int> dp(sSize);
    for(int i = 0; i < sSize - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            if(i != 0) dp[i] = dp[i-1] + 1;
            else dp[i] = 1;
        }
        else
        {
            if(i != 0) dp[i] = dp[i-1];
            else dp[i] = 0;
        }
    }

    int m = 0;
    scanf("%d", &m);

    while(m--)
    {
        int l, r;
        scanf("%d %d", &l,&r);

        int left = l == 1 ? 0 : dp[l-2];
        int right = dp[r - 2];         


        printf("%d\n", (right - left));
    }
   
    return 0;
}
