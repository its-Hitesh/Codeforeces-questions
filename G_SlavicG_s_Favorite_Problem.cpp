#include <bits/stdc++.h>
#define ll            long long
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define mod           1000000007
#define int long long
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int>> adj[N];
set<int> s;
bool ok = true;
int n, a, b;
void dfs1(int u, int par, int x) {
    if(u == b) return;
    s.insert(x);
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        dfs1(v, u, x ^ w);
    }
}

bool dfs2(int u, int par, int x) {
    if(u != b && s.count(x)) return true;
    for(auto e: adj[u]) {
        int v = e.first, w = e.second;
        if(v == par) continue;
        if(dfs2(v, u, w ^ x)) return true;
    } 
    return false;
}

void solve() {
    s.clear();
    cin >> n >> a >> b; --a, --b;
    foo(i,0,n) adj[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs1(a, -1, 0);
    if(dfs2(b, -1, 0)) cout << "YES\n";
    else cout << "NO\n";
}   

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  */


  int t =1; cin>>t;

  while(t--){

    solve();

  }
  return 0;
}

