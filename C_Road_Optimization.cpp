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
int dp[501][501];
int fun(int n, int k, int prevs, int prevd,int d[], int speed[], int l){
    // cout<<n<<" "<<k<<" "<<dp[n][k]<<ed;
    if(d[n] == l) return prevs*(l-prevd);
    if(dp[n][k] != -1 ){
        return dp[n][k];
    } 
    int ans1 = fun(n+1,k, speed[n], d[n],d,speed,l) + prevs*(d[n] - prevd);
    if(k > 0) ans1 = min(ans1,fun(n+1, k-1, prevs, d[n],d,speed,l) + prevs*(d[n] - prevd));
    // cout<<dp[n][k]<<ed;
    dp[n][k] = ans1;
    foo(i,0,501) if(dp[n][i] != -1) dp[n][k] = min(dp[n][k],dp[n][i]);
    return dp[n][k];
    // cout<<n<<" "<<k<<" "<<dp[n][k]<<ed;
}
void solve(){
    int n,l,k; cin>>n>>l>>k;
    int d[n+1]; foo(i,0,n) cin>>d[i];
    d[n] = l;
    int speed[n];
    foo(i,0,501) foo(j,0,501) dp[i][j] = -1;
    foo(i,0,n) cin>>speed[i];
    int ans = fun(1,k,speed[0],d[0],d,speed,l);
    cout<<ans<<ed;
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