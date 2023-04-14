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

void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int,pair<int,int>>> grp(m);
    foo(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        grp[i] = {u,{v,-1*w}};
    }
    int dp[n+1];
    foo(i,0,n+1) dp[i] = 1e18;
    dp[1] = 0 ;
    foo(i,0,n-1){
        for(auto e : grp){
            int u=e.first;
            int v=e.second.first;
            int w=e.second.second;
            if(dp[u] == 1e18) continue;
            if(dp[u]+w < dp[v])
            { // relaxation
                dp[v] = dp[u] + w;
            // cout<<u<<" "<<v<<" "<<dp[v]<<ed;
            }
        }
    }
    // foo(i,0,n+1) cout<<dp[i]<< " ";
    // cout<<ed;
    foo(i,0,n-1){
        for(auto e : grp){
            int u=e.first;
            int v=e.second.first;
            if(dp[u] == 1e18) continue;
            int w=e.second.second;
            if(dp[u]+w < dp[v])
            { // relaxation
                dp[v] = -1e18 ;
            // cout<<u<<" "<<v<<" "<<dp[v]<<ed;
            }
        }
    }
    // foo(i,0,n+1) cout<<dp[i]<< " ";
    cout<<ed;
    if(dp[n] == 1e18 || dp[n] == -1e18) cout<<-1<<ed;
    else cout<<-1*dp[n]<<ed;
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