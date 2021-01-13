#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max()/4;

const int maxN = 1e6 + 5;
const int maxD = 1e9 + 1;

vector<int> fenTree(maxN);

void addInFenwickTree(int k, int val, int n)
{
    while(k >= 1)
    {
        fenTree[k] += val;
        k -= k & -k;
    }
}

int sumRangeFenwickTree(int k, int n)
{
    int sum = 0;
    while(k <= n)
    {
        sum += fenTree[k];
        k += k & -k;
    }
    return sum;
}

struct str
{
    int val;
    int type; // type == 1 -> in array; type == 0 -> in query
    int index;
    int order;
    int left;
    int right;
};


// O ( (n + m) * log(n + m) ) solution

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);

    vector<str> arr;

    for(int i = 1; i <= n; i++)
    {
        str p;
        scanf("%d", &p.val);
        p.type = 1; p.index = i; p.order = -1; p.left = -1; p.right = -1;
        
        arr.push_back(p);
    }


    int s = 0;
    while(m--)
    {
        int i, j, X;
        scanf("%d %d %d", &i, &j, &X);

        str p;
        p.val = X; p.type = 0; p.index = -1; p.order = s++; p.left = i + 1; p.right = j + 1;

        arr.push_back(p); 
    }


    sort(arr.begin(), arr.end(), [](const str &lhs, const str &rhs)
    {
        if(lhs.val == rhs.val)
        {
            if(lhs.type == rhs.type) return lhs.order < rhs.order;
            else return lhs.type > rhs.type;
        }
        else return lhs.val < rhs.val;
    });


    // for(auto v: arr) cout << "val: "<< v.val << ", type: "<< v.type << ", index: "<< v.index << endl;

    vector<pairIntInt> answer;
    int arrSize = arr.size();
    for(int i = 0; i < arrSize; ++i)
    {
        if(arr[i].type == 1) addInFenwickTree(arr[i].index, 1, n);
        else
        {
            int ans = sumRangeFenwickTree(arr[i].left, n);
            int ans2 = sumRangeFenwickTree(arr[i].right + 1, n);

            pairIntInt p = make_pair(arr[i].order, ans - ans2);
            answer.push_back(p);
        }
    }

    sort(answer.begin(), answer.end());

    for(pairIntInt p: answer) printf("%d\n", p.second);


    return 0;
}
