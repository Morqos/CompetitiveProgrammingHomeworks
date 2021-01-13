#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max()/4;

const int maxN = 1e6 + 5;
const int maxD = 1e9 + 1;

vector<pairIntInt> seq(maxN);

set<vector<int>> couples; // used for the O(n^2) solution

vector<ll> fenTreeMax(maxN);
vector<ll> fenTreeBiggest(maxN);


// void O_n3_solution()
// {
    // ll ans = 0;
    // for(int i = 0; i < n - 2; i++)
    // {
    //     for(int j = i + 1; j < n - 1; j++)
    //     {
    //         for(int k = j + 1; k < n; k++)
    //         {
    //             if(seq[i] < seq[j] && seq[j] < seq[k]) ans++;                
    //         }
    //     }
    // }

    // cout<<ans<<endl;
// }


// void O_n2_solution()
// {
    // for(int i = 0; i < n - 2; i++)
    // {
    //     for(int j = i + 1; j < n - 1; j++)
    //     {
    //         if(seq[i] < seq[j])
    //         {
    //             vector<int> vInd(4);
    //             vInd[0] = seq[i];
    //             vInd[1] = seq[j];
    //             vInd[2] = i;
    //             vInd[3] = j;
    //             couples.insert(vInd);
    //         }
    //     }
    // }
    
    // ll ans = 0;
    // for(vector<int> arr: couples)
    // {
    //     for(int i = arr[3] + 1; i < n; i++)
    //     {
    //         if(seq[i] > arr[1]) ans++;
    //     }
    // }

    // cout<<ans<<endl;
// }



// O( n * log(n) ) solution

void addInFenwickTree(vector<ll> &fenwickTree, int k, ll val, int n)
{
    while(k <= n)
    {
        fenwickTree[k] += val;
        k += k & -k;
    }
}

ll sumRangeFenwickTree(vector<ll> fenwickTree, int k, int n)
{
    ll sum = 0;
    while(k >= 1)
    {
        sum += fenwickTree[k];
        k -= k & -k;
    }
    return sum;
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);

    for(int i = n; i >= 1; i--)
    {
        scanf("%d", &seq[i].first);
        seq[i].second = i;
    }

    sort(seq.begin()+1, seq.begin()+1+n);

    ll ans = 0;
    for(int i = n; i >= 1; i--)
    {
        addInFenwickTree(fenTreeMax, seq[i].second, 1, n);
        
        ll resQuery = sumRangeFenwickTree(fenTreeMax, seq[i].second - 1, n);
        
        addInFenwickTree(fenTreeBiggest, seq[i].second, resQuery, n);

        ans += sumRangeFenwickTree(fenTreeBiggest, seq[i].second - 1, n);
    }

    printf("%I64d\n", ans);

    return 0;
}
