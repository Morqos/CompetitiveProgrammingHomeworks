#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 1e5 + 5;

/*
    Input:
2
bbabcbcab
abbaab

    Output:
7
4

-----------------

    bbabcbcab
    b abcb ab



*/

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int T;
    scanf("%d", &T);

    while(T--)
    {
        string s;
        cin >> s;
        int sSize = s.size();

        vector<vector<int>> dp(sSize, vector<int>(sSize));

        for(int i = 0; i < sSize; i++) dp[i][i] = 1;

        for(int tmpLength = 2; tmpLength <= sSize; tmpLength++)
        {
            for(int i = 0; i <= sSize - tmpLength; i++)
            {
                int j = i + tmpLength - 1;
                
                if(s[i] == s[j] && tmpLength == 2) dp[i][j] = 2;
                else if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        cout << dp[0][sSize - 1] << endl;

    }


    return 0;
}
