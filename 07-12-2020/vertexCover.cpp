#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 1e5 + 5;

vector<int> adj[maxN];

int dp[maxN][2];

void dfs(int curr, int prev)
{
    vector<int> prefSum, sufSum;
    dp[curr][0] = dp[curr][1] = 0;

    bool leaf = true;
    for(int child: adj[curr])
    {
        if(child != prev)
        {
            leaf = false;
            dfs(child, curr);
        }
    }

    if(leaf) return;

    for(int child: adj[curr])
    {
        if(child != prev)
        {
            prefSum.push_back(max(dp[child][0], dp[child][1]));
            sufSum.push_back(max(dp[child][0], dp[child][1]));
        }
    }

    for(int i = 1; i < (int) prefSum.size(); i++) prefSum[i] += prefSum[i - 1];

    for(int i = sufSum.size() - 2; i >= 0; i--) sufSum[i] += sufSum[i + 1];

    dp[curr][0] = sufSum[0];
    int cNo = 0;
    
    for(int child: adj[curr])
    {
        if(child == prev) continue;

        int leftChild = (cNo == 0) ? 0 : prefSum[cNo - 1];
        int rightChild = (cNo == (int) sufSum.size() - 1) ? 0 : sufSum[cNo + 1];

        dp[curr][1] = max(dp[curr][1], 1 + leftChild + rightChild + dp[child][0]);
        cNo++;
    }
    


}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    printf("%d\n", max(dp[1][0], dp[1][1]));


    return 0;
}
