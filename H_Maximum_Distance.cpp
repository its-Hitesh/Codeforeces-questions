#include <bits/stdc++.h>
#include <bits/extc++.h>//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long ;
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define m_p           make_pair
#define mod           998244353
#define int long long

// for fast hashing
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { // To use most bits rather than just the lowest ones:
    const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
    ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
//__gnu_pbds::gp_hash_table<ll, int, chash> ht({},{},{},{}, {1 << 16});

//oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
int parent[200001], rnk[200001];
vector<int> spec(200000,0), dp(200000,0);
int ans = 0,k;
void dfs(int n, int p, int wt, vector<vector<pair<int,int>>> & mst){
    dp[n] = spec[n];
    for(auto x : mst[n]){
        if(x.second != p){
            dfs(x.second, n, x.first, mst);
            dp[n] += dp[x.second];
        }
    }
    if(min(dp[n], k - dp[n]) > 0) ans = max(ans, wt);
}
void build(int n){
    foo(i,0,n+1){
        parent[i] = i;
        rnk[i] = 1;
    }
}
int find_set(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}
void merge(int x, int y){
    int lx = find_set(x);
    int ly = find_set(y);
    if(rnk[x] > rnk[y]){
        swap(lx, ly);
    }
    parent[ly] = lx;
    rnk[lx] += rnk[ly]; 
}
void solve(){
    int n,m ; cin>>n>>m>>k;
    int a[k]; foo(i,0,k) cin>>a[i], spec[a[i] - 1] = 1;
    vector<pair<pair<int,int>,int>> grp;
    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        x--; y--;
        grp.pb({{w,x},y});
    }
    build(n+1);
    sort(grp.begin(),grp.end());
    vector<vector<pair<int,int>>> mst(n);
    for(auto x : grp){
    // cout<<x.first.second<<" "<<x.second<<" "<<find_set(x.first.second)<<ed;

        int p = find_set(x.first.second);
        int q = find_set(x.second);
        if(p == q) continue;
        merge(p,q);
        mst[p].pb({x.first.first,q});
        mst[q].pb({x.first.first,p});
    }
    // foo(i,0,n){
    //     for(auto x : mst[i]){
    //         cout<<i<<" "<<x.second<<" "<<x.first<<ed;
    //     }
    // }
    dfs(0, -1, 0, mst);

    foo(i,0,k) cout<<ans<<" ";
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}