#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max()/4;

const int maxN = 1e5 + 5;
const int maxM = 1e5 + 5;

vector<int> adj[maxN];
vector<int> child[maxN];

vector<int> color(maxN);

vector<pairIntInt> queries[maxM];
int sizeVector[maxN];

int freq[maxN];
int fenTree[maxN];
int ans[maxM];


void printChild()
{
    for(int i = 1; i < maxN; i++)
    {
        if(child[i].size() != 0)
        {
            cout << "vertex: " << i << ", children: \n";
            for(int node: child[i])
                cout << node << " ";
            cout << "\n"; 
        }
    }

}


// For each vertex stores the size (#nodes) of the subtree and creates tree "child"
void getSize(int prev, int curr)
{
    sizeVector[curr] = 1;
    for(int node: adj[curr])
    {
        if(node != prev)
        {
            child[curr].push_back(node);
            getSize(curr, node);
            sizeVector[curr] += sizeVector[node];
        }
    }
}




int sumQuery(int pos)
{
    int ans = 0;
    for(int i = pos; i >= 1; i = ((i) & (i - 1))) ans += fenTree[i - 1];
    return ans;
}




void addQuery(int pos, int val)
{
    if(pos < 0) return;
    for(int i = pos; i < maxN; i = ((i) | (i + 1))) fenTree[i] += val;
}

void updateQuery(int typeColor, int d)
{
    addQuery(freq[typeColor], -1);
    freq[typeColor] += d;
    addQuery(freq[typeColor], 1);
}



void clearAll(int curr)
{
    updateQuery(color[curr], -1);
    for(int node: child[curr]) clearAll(node);
}

void addAll(int curr)
{
    updateQuery(color[curr], 1);
    for(int node: child[curr]) addAll(node);
}




// I need to keep track of the node with the biggest size. Without doing so still works but gets TLE in huge test cases
void dfs(int curr)
{
    int biggestSize = -1;
    int nodeBiggestSize = -1;
    for(int node: child[curr])
    {
        if(sizeVector[node] > biggestSize)
        {
            biggestSize = sizeVector[node];
            nodeBiggestSize = node;
        }
    }

    for(int node: child[curr])
    {
        if(node != nodeBiggestSize)
        {
            dfs(node);
            clearAll(node); // Clears every subtree
        }
    }

    if(nodeBiggestSize != -1) dfs(nodeBiggestSize);

    for(int node: child[curr])
    {
        if(node != nodeBiggestSize) addAll(node); // Adds every subtree
    }

    // Adds itself
    updateQuery(color[curr], 1);


    for(pairIntInt q: queries[curr])
    {
        int minCount = q.first;
        int qId = q.second;
        ans[qId] = -sumQuery(minCount);
    }

}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);

    
    for(int i = 1; i <= n; i++) scanf("%d", &color[i]);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    int cntQuery = 0;
    while(m--)
    {
        int v, k;
        scanf("%d %d", &v, &k);
        queries[v].push_back(make_pair(k, cntQuery++));
    }
    
    getSize(-1, 1);
    
    // printChild();

    dfs(1);

    for(int i = 0; i < cntQuery; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
