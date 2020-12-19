#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
 
const int MOD=1e9+7;
const int INF=1e9+7;

const int maxN = 1000 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    scanf("%d", &N);

    vector<int> wBars(N);
    for(int &v: wBars) scanf("%d", &v);

    vector<int> sup(maxN);
    int maxV = -1;
    for(int i = 0; i < N; i++)
    {
        sup[wBars[i]]++;
        maxV = max(maxV, sup[wBars[i]]);
    }

    int sum = 0;
    for(int i = 0; i < maxN; i++)
    {
        if(sup[i] != 0) sum++;
    }

    printf("%d %d\n", maxV, sum);
    
    return 0;
}
