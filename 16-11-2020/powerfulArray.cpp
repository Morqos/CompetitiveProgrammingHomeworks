#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max()/4;

const int maxN = 2e5 + 5;
const int maxA = 1e6 + 5;
vector<ll> ans(maxN);
vector<ll> freq(maxA);

struct str
{
    int left;
    int right;
    int order;
};

void updateTmpAns(ll &tmpAns, int num, int val)
{
    tmpAns -= (ll)(freq[num] * freq[num] * num);
    freq[num] += val;
    tmpAns += (ll)(freq[num] * freq[num] * num);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, t;
    scanf("%d %d", &n, &t);

    int sqN = sqrt(n);

    vector<int> seq(n + 1);
    for(int i = 1; i <= n; i++) scanf("%d", &seq[i]);


    vector<str> queries; int s = 0;
    while(t--)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        
        str st;
        st.left = left; st.right = right; st.order = s++;
        queries.push_back(st);
    }


    sort(queries.begin(), queries.end(), [&sqN](const str &l, const str &r)
    {
        if( int(l.left / sqN) == int(r.left / sqN) ) return l.right < r.right;
        return int(l.left / sqN) < int(r.left / sqN);
    });

    // for(str sp: queries) cout << "left: " << sp.left << ", right: " << sp.right << ", order: " << sp.order << endl;

    
    int left = queries[0].left;
    int right = queries[0].right;
    ll tmpAns = 0;
    
    for(int i = left; i <= right; i++) updateTmpAns(tmpAns, seq[i], 1);

    ans[queries[0].order] = tmpAns;


    int qSize = queries.size();    
    for(int i = 1; i < qSize; i++)
    {
        int newLeft = queries[i].left;
        int newRight = queries[i].right;
        
        if(newLeft > left)
        {
            for(int j = left; j < newLeft; j++) updateTmpAns(tmpAns, seq[j], -1);
        }
        else
        {
            for(int j = left - 1; j >= newLeft; j--) updateTmpAns(tmpAns, seq[j], 1);
        }


        if(newRight > right)
        {
            for(int j = right + 1; j <= newRight; j++) updateTmpAns(tmpAns, seq[j], 1);
        }
        else
        {
            for(int j = right; j > newRight; j--) updateTmpAns(tmpAns, seq[j], -1);
        }

        left = newLeft;
        right = newRight;

        ans[queries[i].order] = tmpAns;
    }

    for(int i = 0; i < s; i++)
    {
        printf("%I64d\n", ans[i]);
    }

    

    return 0;
}
