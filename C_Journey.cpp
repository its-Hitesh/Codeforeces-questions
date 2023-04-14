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
vector<ld> dis(1000001,0);
vector<int> grp[100005];
int vis[100005];
const int mode=1e18;
vector<double> ans;
void dfs(int node)
{
    vis[node]=1;
    ld no_child=0;
    ld length_child=0;
    for(auto it:grp[node])
    {
        if(!vis[it])
        {
        dfs(it);
        no_child++;
        length_child+=dis[it];
        }
    }
    if(no_child==0)
    {
        dis[node]=0;
        return;
    }
    ld vr = length_child / no_child;
    dis[node] = vr + (ld)1;
}
void solve(){
    int n;
    cin>>n;
    foo(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        grp[u].pb(v);
        grp[v].pb(u);
    }
    dfs(1);
    cout<<setprecision(8)<<dis[1]<<ed;
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